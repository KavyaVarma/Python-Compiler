/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_ICG_Y_TAB_H_INCLUDED
# define YY_YY_ICG_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 28 "./ICG/yfile.y" /* yacc.c:1909  */

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

#line 64 "./ICG/y.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_OR = 258,
    T_AND = 259,
    T_BOOLEAN = 260,
    T_INTEGER = 261,
    T_IDENTIFIER = 262,
    T_STRING = 263,
    T_FLOAT = 264,
    T_FROM = 265,
    T_NOT = 266,
    T_WHILE = 267,
    T_WITH = 268,
    T_ELSE = 269,
    T_IF = 270,
    T_BREAK = 271,
    T_IN = 272,
    T_CONTINUE = 273,
    T_RETURN = 274,
    T_DEF = 275,
    T_FOR = 276,
    T_IMPORT = 277,
    T_AS = 278,
    T_PRINT = 279,
    T_PLUS = 280,
    T_MINUS = 281,
    T_POWER = 282,
    T_STAR = 283,
    T_DIVIDE = 284,
    T_MOD = 285,
    T_OPENP = 286,
    T_CLOSEP = 287,
    T_OPENS = 288,
    T_CLOSES = 289,
    T_EQUAL = 290,
    T_COMMA = 291,
    T_INDENT = 292,
    T_LESSER = 293,
    T_GREATER = 294,
    T_NO = 295,
    T_NEWLINE = 296,
    T_COLON = 297,
    T_RANGE = 298,
    T_DEDENT = 299,
    T_EOF = 300,
    T_SEMICOLON = 301
  };
#endif
/* Tokens.  */
#define T_OR 258
#define T_AND 259
#define T_BOOLEAN 260
#define T_INTEGER 261
#define T_IDENTIFIER 262
#define T_STRING 263
#define T_FLOAT 264
#define T_FROM 265
#define T_NOT 266
#define T_WHILE 267
#define T_WITH 268
#define T_ELSE 269
#define T_IF 270
#define T_BREAK 271
#define T_IN 272
#define T_CONTINUE 273
#define T_RETURN 274
#define T_DEF 275
#define T_FOR 276
#define T_IMPORT 277
#define T_AS 278
#define T_PRINT 279
#define T_PLUS 280
#define T_MINUS 281
#define T_POWER 282
#define T_STAR 283
#define T_DIVIDE 284
#define T_MOD 285
#define T_OPENP 286
#define T_CLOSEP 287
#define T_OPENS 288
#define T_CLOSES 289
#define T_EQUAL 290
#define T_COMMA 291
#define T_INDENT 292
#define T_LESSER 293
#define T_GREATER 294
#define T_NO 295
#define T_NEWLINE 296
#define T_COLON 297
#define T_RANGE 298
#define T_DEDENT 299
#define T_EOF 300
#define T_SEMICOLON 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 50 "./ICG/yfile.y" /* yacc.c:1909  */

	struct datatype data;

#line 172 "./ICG/y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ICG_Y_TAB_H_INCLUDED  */
