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
	
	node *mknode(node *left, node *right, char *token);
	void printtree(node *tree);
	void printtree2(node *tree);
%}


%code requires{
	struct datatype
	{
		int val_type;
		float numval;
		char sval[64];
		char idval[64];
		struct node *res;
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
P: 							all_stmt T_EOF { printtree($<data.res>1); printf("\n"); YYACCEPT;}

literal:					T_INTEGER	{$<data.val_type>$ = int_type; $<data.numval>$ = $<data.numval>1; char snum[10]; sprintf(snum, "%f", $<data.numval>1); 	 $<data.res>$=mknode(0,0,snum); }
						|	T_FLOAT		{$<data.val_type>$ = float_type; $<data.numval>$ = $<data.numval>1; char snum[10]; sprintf(snum, "%f",$<data.numval>1);  $<data.res>$=mknode(0,0,snum); }
						|	T_STRING	{$<data.val_type>$ = string_type; strcpy($<data.sval>$,$<data.sval>1);  $<data.res>$=mknode(0,0,$<data.sval>1); }
						|	T_BOOLEAN	{$<data.val_type>$ = bool_type; $<data.numval>$ = $<data.numval>1; char snum[10]; sprintf(snum, "%f",$<data.numval>1); $<data.res>$=mknode(0,0,snum);  }
						|	list_stmt	{$<data.val_type>$ = list_type; strcpy($<data.sval>$,$<data.sval>1); $<data.res>$=mknode(0,0,$<data.sval>$); }	

indexes:					T_OPENS T_INTEGER T_CLOSES indexes {sprintf($<data.sval>$,"%d %s", (int)$<data.numval>2, $<data.sval>4); sprintf($<data.idval>$,"[%d]%s", (int)$<data.numval>2, $<data.idval>4);}
						|	{strcpy($<data.sval>$, ""); strcpy($<data.idval>$, "");};					

all_stmt:					simple_stmt line all_stmt { $<data.res>$=mknode($<data.res>1,$<data.res>3,"seq");}
						|	compound_stmt  { $<data.res>$=$<data.res>1; }
						|	{$<data.res>$=NULL;}

compound_stmt:  			while_stmt line suite all_stmt {$<data.res>$=mknode($<data.res>1,$<data.res>3,"while");}
						|	for_stmt line suite all_stmt { node * newnode=mknode(0,0,"for"); newnode->child=$<data.res>1; newnode->child->next->next->next=$<data.res>3; $<data.res>$=newnode;  }

suite:						indent all_stmt dedent {$<data.res>$=$<data.res>2;}
						|	line suite {$<data.res>$=$<data.res>2;}

line:						T_NEWLINE 	{curr_line++;}

indent:						T_INDENT	{current_scope = create_scope(current_scope);}

dedent:						T_DEDENT	{current_scope = exit_scope(current_scope);}


simple_stmt:				print_stmt {$<data.res>$=$<data.res>1;}
						|	assignment_stmt {$<data.res>$=$<data.res>1;}
						|	break_stmt {$<data.res>$=$<data.res>1;}
						|	continue_stmt {$<data.res>$=$<data.res>1;}
						|	import_stmt {$<data.res>$=$<data.res>1;}
						|	aug_assignment_stmt {$<data.res>$=$<data.res>1;}
						|	;

print_stmt: 				T_PRINT T_OPENP print_list T_CLOSEP {$<data.res>$=mknode($<data.res>3,0,"print");}

print_list:					expression_stmt T_COMMA print_list
						|	expression_stmt

assignment_stmt:			T_IDENTIFIER indexes T_EQUAL expression_stmt {if($<data.val_type>4==string_type || $<data.val_type>4==list_type){add_variable(current_scope, $<data.idval>1, $<data.val_type>4, curr_line, (void*)(($<data.sval>4))); } else{add_variable(current_scope, $<data.idval>1, $<data.val_type>4, curr_line, (void*)(&($<data.numval>4)));}  sprintf($<data.idval>$, "%s%s", $<data.idval>1, $<data.idval>2); $<data.res>$=mknode(mknode(0,0,$<data.idval>$),$<data.res>4,"Assign"); }


list_stmt:					T_OPENS item T_CLOSES 	{sprintf($<data.sval>$, "[%s]", $<data.sval>2); $<data.val_type>$=list_type;  }
						|   T_OPENS T_CLOSES 		{sprintf($<data.sval>$, "[]"); $<data.val_type>$=list_type;}

item:						list_literal T_COMMA item 	{sprintf($<data.sval>$, "%s %s", $<data.sval>1, $<data.sval>3);}
						|   list_literal	{sprintf($<data.sval>$, "%s", $<data.sval>1);}

list_literal:				T_INTEGER	{sprintf($<data.sval>$, "%d", (int)$<data.numval>1);}
						|	T_FLOAT		{sprintf($<data.sval>$, "%f", (float)$<data.numval>1);}
						|	list_stmt	{sprintf($<data.sval>$, "%s", $<data.sval>1);}

break_stmt:					T_BREAK {$<data.res>$=mknode(0,0,"break");}

continue_stmt:				T_CONTINUE {$<data.res>$=mknode(0,0,"continue");}

import_stmt:				T_IMPORT import_list {$<data.res>$=$<data.res>2;}
 
import_list:				T_IDENTIFIER T_COMMA import_list {$<data.res>$=mknode($<data.res>1,$<data.res>3,"import");}
						|	T_IDENTIFIER {$<data.res>$=mknode(0,0,(char*)yylval.data.idval);}

aug_assignment_stmt:		T_IDENTIFIER arith_operator T_EQUAL expression_stmt

logical_exp:   				condition rel_op logical_exp {$<data.res>$=mknode($<data.res>1,$<data.res>3,$<data.idval>2);}
								| condition {$<data.res>$=$<data.res>1;}
rel_op:   					T_AND {strcpy($<data.idval>$,$<data.idval>1);}
							| T_OR {strcpy($<data.idval>$,$<data.idval>1);}
							| T_NOT {strcpy($<data.idval>$,$<data.idval>1);}

arith_operator:				T_PLUS
						|	T_MINUS
						|	T_STAR
						|	T_POWER
						|	T_DIVIDE
						|	T_MOD

condition:					expression_stmt comp_operator condition { $<data.res>$=mknode($<data.res>1,$<data.res>3,$<data.idval>2);  }
							| expression_stmt { $<data.res>$=$<data.res>1;  }

comp_operator:
			            	T_LESSER { strcpy($<data.idval>$,$<data.idval>1); }
			            |	T_GREATER {strcpy($<data.idval>$,$<data.idval>1); }
			            |	T_EQUAL T_EQUAL { strcpy($<data.idval>$,$<data.idval>1); strcat($<data.idval>$,$<data.idval>1);}
			            |	T_GREATER T_EQUAL { strcpy($<data.idval>$,$<data.idval>1); strcat($<data.idval>$,$<data.idval>1);}
			            |	T_LESSER T_EQUAL { strcpy($<data.idval>$,$<data.idval>1); strcat($<data.idval>$,$<data.idval>1);}
			            |	T_NO T_EQUAL { strcpy($<data.idval>$,$<data.idval>1); strcat($<data.idval>$,$<data.idval>1);}

expression_stmt:			expression_stmt T_PLUS term {int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(8, flag, NULL); switch(flag){case 22: strcpy($<data.sval>$, strcat($<data.sval>1, $<data.sval>3)); $<data.val_type>$ = string_type; break; case 20: case 21: case 23: case 2: case 12: case 32: error(8, flag, NULL); break; default: $<data.numval>$ = $<data.numval>1+$<data.numval>3; if(flag==0 || flag==30 || flag==3 || flag==33) $<data.val_type>$ = int_type; else $<data.val_type>$ = float_type;} $<data.res>$=mknode($<data.res>1,$<data.res>3,"+"); }	
						|	expression_stmt T_MINUS term {int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(7, flag, NULL); switch(flag){case 20: case 21: case 22: case 23: case 2: case 12: case 32: error(7, flag, NULL); break; default: $<data.numval>$ = $<data.numval>1-$<data.numval>3; if(flag==0 || flag==30 || flag==3 || flag==33) $<data.val_type>$ = int_type; else $<data.val_type>$ = float_type;} $<data.res>$=mknode($<data.res>1,$<data.res>3,"-"); }
						|	term 	{$<data.val_type>$ = $<data.val_type>1; switch($<data.val_type>$){ case int_type: case float_type: case bool_type: $<data.numval>$ = $<data.numval>1; break; case string_type: strcpy($<data.sval>$, $<data.sval>1); break;} $<data.res>$=$<data.res>1; }	


term:						term T_STAR factor 	{int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(5, flag, NULL); switch(flag){case 12: case 21: case 22: error(5, flag, NULL); break; case 20: case 23: case 2: case 32:  error(5, flag, NULL);break; default: $<data.numval>$ = $<data.numval>1*$<data.numval>3; if(flag==0 || flag==30 || flag==3) $<data.val_type>$ = int_type; else $<data.val_type>$ = float_type;} $<data.res>$=mknode($<data.res>1,$<data.res>3,"*"); }
						|	term T_DIVIDE factor	{int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(4, flag, NULL); switch(flag){case 20: case 21: case 22: case 23: case 2: case 12: case 32:  error(4, flag, NULL); break; default: if($<data.numval>3==0) error(3, 0, NULL); $<data.numval>$ = $<data.numval>1/$<data.numval>3; $<data.val_type>$ = float_type;} $<data.res>$=mknode($<data.res>1,$<data.res>3,"/"); }
						|	term T_MOD factor 	{int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(2, flag, NULL); switch(flag){case 20: case 21: case 22: case 23: case 2: case 12: case 32: case 1: case 10: case 11: case 13: case 31: error(2, flag, NULL); break; default: if($<data.numval>3==0) error(2, 0, NULL); $<data.numval>$ = (int)$<data.numval>1%(int)$<data.numval>3; $<data.val_type>$ = int_type;} $<data.res>$=mknode($<data.res>1,$<data.res>3,"%"); }	
						|	factor 	{$<data.val_type>$ = $<data.val_type>1; switch($<data.val_type>$){ case int_type: case float_type: case bool_type: $<data.numval>$ = $<data.numval>1; break; case string_type: strcpy($<data.sval>$, $<data.sval>1); break;} $<data.res>$=$<data.res>1; }

factor:						power T_POWER factor 	{int flag = $<data.val_type>1*10+$<data.val_type>3; if($<data.val_type>1==4 || $<data.val_type>1==5 || $<data.val_type>3==4 || $<data.val_type>3==5) error(1, flag, NULL); switch(flag){case 20: case 21: case 22: case 23: case 2: case 12: case 32: error(1, flag, NULL); break; default: $<data.numval>$ = pow($<data.numval>1, $<data.numval>3); if(flag==0 || flag==30 || flag==3 || flag==33) $<data.val_type>$ = int_type; else $<data.val_type>$ = float_type;} $<data.res>$=mknode($<data.res>1,$<data.res>3,"**"); }	
						|	power 	{$<data.val_type>$ = $<data.val_type>1; switch($<data.val_type>$){ case int_type: case float_type: case bool_type: $<data.numval>$ = $<data.numval>1; break; case string_type: strcpy($<data.sval>$, $<data.sval>1); break;} $<data.res>$=$<data.res>1; }

power:						T_OPENP expression_stmt T_CLOSEP 	{$<data.val_type>$ = $<data.val_type>2; switch($<data.val_type>$){ case int_type: case float_type: case bool_type: $<data.numval>$ = $<data.numval>2; break; case string_type: strcpy($<data.sval>$, $<data.sval>2); break;} $<data.res>$=$<data.res>2; }
						|	literal 	{ $<data.val_type>$ = $<data.val_type>1; switch($<data.val_type>$){ case int_type: case float_type: case bool_type: $<data.numval>$ = $<data.numval>1; break; case string_type: strcpy($<data.sval>$, $<data.sval>1); break;} $<data.res>$=$<data.res>1; }	
						|	T_IDENTIFIER indexes { struct datatype *temp=lookup(current_scope,$<data.idval>1, $<data.sval>2); if(temp!=NULL){if(temp->val_type<0){error(temp->val_type+11,0, $<data.idval>1);}$<data.val_type>$=temp->val_type; if(temp->val_type==int_type|| temp->val_type==float_type || temp->val_type==bool_type)$<data.numval>$=temp->numval; else {strcpy($<data.sval>$, temp->sval);}} else{ error(6,0,$<data.idval>1); } if(strcmp($<data.sval>2,"")==0){ char snum[10]; strcpy(snum,$<data.idval>1);  $<data.res>$=mknode(0,0,snum); } else {char snum[10]; strcpy(snum,$<data.idval>1); strcat(snum,"["); strcat(snum,$<data.sval>2); strcat(snum,"]");  $<data.res>$=mknode(0,0,snum); } }  

while_stmt:					T_WHILE logical_exp T_COLON { $<data.res>$=$<data.res>2; }


for_stmt:					T_FOR T_IDENTIFIER T_IN range_stmt T_COLON {add_variable(current_scope, $<data.idval>2, int_type, curr_line, (void*)(&temp)); 
																						//node *newnode = (node *)malloc(sizeof(node));
																						node * newnode=mknode(0,0,$<data.idval>2);
																						newnode->next=mknode(0,0,"in");
																						//printf(" %s ",newnode->next->token);
																						newnode->next->next=$<data.res>4;
																						
																						//printf(" %s ",newnode->next->next->token);
																						$<data.res>$=newnode;
																						}

range_stmt:					T_RANGE T_OPENP T_INTEGER T_COMMA T_INTEGER T_CLOSEP {  char snum[10]; sprintf(snum, "%f", $<data.numval>3); char snum2[10]; sprintf(snum2, "%f", $<data.numval>5); 	 $<data.res>$=mknode(mknode(0,0,snum),mknode(0,0,snum2),"range");  }
						|	T_RANGE T_OPENP T_INTEGER T_COMMA T_INTEGER T_COMMA T_INTEGER T_CLOSEP {  $<data.res>5->next=$<data.res>7; $<data.res>$=mknode($<data.res>3,$<data.res>5,"rangewithstep" ); }
						|	T_STRING { $<data.res>$=$<data.res>1; }



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
		//printf("Valid\n");
		//print_table(global, 0);
		return 0;
	}
	return 1;
}

node *mknode(node *child, node *next, char *token)
{ /* malloc the node */
	node *newnode = (node *)malloc(sizeof(node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	if(child)
		child->next=next;
	newnode->child=child;
	//newnode->child = child;
	//newnode->child->next = next;
	newnode->token = newstr;
	//printf(" %s ",newnode->token);
	return(newnode);
}
void printtree(node *tree)
{
	//printf(" %s ", tree->token);
	//printf(" %s ", tree->child->token);
	//printf(" %s ", tree->child->child->token);
	//printf(" %s ", tree->child->child->next->token);
	int i;
	if(!tree)	return;
	if(tree)
		printf(" %s ", tree->token);
	printf("\n");
	node* temp=tree->child;
	while(temp){
		printf(" %s ",temp->token);
		temp=temp->next;
	}
	temp=tree->child;
	while(temp){
		printtree2(temp);
		temp=temp->next;
	}
	/*
	if (tree->left || tree->right)
	printf("(");
	printf(" %s ", tree->token);
	if (tree->left)
	printtree(tree->left);	
	if (tree->right)
	printtree(tree->right);
	if (tree->left || tree->right)
	printf(")");*/
}

void printtree2(node *tree)
{
	if(!tree)	return;
	node* temp=tree->child;
	printf("\n");
	while(temp){
		printf(" %s ",temp->token);
		temp=temp->next;
	}
	temp=tree->child;
	while(temp){
		printtree2(temp);
		temp=temp->next;
	}
}


