%{
	#include <stdio.h>
	#include "symboltable.h"
	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	#include "stack.h"

	struct scope *global, *current_scope;
	int curr_line = 1;
	int temp = 1;

	void yyerror(const char* error);
	char* newTemp();
	int error(int type, int spec, char *id);
	int yylex();
	char* newLabel(char*);
	int label_count = 1;
	int temp_count = 1;
	char next_label[100];
	char temp_string[100];
	
	stack breakpoint, looppoint;
	int inloop = 0;
%}


%code requires{
	struct datatype
	{
		int val_type;
		float numval;
		char sval[64];
		char idval[64];
		char* temp;
		char* next;
		char code[500];
		char* true;
		char* false;
		char* my;	//my label
		char* loop;
		char* start;
		char* end;
		char which;
	};
}


%union
{
	struct datatype data;
};

%left T_OR 
%left T_AND

%error-verbose
%token T_BOOLEAN
%token T_INTEGER
%token T_IDENTIFIER
%token T_STRING
%token T_FLOAT
%token T_AND
%token T_FROM
%token T_NOT
%token T_WHILE
%token T_OR
%token T_WITH
%token T_ELSE
%token T_IF
%token T_BREAK
%token T_IN
%token T_CONTINUE
%token T_RETURN
%token T_DEF
%token T_FOR
%token T_IMPORT
%token T_AS
%token T_PRINT
%token T_PLUS
%token T_MINUS
%token T_POWER
%token T_STAR
%token T_DIVIDE
%token T_MOD
%token T_OPENP
%token T_CLOSEP
%token T_OPENS
%token T_CLOSES
%token T_EQUAL
%token T_COMMA
%token T_INDENT
%token T_LESSER
%token T_GREATER
%token T_NO
%token T_NEWLINE
%token T_COLON
%token T_RANGE
%token T_DEDENT
%token T_EOF
%token T_SEMICOLON

%%
P: 							{$<data.next>$ = newLabel("\nnext:\n");}
							all_stmt 
							T_EOF 
							{printf("ICG:\n");printf("\n.begin:");$<data.next>2 = $<data.next>1;sprintf($<data.code>$,"%s%s",$<data.code>2,$<data.next>1);printf("%s\n",$<data.code>$);YYACCEPT;}

literal:					T_INTEGER	
							{$<data.val_type>$ = int_type; $<data.numval>$ = $<data.numval>1; $<data.temp>$ = (char*)malloc(sizeof(char)*10);sprintf($<data.temp>$, "%d", (int)$<data.numval>1); strcpy($<data.code>$, "");}
						|	T_FLOAT		
							{$<data.val_type>$ = float_type; $<data.numval>$ = $<data.numval>1;$<data.temp>$ = (char*)malloc(sizeof(char)*10);sprintf($<data.temp>$, "%f", (float)$<data.numval>1); strcpy($<data.code>$, "");}
						|	T_STRING	
							{$<data.val_type>$ = string_type; strcpy($<data.sval>$,$<data.sval>1);  $<data.temp>$ = (char*)malloc(sizeof(char)*10);sprintf($<data.temp>$, "%s", $<data.sval>1); strcpy($<data.code>$, "");}
						|	T_BOOLEAN	
							{$<data.val_type>$ = bool_type; $<data.numval>$ = $<data.numval>1; $<data.temp>$ = (char*)malloc(sizeof(char)*10);sprintf($<data.temp>$, "%d", (int)$<data.numval>1); strcpy($<data.code>$, "");}
						|	list_stmt	
							{$<data.val_type>$ = list_type; strcpy($<data.sval>$,$<data.sval>1);  $<data.temp>$ = (char*)malloc(sizeof(char)*10);sprintf($<data.temp>$, "%s", $<data.sval>1); strcpy($<data.code>$, "");}	

indexes:					T_OPENS 
							T_INTEGER 
							T_CLOSES 
							indexes 
							{sprintf($<data.sval>$,"%d %s", (int)$<data.numval>2, $<data.sval>4);}
						|	{strcpy($<data.sval>$, "");};					

all_stmt:					simple_stmt 
							line 
							all_stmt
							{strcpy($<data.code>$, $<data.code>1); sprintf($<data.code>$, "%s%s", $<data.code>$, $<data.code>3);}

						|	{$<data.my>$ = newLabel("label");$<data.loop>$ = newLabel("label"); inloop++; 
							push(&looppoint, $<data.my>$);}
							compound_stmt  
							line 
							suite
							{inloop--; pop(&looppoint); pop(&breakpoint);}
							all_stmt

							{if($<data.which>2=='w'){sprintf($<data.code>$, "\n%s:%s\n%s:%s\ngoto %s\n%s:%s", $<data.my>1,  $<data.code>2, $<data.loop>1, $<data.code>4, $<data.my>1, $<data.next>2, $<data.code>6);} 
							
							else if($<data.which>2 == 'f'){sprintf($<data.code>$, "\n%s = %f\n%s:\n%s = %s + 1%s%s\ngoto %s\n%s:%s", $<data.idval>2, $<data.numval>2-1, $<data.my>1, $<data.idval>2,$<data.idval>2, $<data.code>2, $<data.code>4, $<data.my>1, $<data.next>2,$<data.code>6);};}

						|	
							{strcpy($<data.code>$, "");}
							;

compound_stmt:  			while_stmt
							{$<data.next>$ = $<data.next>1;}
						|	for_stmt
							{$<data.next>$ = $<data.next>1; $<data.numval>$ = $<data.numval>1; strcpy($<data.idval>$,$<data.idval>1);}

suite:						indent 
							all_stmt 
							dedent
							{sprintf($<data.code>$, "%s", $<data.code>2);}
						|	line 
							suite
							{sprintf($<data.code>$, "%s", $<data.code>2);}

line:						T_NEWLINE 	
							{curr_line++;}

indent:						T_INDENT	
							{current_scope = create_scope(current_scope);}

dedent:						T_DEDENT	
							{current_scope = exit_scope(current_scope);}


simple_stmt:				print_stmt
							{strcpy($<data.code>$, $<data.code>1); }
						|	assignment_stmt
							{strcpy($<data.code>$, $<data.code>1); }
						|	break_stmt
						|	continue_stmt
						|	import_stmt
						|	aug_assignment_stmt
							{strcpy($<data.code>$, $<data.code>1); }
						|	;

print_stmt: 				T_PRINT 
							T_OPENP 
							print_list 
							T_CLOSEP
							{sprintf($<data.code>$, "%s", $<data.code>3);}

print_list:					expression_stmt 
							T_COMMA 
							print_list 
							{sprintf($<data.code>$,"\nprint %s%s",$<data.temp>1,$<data.code>3);}
						|	expression_stmt
							{sprintf($<data.code>$,"%s\nprint %s",$<data.code>1,$<data.temp>1);}

assignment_stmt:			T_IDENTIFIER 
							indexes
							T_EQUAL 
							expression_stmt 
							{if(strlen($<data.sval>2)==0){if($<data.val_type>4==string_type || $<data.val_type>4==list_type){add_variable(current_scope, $<data.idval>1, $<data.val_type>4, curr_line, (void*)(($<data.sval>4))); } else{add_variable(current_scope, $<data.idval>1, $<data.val_type>4, curr_line, (void*)(&($<data.numval>4)));} sprintf($<data.code>$, "%s\n%s = %s",$<data.code>4, $<data.idval>1, $<data.temp>4);} else{struct datatype *temp=lookup(current_scope,$<data.idval>1, $<data.sval>2); if(temp==NULL){error(6,0,$<data.idval>1);} if(temp!=NULL){if(temp->val_type<0){error(temp->val_type+11,0, $<data.idval>1);}} int s = listSize(lookup(current_scope,$<data.idval>1, ""), $<data.sval>2); $<data.temp>$ = newTemp(); $<data.temp>2 = newTemp(); sprintf($<data.code>$, "\n%s = %d*4\n%s = %s[%s]\n%s = %s", $<data.temp>2, s, $<data.temp>$, $<data.idval>1, $<data.temp>2, $<data.temp>$, $<data.temp>4);}}


list_stmt:					T_OPENS 
							item 
							T_CLOSES 	
							{sprintf($<data.sval>$, "[%s]", $<data.sval>2); $<data.val_type>$=list_type;}
						|   T_OPENS 
							T_CLOSES 		
							{sprintf($<data.sval>$, "[]"); $<data.val_type>$=list_type;}

item:						list_literal 
							T_COMMA 
							item 	
							{sprintf($<data.sval>$, "%s %s", $<data.sval>1, $<data.sval>3);}
						|   list_literal	
							{sprintf($<data.sval>$, "%s", $<data.sval>1);}

list_literal:				T_INTEGER	
							{sprintf($<data.sval>$, "%d", (int)$<data.numval>1);}
						|	T_FLOAT		
							{sprintf($<data.sval>$, "%f", (float)$<data.numval>1);}
						|	list_stmt	
							{sprintf($<data.sval>$, "%s", $<data.sval>1);}

break_stmt:					T_BREAK
							{if(inloop==0) error(11, 0, 0); sprintf($<data.code>$, "\ngoto %s", top(&breakpoint));}

continue_stmt:				T_CONTINUE
							{if(inloop==0) error(12, 0, 0); sprintf($<data.code>$, "\ngoto %s", top(&looppoint));}

import_stmt:				T_IMPORT 
							import_list

import_list:				T_IDENTIFIER 
							T_COMMA 
							import_list
						|	T_IDENTIFIER

aug_assignment_stmt:		T_IDENTIFIER 
							arith_operator 
							T_EQUAL 
							expression_stmt
							{$<data.temp>$ = newTemp(); sprintf($<data.code>$, "\n%s = %s %s %s\n%s = %s", $<data.temp>$, $<data.idval>1, $<data.code>2, $<data.temp>4, $<data.idval>1, $<data.temp>$);}

arith_operator:				T_PLUS	
							{sprintf($<data.code>$, "+");}
						|	T_MINUS
							{sprintf($<data.code>$, "-");}
						|	T_STAR
							{sprintf($<data.code>$, "*");}
						|	T_POWER
							{sprintf($<data.code>$, "**");}
						|	T_DIVIDE
							{sprintf($<data.code>$, "/");}
						|	T_MOD
							{sprintf($<data.code>$, "mod");}

condition:					condition
							T_OR
							{$<data.next>$ = newLabel("label"); $<data.true>$ = $<data.true>0; $<data.false>$ = $<data.next>$;}
							condition_and
							{$<data.next>$ = $<data.next>3;sprintf($<data.code>$, "%s\n%s:%s", $<data.code>1, $<data.next>1, $<data.code>4);}
						|	{$<data.next>$ = newLabel("label"); $<data.true>$ = $<data.true>0; $<data.false>$ = 
							$<data.next>$;}
							condition_and
							{$<data.next>$ = $<data.next>1;sprintf($<data.code>$, "%s", $<data.code>2);}

condition_and:				expression_stmt 
							comp_operator 
							expression_stmt
							T_AND
							{$<data.temp>$ = newTemp(); $<data.true>$ = $<data.true>0; $<data.false>$ = $<data.false>0;$<data.next>$ = $<data.next>0;}
							condition_and
							{sprintf($<data.code>$, "\n%s = %s %s %s\niffalse %s goto %s%s", $<data.temp>5, $<data.temp>1, $<data.code>2, $<data.temp>3, $<data.temp>5, $<data.false>0, $<data.code>6);}
						|	expression_stmt 
							comp_operator 
							expression_stmt
							{$<data.temp>$ = newTemp();sprintf($<data.code>$, "\n%s = %s %s %s\nif %s goto %s\ngoto %s", $<data.temp>$, $<data.temp>1, $<data.code>2, $<data.temp>3, $<data.temp>$, $<data.true>0, $<data.next>0);}

comp_operator:            	T_LESSER
							{sprintf($<data.code>$, "<");}
			            |	T_GREATER
			            	{sprintf($<data.code>$, ">");}
			            |	T_EQUAL T_EQUAL
			            	{sprintf($<data.code>$, "==");}
			            |	T_GREATER T_EQUAL
			            	{sprintf($<data.code>$, ">=");}
			            |	T_LESSER T_EQUAL
			            	{sprintf($<data.code>$, "<=");}
			            |	T_NO T_EQUAL
			            	{sprintf($<data.code>$, "!=");}

expression_stmt:			expression_stmt 
							T_PLUS 
							term 
							{int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(8, flag, NULL); switch(flag){case 22: strcpy($<data.sval>$, strcat($<data.sval>1, $<data.sval>3)); $<data.val_type>$ = string_type; break; case 20: case 21: case 23: case 2: case 12: case 32: error(8, flag, NULL); break; default: $<data.numval>$ = $<data.numval>1+$<data.numval>3; if(flag==0 || flag==30 || flag==3 || flag==33) $<data.val_type>$ = int_type; else $<data.val_type>$ = float_type;}$<data.temp>$ = newTemp(); sprintf($<data.code>$, "%s%s\n%s = %s + %s", $<data.code>1, $<data.code>3, $<data.temp>$, $<data.temp>1, $<data.temp>3);}	
						
						|	expression_stmt 
							T_MINUS 
							term 
							{int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(7, flag, NULL); switch(flag){case 20: case 21: case 22: case 23: case 2: case 12: case 32: error(7, flag, NULL); break; default: $<data.numval>$ = $<data.numval>1-$<data.numval>3; if(flag==0 || flag==30 || flag==3 || flag==33) $<data.val_type>$ = int_type; else $<data.val_type>$ = float_type;}$<data.temp>$ = newTemp(); sprintf($<data.code>$, "%s%s\n%s = %s - %s", $<data.code>1, $<data.code>3, $<data.temp>$, $<data.temp>1, $<data.temp>3);}
						
						|	term 	
							{$<data.val_type>$ = $<data.val_type>1; switch($<data.val_type>$){ case int_type: case float_type: case bool_type: $<data.numval>$ = $<data.numval>1; break; case string_type: strcpy($<data.sval>$, $<data.sval>1); break;}strcpy($<data.code>$,$<data.code>1); $<data.temp>$ = (char*)malloc(sizeof(char)*10); $<data.temp>$ = (char*)malloc(sizeof(char)*10); sprintf($<data.temp>$,"%s",$<data.temp>1);}	


term:						term 
							T_STAR 
							factor 	
							{int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(5, flag, NULL); switch(flag){case 12: case 21: case 22: error(5, flag, NULL); break; case 20: case 23: case 2: case 32:  error(5, flag, NULL);break; default: $<data.numval>$ = $<data.numval>1*$<data.numval>3; if(flag==0 || flag==30 || flag==3) $<data.val_type>$ = int_type; else $<data.val_type>$ = float_type;} $<data.temp>$ = newTemp(); sprintf($<data.code>$, "%s%s\n%s = %s * %s", $<data.code>1,$<data.code>3, $<data.temp>$, $<data.temp>1, $<data.temp>3);}
						
						|	term 
							T_DIVIDE 
							factor	
							{int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(4, flag, NULL); switch(flag){case 20: case 21: case 22: case 23: case 2: case 12: case 32:  error(4, flag, NULL); break; default: if($<data.numval>3==0) error(3, 0, NULL); $<data.numval>$ = $<data.numval>1/$<data.numval>3; $<data.val_type>$ = float_type;} $<data.temp>$ = newTemp(); sprintf($<data.code>$, "%s%s\n%s = %s / %s", $<data.code>1, $<data.code>3, $<data.temp>$, $<data.temp>1, $<data.temp>3);}
						
						|	term 
							T_MOD 
							factor 	
							{int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(2, flag, NULL); switch(flag){case 20: case 21: case 22: case 23: case 2: case 12: case 32: case 1: case 10: case 11: case 13: case 31: error(2, flag, NULL); break; default: if($<data.numval>3==0) error(2, 0, NULL); $<data.numval>$ = (int)$<data.numval>1%(int)$<data.numval>3; $<data.val_type>$ = int_type;} $<data.temp>$ = newTemp(); sprintf($<data.code>$, "%s%s\n%s = %s mod %s", $<data.code>1, $<data.code>3, $<data.temp>$, $<data.temp>1, $<data.temp>3);}	
						
						|	factor 	
							{$<data.val_type>$ = $<data.val_type>1; switch($<data.val_type>$){ case int_type: case float_type: case bool_type: $<data.numval>$ = $<data.numval>1; break; case string_type: strcpy($<data.sval>$, $<data.sval>1); break;} strcpy($<data.code>$,$<data.code>1); $<data.temp>$ = (char*)malloc(sizeof(char)*10); sprintf($<data.temp>$,"%s",$<data.temp>1);}


factor:						power 
							T_POWER 
							factor 	
							{int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(1, flag, NULL); switch(flag){case 20: case 21: case 22: case 23: case 2: case 12: case 32: error(1, flag, NULL); break; default: $<data.numval>$ = pow($<data.numval>1, $<data.numval>3); if(flag==0 || flag==30 || flag==3 || flag==33) $<data.val_type>$ = int_type; else $<data.val_type>$ = float_type;} $<data.temp>$ = newTemp(); sprintf($<data.code>$, "%s%s\n%s = %s ** %s", $<data.code>1, $<data.code>3, $<data.temp>$, $<data.temp>1, $<data.temp>3);}	
						
						|	power 	
							{$<data.val_type>$ = $<data.val_type>1; switch($<data.val_type>$){ case int_type: case float_type: case bool_type: $<data.numval>$ = $<data.numval>1; break; case string_type: strcpy($<data.sval>$, $<data.sval>1); break;} strcpy($<data.code>$, $<data.code>1); $<data.temp>$ = (char*)malloc(sizeof(char)*10); sprintf($<data.temp>$,"%s",$<data.temp>1);}

power:						T_OPENP 
							expression_stmt 
							T_CLOSEP 	
							{$<data.val_type>$ = $<data.val_type>2; switch($<data.val_type>$){ case int_type: case float_type: case bool_type: $<data.numval>$ = $<data.numval>2; break; case string_type: strcpy($<data.sval>$, $<data.sval>2); break;} strcpy($<data.code>$, $<data.code>2); $<data.temp>$ = (char*)malloc(sizeof(char)*10); sprintf($<data.temp>$,"%s",$<data.temp>2);}
						
						|	literal 	
							{ $<data.val_type>$ = $<data.val_type>1; switch($<data.val_type>$){ case int_type: case float_type: case bool_type: $<data.numval>$ = $<data.numval>1; break; case string_type: strcpy($<data.sval>$, $<data.sval>1); break;} strcpy($<data.code>$, $<data.code>1);}	
						
						|	T_IDENTIFIER 
							indexes 
							{ struct datatype *temp=lookup(current_scope,$<data.idval>1, $<data.sval>2); if(temp!=NULL){if(temp->val_type<0){error(temp->val_type+11,0, $<data.idval>1);}$<data.val_type>$=temp->val_type; if(temp->val_type==int_type|| temp->val_type==float_type || temp->val_type==bool_type)$<data.numval>$=temp->numval; else {strcpy($<data.sval>$, temp->sval);}} else{ error(6,0,$<data.idval>1); } if(strcmp($<data.sval>2, "")==0){$<data.temp>$ = (char*)malloc(sizeof(char)*10);sprintf($<data.temp>$, "%s", $<data.idval>1); strcpy($<data.code>$, "");} else {int s = listSize(lookup(current_scope,$<data.idval>1, ""), $<data.sval>2); $<data.temp>$ = newTemp(); $<data.temp>2 = newTemp(); sprintf($<data.code>$, "\n%s = %d*4\n%s = %s[%s]", $<data.temp>2, s, $<data.temp>$, $<data.idval>1, $<data.temp>2);}} 
 
while_stmt:					T_WHILE
							{$<data.true>$ = $<data.loop>0; $<data.false>$ = $<data.next>0; $<data.next>$ = $<data.next>0; $<data.loop>$ = $<data.loop>0;} 
							condition 
							T_COLON
							{$<data.next>$ = $<data.next>3;strcpy($<data.code>$, $<data.code>3); 
							push(&breakpoint, $<data.next>3); $<data.which>$ = 'w';} 


for_stmt:					T_FOR 
							T_IDENTIFIER 
							T_IN
							{$<data.loop>$ = $<data.loop>0;}
							range_stmt
							T_COLON 
							{add_variable(current_scope, $<data.idval>2, int_type, curr_line, (void*)(&temp));$<data.numval>2 = $<data.numval>4; sprintf($<data.code>$, "\n%s" ,$<data.code>5);$<data.next>$ = $<data.false>5; $<data.numval>$ = $<data.numval>5; strcpy($<data.idval>$,$<data.idval>5); $<data.which>$ = 'f';}

range_stmt:					T_RANGE 
							T_OPENP 
							T_INTEGER 
							T_COMMA 
							T_INTEGER 
							T_CLOSEP
							{$<data.start>$ = newTemp(); $<data.end>$ = newTemp(); $<data.temp>$ = newTemp(); $<data.false>$ = newLabel("label"); ;sprintf($<data.code>$, "%s = %s >= %f\nifFalse %s goto %s\n%s = %s < %f\nifFalse %s goto %s",
							$<data.start>$,$<data.idval>$,$<data.numval>3,$<data.start>$,$<data.false>$,$<data.end>$,$<data.idval>$,$<data.numval>5,$<data.end>$,$<data.false>$);$<data.numval>$ = $<data.numval>3; strcpy($<data.idval>$,$<data.idval>5);}



%%

int error(int type, int spec, char* id)
{
	int x = spec/10;
	int y = spec%10;
	
	char types[6][10] = {"int", "float", "string", "bool", "list", "list"};
	yyerror("");
	switch(type)
	{
		case 1:
			printf("unsupported operand type(s) for ** or pow(): %s and %s in line %d\n", types[x], types[y], curr_line);
			break;

		case 2:
			printf("unsupported operand type(s) for mod(): %s and %s in line %d\n", types[x], types[y], curr_line);
			break;

		case 3:
			printf("ZeroDivisionError: integer division or modulo by zero in line %d\n", curr_line);
			break;
		
		case 4:
			printf("unsupported operand type(s) for div(): %s and %s in line %d\n", types[x], types[y], curr_line);
			break;

		case 5:
			printf("unsupported operand type(s) for mul(): %s and %s in line %d\n", types[x], types[y], curr_line);
			break;
		
		case 6:
			printf("Undefined variable %s in line %d\n", id, curr_line);
			break;

		case 7:
			printf("unsupported operand type(s) for sub(): %s and %s in line %d\n", types[x], types[y], curr_line);
			break;

		case 8:
			printf("unsupported operand type(s) for add(): %s and %s in line %d\n", types[x], types[y], curr_line);
			break;

		case 9:
			printf("index out of range in variable %s, line %d\n", id, curr_line);
			break;

		case 10:
			printf("variable %s not indexable in line %d\n", id, curr_line);
			break;

		case 11:
			printf("cannot have jump statement break outside a loop in line %d\n", curr_line);
			break;

		case 12:
			printf("cannot have jump statement continue outside a loop in line %d\n", curr_line);
			break;

	}
	exit(1);
	return 0;
}
void yyerror(const char* error)
{
	printf("Syntax Error:\n");
}

int main()
{
	global = (struct scope*)malloc(sizeof(struct scope));
	global->parent_scope = NULL;	
	global->next_in_scope = NULL;
	global->child_scope = NULL;
	global->var_items = NULL;
	global->position = 1;

	stack_init(&breakpoint);
	stack_init(&looppoint);

	current_scope = global;

	if(!yyparse())
	{
		//print_table(global, 0);
		return 0;
	}
	return 1;
}

char* newLabel(char* label)
{
	char* x = (char*)malloc(sizeof(char)*10);
	if(label == "label")
	{
		sprintf(x,"L%d",label_count);
		label_count++;
	}
	else
	{
		strcpy(x,label);
	}
	return x;
}

char* newTemp()
{
	char* x = (char*)malloc(sizeof(char)*10);
	sprintf(x,"t%d",temp_count++);
	return x;
}
