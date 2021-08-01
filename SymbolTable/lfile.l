%{
#include "y.tab.h"
#include<stdio.h>
#include<stdlib.h>

int level = 0;
int curr = 0;
int indenting = 0;

int check()
{
	if(curr<level)
	{
		level--;
		return 1;
	}
	indenting = 0;
	return 0;
}

%}

digit [0-9]
letter [A-Za-z]


%%
"and"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_AND;}
"from"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_FROM;}
"not"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_NOT;}
"while"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_WHILE;}
"or"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_OR;}
"with"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_WITH;}
"else"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_ELSE;}
"if"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_IF;}
"break"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_BREAK;}
"in"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_IN;}
"continue"						{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_CONTINUE;}
"return"						{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_RETURN;}
"def"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_DEF;}
"for"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_FOR;}
"import"						{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_IMPORT;}
"as"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_AS;}
"print"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_PRINT;}
"range"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_RANGE;}
("True"|"False")				{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} if(strcmp(yytext, "False")==0) {yylval.data.numval = 0;} else {yylval.data.numval = 1;} return T_BOOLEAN;}
{digit}+ 						{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} yylval.data.numval = atof(yytext); return T_INTEGER;}
{digit}+([\.]{digit}+)?([E|e][\+|\-]?{digit}+)?	  			{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} yylval.data.numval = atof(yytext); return T_FLOAT; }
[\"][^\"\n]*[\"] 				{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} strncpy(yylval.data.sval, yytext+1, strlen(yytext)-2); yylval.data.sval[strlen(yytext)-2] = '\0'; return T_STRING;}
[\'][^\'\n]*[\'] 				{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} strncpy(yylval.data.sval, yytext+1, strlen(yytext)-2); yylval.data.sval[strlen(yytext)-2] = '\0'; return T_STRING; }
({letter}|_)({letter}|{digit})* {if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} strcpy(yylval.data.idval, yytext); return T_IDENTIFIER;}
"+"								{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_PLUS;}
"-"								{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_MINUS;}
"**"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_POWER;}
"*"								{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_STAR;}
"\/"							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_DIVIDE;}
"!"               				{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_NO;}
"%"								{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_MOD;}
"("								{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_OPENP;}
")"								{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_CLOSEP;}

"["								{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_OPENS;}
"]"								{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_CLOSES;}


"="								{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_EQUAL;}	
":"               				{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_COLON;}
","								{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_COMMA;}
";"								{return T_SEMICOLON;}
"\t"							{indenting = 1; curr++; if(curr>level){level++; return T_INDENT;}}
"\n"							{curr = 0; indenting = 1; return T_NEWLINE;}
"<"    							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_LESSER;}
">"    							{if(indenting==1){if(check()==1){yyless(0); return T_DEDENT;}} return T_GREATER;}
"\t"*"#"[^\n]*					{}
[' ']							{}
<<EOF>>							{if(level!=0){level--;unput(EOF);return T_DEDENT;}return T_EOF;}
.								{}

%%

/*int main()
{
	while(yylex()){}
}*/
