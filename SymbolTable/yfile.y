%{
	#include <stdio.h>
	#include "symboltable.h"
	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>

	struct scope *global, *current_scope;
	int curr_line = 1;
	int temp = 1;

	int yyerror(const char* error);
	int error(int type, int spec, char* id);
	int yylex();
	
	int inloop = 0;
%}


%code requires{
	struct datatype
	{
		int val_type;
		float numval;
		char sval[64];
		char idval[64];
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
P: 							all_stmt T_EOF {YYACCEPT;}

literal:					T_INTEGER	{$<data.val_type>$ = int_type; $<data.numval>$ = $<data.numval>1;}
						|	T_FLOAT		{$<data.val_type>$ = float_type; $<data.numval>$ = $<data.numval>1;}
						|	T_STRING	{$<data.val_type>$ = string_type; strcpy($<data.sval>$,$<data.sval>1);  }
						|	T_BOOLEAN	{$<data.val_type>$ = bool_type; $<data.numval>$ = $<data.numval>1;}
						|	list_stmt	{$<data.val_type>$ = list_type; strcpy($<data.sval>$,$<data.sval>1);  }	

indexes:					T_OPENS T_INTEGER T_CLOSES indexes {sprintf($<data.sval>$,"%d %s", (int)$<data.numval>2, $<data.sval>4);}
						|	{strcpy($<data.sval>$, "");};					

all_stmt:					simple_stmt line all_stmt
						|	{inloop++;} compound_stmt  line suite {inloop--;} all_stmt
						|	;

compound_stmt:  			while_stmt
						|	for_stmt

suite:						indent all_stmt dedent
						|	line suite

line:						T_NEWLINE 	{curr_line++;}

indent:						T_INDENT	{current_scope = create_scope(current_scope);}

dedent:						T_DEDENT	{current_scope = exit_scope(current_scope);}


simple_stmt:				print_stmt
						|	assignment_stmt
						|	break_stmt
						|	continue_stmt
						|	import_stmt
						|	aug_assignment_stmt
						|	;

print_stmt: 				T_PRINT T_OPENP print_list T_CLOSEP

print_list:					expression_stmt T_COMMA print_list
						|	expression_stmt

assignment_stmt:			T_IDENTIFIER indexes T_EQUAL expression_stmt {if(strlen($<data.sval>2)!=0){struct datatype *temp=lookup(current_scope,$<data.idval>1, $<data.sval>2); if(temp==NULL){error(6,0,$<data.idval>1);} if(temp!=NULL){if(temp->val_type<0){error(temp->val_type+11,0, $<data.idval>1);}}}  if(strlen($<data.sval>2)==0){if($<data.val_type>4==string_type || $<data.val_type>4==list_type){add_variable(current_scope, $<data.idval>1, $<data.val_type>4, curr_line, (void*)(($<data.sval>4))); } else{add_variable(current_scope, $<data.idval>1, $<data.val_type>4, curr_line, (void*)(&($<data.numval>4)));}}}


list_stmt:					T_OPENS item T_CLOSES 	{sprintf($<data.sval>$, "[%s]", $<data.sval>2); $<data.val_type>$=list_type;}
						|   T_OPENS T_CLOSES 		{sprintf($<data.sval>$, "[]"); $<data.val_type>$=list_type;}

item:						list_literal T_COMMA item 	{sprintf($<data.sval>$, "%s %s", $<data.sval>1, $<data.sval>3);}
						|   list_literal	{sprintf($<data.sval>$, "%s", $<data.sval>1);}

list_literal:				T_INTEGER	{sprintf($<data.sval>$, "%d", (int)$<data.numval>1);}
						|	T_FLOAT		{sprintf($<data.sval>$, "%f", (float)$<data.numval>1);}
						|	list_stmt	{sprintf($<data.sval>$, "%s", $<data.sval>1);}

break_stmt:					T_BREAK
							{if(inloop==0) error(11, 0, 0);}

continue_stmt:				T_CONTINUE
							{if(inloop==0) error(12, 0, 0);}

import_stmt:				T_IMPORT import_list

import_list:				T_IDENTIFIER T_COMMA import_list
						|	T_IDENTIFIER

aug_assignment_stmt:		T_IDENTIFIER arith_operator T_EQUAL expression_stmt

logical_exp:   				condition rel_op logical_exp | condition
rel_op:   					T_AND | T_OR | T_NOT

arith_operator:				T_PLUS
						|	T_MINUS
						|	T_STAR
						|	T_POWER
						|	T_DIVIDE
						|	T_MOD

condition:					expression_stmt comp_operator condition | expression_stmt

comp_operator:
			            	T_LESSER
			            |	T_GREATER
			            |	T_EQUAL T_EQUAL
			            |	T_GREATER T_EQUAL
			            |	T_LESSER T_EQUAL
			            |	T_NO T_EQUAL

expression_stmt:			expression_stmt T_PLUS term {int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(8, flag, NULL); switch(flag){case 22: strcpy($<data.sval>$, strcat($<data.sval>1, $<data.sval>3)); $<data.val_type>$ = string_type; break; case 20: case 21: case 23: case 2: case 12: case 32: error(8, flag, NULL); break; default: $<data.numval>$ = $<data.numval>1+$<data.numval>3; if(flag==0 || flag==30 || flag==3 || flag==33) $<data.val_type>$ = int_type; else $<data.val_type>$ = float_type;}}	
						|	expression_stmt T_MINUS term {int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(7, flag, NULL); switch(flag){case 20: case 21: case 22: case 23: case 2: case 12: case 32: error(7, flag, NULL); break; default: $<data.numval>$ = $<data.numval>1-$<data.numval>3; if(flag==0 || flag==30 || flag==3 || flag==33) $<data.val_type>$ = int_type; else $<data.val_type>$ = float_type;}}
						|	term 	{$<data.val_type>$ = $<data.val_type>1; switch($<data.val_type>$){ case int_type: case float_type: case bool_type: $<data.numval>$ = $<data.numval>1; break; case string_type: strcpy($<data.sval>$, $<data.sval>1); break;}}	


term:						term T_STAR factor 	{int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(5, flag, NULL); switch(flag){case 12: case 21: case 22: error(5, flag, NULL); break; case 20: case 23: case 2: case 32:  error(5, flag, NULL);break; default: $<data.numval>$ = $<data.numval>1*$<data.numval>3; if(flag==0 || flag==30 || flag==3) $<data.val_type>$ = int_type; else $<data.val_type>$ = float_type;}}
						|	term T_DIVIDE factor	{int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(4, flag, NULL); switch(flag){case 20: case 21: case 22: case 23: case 2: case 12: case 32:  error(4, flag, NULL); break; default: if($<data.numval>3==0) error(3, 0, NULL); $<data.numval>$ = $<data.numval>1/$<data.numval>3; $<data.val_type>$ = float_type;}}
						|	term T_MOD factor 	{int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(2, flag, NULL); switch(flag){case 20: case 21: case 22: case 23: case 2: case 12: case 32: case 1: case 10: case 11: case 13: case 31: error(2, flag, NULL); break; default: if($<data.numval>3==0) error(2, 0, NULL); $<data.numval>$ = (int)$<data.numval>1%(int)$<data.numval>3; $<data.val_type>$ = int_type;}}	
						|	factor 	{$<data.val_type>$ = $<data.val_type>1; switch($<data.val_type>$){ case int_type: case float_type: case bool_type: $<data.numval>$ = $<data.numval>1; break; case string_type: strcpy($<data.sval>$, $<data.sval>1); break;}}

factor:						power T_POWER factor 	{int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(1, flag, NULL); switch(flag){case 20: case 21: case 22: case 23: case 2: case 12: case 32: error(1, flag, NULL); break; default: $<data.numval>$ = pow($<data.numval>1, $<data.numval>3); if(flag==0 || flag==30 || flag==3 || flag==33) $<data.val_type>$ = int_type; else $<data.val_type>$ = float_type;}}	
						|	power 	{$<data.val_type>$ = $<data.val_type>1; switch($<data.val_type>$){ case int_type: case float_type: case bool_type: $<data.numval>$ = $<data.numval>1; break; case string_type: strcpy($<data.sval>$, $<data.sval>1); break;}}

power:						T_OPENP expression_stmt T_CLOSEP 	{$<data.val_type>$ = $<data.val_type>2; switch($<data.val_type>$){ case int_type: case float_type: case bool_type: $<data.numval>$ = $<data.numval>2; break; case string_type: strcpy($<data.sval>$, $<data.sval>2); break;}}
						|	literal 	{ $<data.val_type>$ = $<data.val_type>1; switch($<data.val_type>$){ case int_type: case float_type: case bool_type: $<data.numval>$ = $<data.numval>1; break; case string_type: strcpy($<data.sval>$, $<data.sval>1); break;}}	
						|	T_IDENTIFIER indexes { struct datatype *temp=lookup(current_scope,$<data.idval>1, $<data.sval>2); if(temp!=NULL){if(temp->val_type<0){error(temp->val_type+11,0, $<data.idval>1);}$<data.val_type>$=temp->val_type; if(temp->val_type==int_type|| temp->val_type==float_type || temp->val_type==bool_type)$<data.numval>$=temp->numval; else {strcpy($<data.sval>$, temp->sval);}} else{ error(6,0,$<data.idval>1); } } 
 
while_stmt:					T_WHILE logical_exp T_COLON 


for_stmt:					T_FOR T_IDENTIFIER T_IN range_stmt T_COLON {add_variable(current_scope, $<data.idval>2, int_type, curr_line, (void*)(&temp));}

range_stmt:					T_RANGE T_OPENP T_INTEGER T_COMMA T_INTEGER T_CLOSEP
						|	T_RANGE T_OPENP T_INTEGER T_COMMA T_INTEGER T_COMMA T_INTEGER T_CLOSEP
						|	T_STRING



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
	return 1;
}
int yyerror(const char* error)
{
	printf("Syntax Error:%s\n", error);
	return 1;
}

int main()
{
	global = (struct scope*)malloc(sizeof(struct scope));
	global->parent_scope = NULL;	
	global->next_in_scope = NULL;
	global->child_scope = NULL;
	global->var_items = NULL;
	global->position = 1;

	current_scope = global;

	if(!yyparse())
	{
		printf("Valid\n");
		print_table(global, 0);
		return 0;
	}
	return 1;
}
