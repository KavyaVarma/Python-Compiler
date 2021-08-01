/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "./SyntaxTree/yfile.y" /* yacc.c:339  */

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

#line 86 "./SyntaxTree/y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_SYNTAXTREE_Y_TAB_H_INCLUDED
# define YY_YY_SYNTAXTREE_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 22 "./SyntaxTree/yfile.y" /* yacc.c:355  */

	struct datatype
	{
		int val_type;
		float numval;
		char sval[64];
		char idval[64];
		struct node *res;
	};

#line 127 "./SyntaxTree/y.tab.c" /* yacc.c:355  */

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
#line 35 "./SyntaxTree/yfile.y" /* yacc.c:355  */

	struct datatype data;

#line 235 "./SyntaxTree/y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAXTREE_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 252 "./SyntaxTree/y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   117

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    89,    89,    91,    92,    93,    94,    95,    97,    98,
     100,   101,   102,   104,   105,   107,   108,   110,   112,   114,
     117,   118,   119,   120,   121,   122,   123,   125,   127,   128,
     130,   133,   134,   136,   137,   139,   140,   141,   143,   145,
     147,   149,   150,   152,   154,   155,   156,   157,   158,   160,
     161,   162,   163,   164,   165,   167,   168,   171,   172,   173,
     174,   175,   176,   178,   179,   180,   183,   184,   185,   186,
     188,   189,   191,   192,   193,   195,   198,   209,   210,   211
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_OR", "T_AND", "T_BOOLEAN",
  "T_INTEGER", "T_IDENTIFIER", "T_STRING", "T_FLOAT", "T_FROM", "T_NOT",
  "T_WHILE", "T_WITH", "T_ELSE", "T_IF", "T_BREAK", "T_IN", "T_CONTINUE",
  "T_RETURN", "T_DEF", "T_FOR", "T_IMPORT", "T_AS", "T_PRINT", "T_PLUS",
  "T_MINUS", "T_POWER", "T_STAR", "T_DIVIDE", "T_MOD", "T_OPENP",
  "T_CLOSEP", "T_OPENS", "T_CLOSES", "T_EQUAL", "T_COMMA", "T_INDENT",
  "T_LESSER", "T_GREATER", "T_NO", "T_NEWLINE", "T_COLON", "T_RANGE",
  "T_DEDENT", "T_EOF", "T_SEMICOLON", "$accept", "P", "literal", "indexes",
  "all_stmt", "compound_stmt", "suite", "line", "indent", "dedent",
  "simple_stmt", "print_stmt", "print_list", "assignment_stmt",
  "list_stmt", "item", "list_literal", "break_stmt", "continue_stmt",
  "import_stmt", "import_list", "aug_assignment_stmt", "logical_exp",
  "rel_op", "arith_operator", "condition", "comp_operator",
  "expression_stmt", "term", "factor", "power", "while_stmt", "for_stmt",
  "range_stmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -49

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-49)))

#define YYTABLE_NINF -27

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,    45,    27,   -49,   -49,     0,     2,   -13,    30,    14,
     -49,    35,   -49,   -49,   -49,   -49,   -49,   -49,    35,    35,
     -49,   -49,   -49,   -49,   -49,   -49,    56,    42,    44,   -49,
     -49,    55,   -49,   -49,    27,    11,   -49,   -49,    47,    46,
      29,    57,   -49,    63,    74,    58,   -49,    27,   -49,   -49,
     -49,     7,   -31,   -31,    59,    27,    27,   -49,    21,   -49,
     -49,   -49,   -49,    61,    60,   -49,   -49,   -49,   -49,    27,
      27,    27,    62,    64,    65,    66,    27,    27,    27,    27,
      27,    -3,     2,    70,   -10,   -49,   -49,     7,   -31,     7,
       7,    55,    12,    12,   -49,   -49,    18,   -49,    57,    57,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
      67,    50,   -49,   -49,    27,   -49,   -49,    68,   -49,   -49,
     -49,    97,   -49,   -49,   -49,   -49,    69,    98,    20,   -49,
     100,    75,   -49
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      12,     9,     0,    38,    39,     0,     0,     0,     0,     0,
      11,     0,    20,    21,    22,    23,    24,    25,     0,     0,
      49,    50,    52,    51,    53,    54,     0,     0,     0,     6,
       3,     9,     5,     4,     0,     0,    73,     7,     0,    45,
      56,    65,    69,    71,     0,    42,    40,     0,     1,     2,
      17,    12,     0,     0,     0,     0,     0,    74,     0,    35,
      36,    32,    37,     0,    34,    75,    47,    46,    48,     0,
       0,     0,     0,    57,    58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    10,    18,    12,     0,    12,
      12,     9,    30,    43,    72,    31,     0,    44,    63,    64,
      59,    61,    60,    62,    55,    66,    67,    68,    70,    79,
       0,     0,    41,    27,     0,    13,    16,     0,    14,     8,
      33,     0,    76,    28,    19,    15,     0,     0,     0,    77,
       0,     0,    78
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,   -49,   -30,   -48,   -49,   -45,    -7,   -49,   -49,
     -49,   -49,    -6,   -49,   -33,    13,   -49,   -49,   -49,   -49,
      28,   -49,    48,   -49,   -49,    37,   -49,   -34,    -5,     4,
     -49,   -49,   -49,   -49
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     8,    36,    27,     9,    10,    87,    88,    89,   125,
      11,    12,    83,    13,    37,    63,    64,    14,    15,    16,
      46,    17,    38,    69,    28,    39,    76,    40,    41,    42,
      43,    18,    19,   111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    57,    62,    85,    51,   109,    86,    44,    90,    45,
      50,    52,    53,    84,     1,    70,    71,    59,    47,     2,
      60,    92,    93,     3,    59,     4,   114,    60,     5,     6,
      48,     7,    29,    30,    31,    32,    33,    70,    71,   115,
     110,   117,   118,   116,    35,    61,    70,    71,   -26,    66,
      67,    35,   129,    94,    70,    71,   130,    68,    34,    49,
      35,   119,    54,    62,    72,    98,    99,    73,    74,    75,
      20,    21,    22,    23,    24,    25,    50,    55,    26,    56,
      84,   105,   106,   107,   108,    77,    78,    79,    26,    65,
      80,    81,   122,    91,    82,    95,    96,   100,   121,   101,
     102,   103,   113,   126,   128,   127,   131,   132,   123,   120,
     112,     0,   124,   104,     0,     0,     0,    97
};

static const yytype_int8 yycheck[] =
{
      34,    31,    35,    51,    11,     8,    37,     7,    53,     7,
      41,    18,    19,    47,     7,    25,    26,     6,    31,    12,
       9,    55,    56,    16,     6,    18,    36,     9,    21,    22,
       0,    24,     5,     6,     7,     8,     9,    25,    26,    87,
      43,    89,    90,    88,    33,    34,    25,    26,    41,     3,
       4,    33,    32,    32,    25,    26,    36,    11,    31,    45,
      33,    91,     6,    96,    35,    70,    71,    38,    39,    40,
      25,    26,    27,    28,    29,    30,    41,    35,    33,    35,
     114,    77,    78,    79,    80,    28,    29,    30,    33,    42,
      27,    17,    42,    34,    36,    34,    36,    35,    31,    35,
      35,    35,    32,     6,     6,    36,     6,    32,   114,    96,
      82,    -1,    44,    76,    -1,    -1,    -1,    69
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    12,    16,    18,    21,    22,    24,    48,    51,
      52,    57,    58,    60,    64,    65,    66,    68,    78,    79,
      25,    26,    27,    28,    29,    30,    33,    50,    71,     5,
       6,     7,     8,     9,    31,    33,    49,    61,    69,    72,
      74,    75,    76,    77,     7,     7,    67,    31,     0,    45,
      41,    54,    54,    54,     6,    35,    35,    50,    74,     6,
       9,    34,    61,    62,    63,    42,     3,     4,    11,    70,
      25,    26,    35,    38,    39,    40,    73,    28,    29,    30,
      27,    17,    36,    59,    74,    51,    37,    53,    54,    55,
      53,    34,    74,    74,    32,    34,    36,    69,    75,    75,
      35,    35,    35,    35,    72,    76,    76,    76,    76,     8,
      43,    80,    67,    32,    36,    51,    53,    51,    51,    50,
      62,    31,    42,    59,    44,    56,     6,    36,     6,    32,
      36,     6,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    49,    49,    50,    50,
      51,    51,    51,    52,    52,    53,    53,    54,    55,    56,
      57,    57,    57,    57,    57,    57,    57,    58,    59,    59,
      60,    61,    61,    62,    62,    63,    63,    63,    64,    65,
      66,    67,    67,    68,    69,    69,    70,    70,    70,    71,
      71,    71,    71,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    75,    75,    75,    75,
      76,    76,    77,    77,    77,    78,    79,    80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     4,     0,
       3,     1,     0,     4,     4,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     3,     1,
       4,     3,     2,     3,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     2,
       2,     2,     2,     3,     3,     1,     3,     3,     3,     1,
       3,     1,     3,     1,     2,     3,     5,     6,     8,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 89 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    { printtree((yyvsp[-1].data.res)); printf("\n"); YYACCEPT;}
#line 1427 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 91 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.val_type) = int_type; (yyval.data.numval) = (yyvsp[0].data.numval); char snum[10]; sprintf(snum, "%f", (yyvsp[0].data.numval)); 	 (yyval.data.res)=mknode(0,0,snum); }
#line 1433 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 92 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.val_type) = float_type; (yyval.data.numval) = (yyvsp[0].data.numval); char snum[10]; sprintf(snum, "%f",(yyvsp[0].data.numval));  (yyval.data.res)=mknode(0,0,snum); }
#line 1439 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 93 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.val_type) = string_type; strcpy((yyval.data.sval),(yyvsp[0].data.sval));  (yyval.data.res)=mknode(0,0,(yyvsp[0].data.sval)); }
#line 1445 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 94 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.val_type) = bool_type; (yyval.data.numval) = (yyvsp[0].data.numval); char snum[10]; sprintf(snum, "%f",(yyvsp[0].data.numval)); (yyval.data.res)=mknode(0,0,snum);  }
#line 1451 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 95 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.val_type) = list_type; strcpy((yyval.data.sval),(yyvsp[0].data.sval)); (yyval.data.res)=mknode(0,0,(yyval.data.sval)); }
#line 1457 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 97 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {sprintf((yyval.data.sval),"%d %s", (int)(yyvsp[-2].data.numval), (yyvsp[0].data.sval)); sprintf((yyval.data.idval),"[%d]%s", (int)(yyvsp[-2].data.numval), (yyvsp[0].data.idval));}
#line 1463 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 98 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {strcpy((yyval.data.sval), ""); strcpy((yyval.data.idval), "");}
#line 1469 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 100 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    { (yyval.data.res)=mknode((yyvsp[-2].data.res),(yyvsp[0].data.res),"seq");}
#line 1475 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 101 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    { (yyval.data.res)=(yyvsp[0].data.res); }
#line 1481 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 102 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=NULL;}
#line 1487 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 104 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=mknode((yyvsp[-3].data.res),(yyvsp[-1].data.res),"while");}
#line 1493 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 105 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    { node * newnode=mknode(0,0,"for"); newnode->child=(yyvsp[-3].data.res); newnode->child->next->next->next=(yyvsp[-1].data.res); (yyval.data.res)=newnode;  }
#line 1499 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 107 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=(yyvsp[-1].data.res);}
#line 1505 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 108 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=(yyvsp[0].data.res);}
#line 1511 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 110 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {curr_line++;}
#line 1517 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 112 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {current_scope = create_scope(current_scope);}
#line 1523 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 114 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {current_scope = exit_scope(current_scope);}
#line 1529 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 117 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=(yyvsp[0].data.res);}
#line 1535 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 118 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=(yyvsp[0].data.res);}
#line 1541 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 119 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=(yyvsp[0].data.res);}
#line 1547 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 120 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=(yyvsp[0].data.res);}
#line 1553 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 121 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=(yyvsp[0].data.res);}
#line 1559 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 122 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=(yyvsp[0].data.res);}
#line 1565 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 125 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=mknode((yyvsp[-1].data.res),0,"print");}
#line 1571 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 130 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {if((yyvsp[0].data.val_type)==string_type || (yyvsp[0].data.val_type)==list_type){add_variable(current_scope, (yyvsp[-3].data.idval), (yyvsp[0].data.val_type), curr_line, (void*)(((yyvsp[0].data.sval)))); } else{add_variable(current_scope, (yyvsp[-3].data.idval), (yyvsp[0].data.val_type), curr_line, (void*)(&((yyvsp[0].data.numval))));}  sprintf((yyval.data.idval), "%s%s", (yyvsp[-3].data.idval), (yyvsp[-2].data.idval)); (yyval.data.res)=mknode(mknode(0,0,(yyval.data.idval)),(yyvsp[0].data.res),"Assign"); }
#line 1577 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 133 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {sprintf((yyval.data.sval), "[%s]", (yyvsp[-1].data.sval)); (yyval.data.val_type)=list_type;  }
#line 1583 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 134 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {sprintf((yyval.data.sval), "[]"); (yyval.data.val_type)=list_type;}
#line 1589 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 136 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {sprintf((yyval.data.sval), "%s %s", (yyvsp[-2].data.sval), (yyvsp[0].data.sval));}
#line 1595 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 137 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {sprintf((yyval.data.sval), "%s", (yyvsp[0].data.sval));}
#line 1601 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 139 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {sprintf((yyval.data.sval), "%d", (int)(yyvsp[0].data.numval));}
#line 1607 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 140 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {sprintf((yyval.data.sval), "%f", (float)(yyvsp[0].data.numval));}
#line 1613 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 141 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {sprintf((yyval.data.sval), "%s", (yyvsp[0].data.sval));}
#line 1619 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 143 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=mknode(0,0,"break");}
#line 1625 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 145 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=mknode(0,0,"continue");}
#line 1631 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 147 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=(yyvsp[0].data.res);}
#line 1637 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 149 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=mknode((yyvsp[-2].data.res),(yyvsp[0].data.res),"import");}
#line 1643 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 150 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=mknode(0,0,(char*)yylval.data.idval);}
#line 1649 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 154 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=mknode((yyvsp[-2].data.res),(yyvsp[0].data.res),(yyvsp[-1].data.idval));}
#line 1655 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 155 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.res)=(yyvsp[0].data.res);}
#line 1661 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 156 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {strcpy((yyval.data.idval),(yyvsp[0].data.idval));}
#line 1667 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 157 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {strcpy((yyval.data.idval),(yyvsp[0].data.idval));}
#line 1673 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 158 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {strcpy((yyval.data.idval),(yyvsp[0].data.idval));}
#line 1679 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 167 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    { (yyval.data.res)=mknode((yyvsp[-2].data.res),(yyvsp[0].data.res),(yyvsp[-1].data.idval));  }
#line 1685 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 168 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    { (yyval.data.res)=(yyvsp[0].data.res);  }
#line 1691 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 171 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    { strcpy((yyval.data.idval),(yyvsp[0].data.idval)); }
#line 1697 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 172 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {strcpy((yyval.data.idval),(yyvsp[0].data.idval)); }
#line 1703 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 173 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    { strcpy((yyval.data.idval),(yyvsp[-1].data.idval)); strcat((yyval.data.idval),(yyvsp[-1].data.idval));}
#line 1709 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 174 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    { strcpy((yyval.data.idval),(yyvsp[-1].data.idval)); strcat((yyval.data.idval),(yyvsp[-1].data.idval));}
#line 1715 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 175 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    { strcpy((yyval.data.idval),(yyvsp[-1].data.idval)); strcat((yyval.data.idval),(yyvsp[-1].data.idval));}
#line 1721 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 176 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    { strcpy((yyval.data.idval),(yyvsp[-1].data.idval)); strcat((yyval.data.idval),(yyvsp[-1].data.idval));}
#line 1727 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 178 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {int flag = (yyvsp[-2].data.val_type)*10+(yyvsp[0].data.val_type); if((yyvsp[-2].data.val_type)==4 || (yyvsp[-2].data.val_type)==5 || (yyvsp[0].data.val_type)==4 || (yyvsp[0].data.val_type)==5) error(8, flag, NULL); switch(flag){case 22: strcpy((yyval.data.sval), strcat((yyvsp[-2].data.sval), (yyvsp[0].data.sval))); (yyval.data.val_type) = string_type; break; case 20: case 21: case 23: case 2: case 12: case 32: error(8, flag, NULL); break; default: (yyval.data.numval) = (yyvsp[-2].data.numval)+(yyvsp[0].data.numval); if(flag==0 || flag==30 || flag==3 || flag==33) (yyval.data.val_type) = int_type; else (yyval.data.val_type) = float_type;} (yyval.data.res)=mknode((yyvsp[-2].data.res),(yyvsp[0].data.res),"+"); }
#line 1733 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 179 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {int flag = (yyvsp[-2].data.val_type)*10+(yyvsp[0].data.val_type); if((yyvsp[-2].data.val_type)==4 || (yyvsp[-2].data.val_type)==5 || (yyvsp[0].data.val_type)==4 || (yyvsp[0].data.val_type)==5) error(7, flag, NULL); switch(flag){case 20: case 21: case 22: case 23: case 2: case 12: case 32: error(7, flag, NULL); break; default: (yyval.data.numval) = (yyvsp[-2].data.numval)-(yyvsp[0].data.numval); if(flag==0 || flag==30 || flag==3 || flag==33) (yyval.data.val_type) = int_type; else (yyval.data.val_type) = float_type;} (yyval.data.res)=mknode((yyvsp[-2].data.res),(yyvsp[0].data.res),"-"); }
#line 1739 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 180 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.val_type) = (yyvsp[0].data.val_type); switch((yyval.data.val_type)){ case int_type: case float_type: case bool_type: (yyval.data.numval) = (yyvsp[0].data.numval); break; case string_type: strcpy((yyval.data.sval), (yyvsp[0].data.sval)); break;} (yyval.data.res)=(yyvsp[0].data.res); }
#line 1745 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 183 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {int flag = (yyvsp[-2].data.val_type)*10+(yyvsp[0].data.val_type); if((yyvsp[-2].data.val_type)==4 || (yyvsp[-2].data.val_type)==5 || (yyvsp[0].data.val_type)==4 || (yyvsp[0].data.val_type)==5) error(5, flag, NULL); switch(flag){case 12: case 21: case 22: error(5, flag, NULL); break; case 20: case 23: case 2: case 32:  error(5, flag, NULL);break; default: (yyval.data.numval) = (yyvsp[-2].data.numval)*(yyvsp[0].data.numval); if(flag==0 || flag==30 || flag==3) (yyval.data.val_type) = int_type; else (yyval.data.val_type) = float_type;} (yyval.data.res)=mknode((yyvsp[-2].data.res),(yyvsp[0].data.res),"*"); }
#line 1751 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 184 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {int flag = (yyvsp[-2].data.val_type)*10+(yyvsp[0].data.val_type); if((yyvsp[-2].data.val_type)==4 || (yyvsp[-2].data.val_type)==5 || (yyvsp[0].data.val_type)==4 || (yyvsp[0].data.val_type)==5) error(4, flag, NULL); switch(flag){case 20: case 21: case 22: case 23: case 2: case 12: case 32:  error(4, flag, NULL); break; default: if((yyvsp[0].data.numval)==0) error(3, 0, NULL); (yyval.data.numval) = (yyvsp[-2].data.numval)/(yyvsp[0].data.numval); (yyval.data.val_type) = float_type;} (yyval.data.res)=mknode((yyvsp[-2].data.res),(yyvsp[0].data.res),"/"); }
#line 1757 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 185 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {int flag = (yyvsp[-2].data.val_type)*10+(yyvsp[0].data.val_type); if((yyvsp[-2].data.val_type)==4 || (yyvsp[-2].data.val_type)==5 || (yyvsp[0].data.val_type)==4 || (yyvsp[0].data.val_type)==5) error(2, flag, NULL); switch(flag){case 20: case 21: case 22: case 23: case 2: case 12: case 32: case 1: case 10: case 11: case 13: case 31: error(2, flag, NULL); break; default: if((yyvsp[0].data.numval)==0) error(2, 0, NULL); (yyval.data.numval) = (int)(yyvsp[-2].data.numval)%(int)(yyvsp[0].data.numval); (yyval.data.val_type) = int_type;} (yyval.data.res)=mknode((yyvsp[-2].data.res),(yyvsp[0].data.res),"%"); }
#line 1763 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 186 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.val_type) = (yyvsp[0].data.val_type); switch((yyval.data.val_type)){ case int_type: case float_type: case bool_type: (yyval.data.numval) = (yyvsp[0].data.numval); break; case string_type: strcpy((yyval.data.sval), (yyvsp[0].data.sval)); break;} (yyval.data.res)=(yyvsp[0].data.res); }
#line 1769 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 188 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {int flag = (yyvsp[-2].data.val_type)*10+(yyvsp[0].data.val_type); if((yyvsp[-2].data.val_type)==4 || (yyvsp[-2].data.val_type)==5 || (yyvsp[0].data.val_type)==4 || (yyvsp[0].data.val_type)==5) error(1, flag, NULL); switch(flag){case 20: case 21: case 22: case 23: case 2: case 12: case 32: error(1, flag, NULL); break; default: (yyval.data.numval) = pow((yyvsp[-2].data.numval), (yyvsp[0].data.numval)); if(flag==0 || flag==30 || flag==3 || flag==33) (yyval.data.val_type) = int_type; else (yyval.data.val_type) = float_type;} (yyval.data.res)=mknode((yyvsp[-2].data.res),(yyvsp[0].data.res),"**"); }
#line 1775 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 189 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.val_type) = (yyvsp[0].data.val_type); switch((yyval.data.val_type)){ case int_type: case float_type: case bool_type: (yyval.data.numval) = (yyvsp[0].data.numval); break; case string_type: strcpy((yyval.data.sval), (yyvsp[0].data.sval)); break;} (yyval.data.res)=(yyvsp[0].data.res); }
#line 1781 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 191 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {(yyval.data.val_type) = (yyvsp[-1].data.val_type); switch((yyval.data.val_type)){ case int_type: case float_type: case bool_type: (yyval.data.numval) = (yyvsp[-1].data.numval); break; case string_type: strcpy((yyval.data.sval), (yyvsp[-1].data.sval)); break;} (yyval.data.res)=(yyvsp[-1].data.res); }
#line 1787 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 192 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    { (yyval.data.val_type) = (yyvsp[0].data.val_type); switch((yyval.data.val_type)){ case int_type: case float_type: case bool_type: (yyval.data.numval) = (yyvsp[0].data.numval); break; case string_type: strcpy((yyval.data.sval), (yyvsp[0].data.sval)); break;} (yyval.data.res)=(yyvsp[0].data.res); }
#line 1793 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 193 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    { struct datatype *temp=lookup(current_scope,(yyvsp[-1].data.idval), (yyvsp[0].data.sval)); if(temp!=NULL){if(temp->val_type<0){error(temp->val_type+11,0, (yyvsp[-1].data.idval));}(yyval.data.val_type)=temp->val_type; if(temp->val_type==int_type|| temp->val_type==float_type || temp->val_type==bool_type)(yyval.data.numval)=temp->numval; else {strcpy((yyval.data.sval), temp->sval);}} else{ error(6,0,(yyvsp[-1].data.idval)); } if(strcmp((yyvsp[0].data.sval),"")==0){ char snum[10]; strcpy(snum,(yyvsp[-1].data.idval));  (yyval.data.res)=mknode(0,0,snum); } else {char snum[10]; strcpy(snum,(yyvsp[-1].data.idval)); strcat(snum,"["); strcat(snum,(yyvsp[0].data.sval)); strcat(snum,"]");  (yyval.data.res)=mknode(0,0,snum); } }
#line 1799 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 195 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    { (yyval.data.res)=(yyvsp[-1].data.res); }
#line 1805 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 198 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {add_variable(current_scope, (yyvsp[-3].data.idval), int_type, curr_line, (void*)(&temp)); 
																						//node *newnode = (node *)malloc(sizeof(node));
																						node * newnode=mknode(0,0,(yyvsp[-3].data.idval));
																						newnode->next=mknode(0,0,"in");
																						//printf(" %s ",newnode->next->token);
																						newnode->next->next=(yyvsp[-1].data.res);
																						
																						//printf(" %s ",newnode->next->next->token);
																						(yyval.data.res)=newnode;
																						}
#line 1820 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 209 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {  char snum[10]; sprintf(snum, "%f", (yyvsp[-3].data.numval)); char snum2[10]; sprintf(snum2, "%f", (yyvsp[-1].data.numval)); 	 (yyval.data.res)=mknode(mknode(0,0,snum),mknode(0,0,snum2),"range");  }
#line 1826 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 210 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    {  (yyvsp[-3].data.res)->next=(yyvsp[-1].data.res); (yyval.data.res)=mknode((yyvsp[-5].data.res),(yyvsp[-3].data.res),"rangewithstep" ); }
#line 1832 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 211 "./SyntaxTree/yfile.y" /* yacc.c:1646  */
    { (yyval.data.res)=(yyvsp[0].data.res); }
#line 1838 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
    break;


#line 1842 "./SyntaxTree/y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 215 "./SyntaxTree/yfile.y" /* yacc.c:1906  */


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


