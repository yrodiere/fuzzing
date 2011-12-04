
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "rutc_yacc.y"

/*
 	Copyright (C) 2008 - 2009 by Lynus Vaz, Durgesh Samant
	lynusvaz@gmail.com
	This file is part of rutc

	rutc is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <setjmp.h>

#include "rutc.h"

void yyerror(char *s)
{
fprintf(stderr,"%s\n",s);
return;
}

int yywrap()
{
	return 1;
}

struct variable *var_head = NULL;
struct variable *local_var_head = NULL;
int num_func;
struct function *func_head = NULL;

int id_num;



/* Line 189 of yacc.c  */
#line 124 "rutc_yacc.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     INTEGER = 259,
     DOUBLE = 260,
     IDIV = 261,
     SQRT = 262,
     SIN = 263,
     COS = 264,
     TAN = 265,
     ASIN = 266,
     ACOS = 267,
     ATAN = 268,
     EXP = 269,
     SINH = 270,
     COSH = 271,
     TANH = 272,
     ASINH = 273,
     ACOSH = 274,
     ATANH = 275,
     LOG = 276,
     LN = 277,
     INT = 278,
     SOLVE = 279,
     QUIT = 280,
     HELP = 281,
     WARRANTY = 282,
     IF = 283,
     ELSE = 284,
     WHILE = 285,
     FOR = 286,
     ASSIGN_OP = 287,
     INCR_DECR = 288,
     REL_OP = 289,
     REL_OP_EQ = 290,
     BIT_OP = 291,
     AND = 292,
     OR = 293,
     COMBO = 294,
     PERM = 295,
     ARG = 296,
     REAL = 297,
     IMAG = 298,
     CONJ = 299,
     STAT = 300,
     ENDSTAT = 301,
     OB_SET = 302,
     FUNC = 303,
     UNARY = 304
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INTEGER 259
#define DOUBLE 260
#define IDIV 261
#define SQRT 262
#define SIN 263
#define COS 264
#define TAN 265
#define ASIN 266
#define ACOS 267
#define ATAN 268
#define EXP 269
#define SINH 270
#define COSH 271
#define TANH 272
#define ASINH 273
#define ACOSH 274
#define ATANH 275
#define LOG 276
#define LN 277
#define INT 278
#define SOLVE 279
#define QUIT 280
#define HELP 281
#define WARRANTY 282
#define IF 283
#define ELSE 284
#define WHILE 285
#define FOR 286
#define ASSIGN_OP 287
#define INCR_DECR 288
#define REL_OP 289
#define REL_OP_EQ 290
#define BIT_OP 291
#define AND 292
#define OR 293
#define COMBO 294
#define PERM 295
#define ARG 296
#define REAL 297
#define IMAG 298
#define CONJ 299
#define STAT 300
#define ENDSTAT 301
#define OB_SET 302
#define FUNC 303
#define UNARY 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 52 "rutc_yacc.y"
int ival; double dval; char *idval; struct statement *sval; struct expr *eval; struct ob_list *obval; struct var_name_list *fval; 


/* Line 214 of yacc.c  */
#line 262 "rutc_yacc.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 274 "rutc_yacc.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1414

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  233

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      59,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,    56,     2,     2,
      66,    67,    54,    53,    63,    52,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    68,
       2,    60,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,    70,    62,     2,     2,     2,     2,
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
      45,    46,    47,    48,    58
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    13,    16,    19,    22,
      28,    32,    33,    39,    41,    43,    47,    49,    53,    55,
      59,    62,    64,    66,    71,    75,    78,    80,    84,    88,
      96,    99,   105,   113,   119,   129,   133,   134,   136,   138,
     140,   143,   146,   150,   154,   158,   162,   166,   170,   174,
     178,   182,   185,   189,   193,   197,   199,   202,   205,   207,
     211,   219,   224,   229,   233,   238,   243,   248,   253,   258,
     263,   268,   273,   277,   281,   287,   292,   297,   302,   307,
     312,   317,   322,   327,   332,   337,   342
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      72,     0,    -1,    72,    73,    -1,    -1,    81,    59,    -1,
      26,    59,    -1,    27,    59,    -1,    25,    59,    -1,     1,
      59,    -1,    45,    59,    74,    46,    59,    -1,    75,    59,
      74,    -1,    -1,    47,    60,    61,    76,    62,    -1,    81,
      -1,    84,    -1,    84,    63,    76,    -1,     3,    -1,     3,
      63,    77,    -1,    84,    -1,    84,    63,    78,    -1,    59,
      79,    -1,    59,    -1,     3,    -1,     3,    64,    84,    65,
      -1,    61,    82,    62,    -1,    79,    81,    -1,    84,    -1,
      80,    32,    84,    -1,    80,    60,    84,    -1,    48,     3,
      66,    77,    67,    60,    84,    -1,    24,     4,    -1,    28,
      66,    84,    67,    81,    -1,    28,    66,    84,    67,    81,
      29,    81,    -1,    30,    66,    84,    67,    81,    -1,    31,
      66,    81,    68,    84,    68,    81,    67,    81,    -1,    81,
      59,    82,    -1,    -1,     4,    -1,     5,    -1,    69,    -1,
      52,    84,    -1,    53,    84,    -1,    84,    53,    84,    -1,
      84,    52,    84,    -1,    84,    54,    84,    -1,    84,    55,
      84,    -1,    84,    57,    84,    -1,    84,     6,    84,    -1,
      84,    56,    84,    -1,    84,    34,    84,    -1,    84,    35,
      84,    -1,    51,    84,    -1,    84,    37,    84,    -1,    84,
      38,    84,    -1,    84,    36,    84,    -1,    80,    -1,    33,
      80,    -1,    80,    33,    -1,    83,    -1,    66,    84,    67,
      -1,    66,    61,    82,    62,    63,    84,    67,    -1,     3,
      66,    78,    67,    -1,    23,    66,    84,    67,    -1,    70,
      84,    70,    -1,    41,    66,    84,    67,    -1,    42,    66,
      84,    67,    -1,    43,    66,    84,    67,    -1,    44,    66,
      84,    67,    -1,     7,    66,    84,    67,    -1,    14,    66,
      84,    67,    -1,    21,    66,    84,    67,    -1,    22,    66,
      84,    67,    -1,    84,    39,    84,    -1,    84,    40,    84,
      -1,    84,    49,    84,    50,    84,    -1,     8,    66,    84,
      67,    -1,     9,    66,    84,    67,    -1,    10,    66,    84,
      67,    -1,    15,    66,    84,    67,    -1,    16,    66,    84,
      67,    -1,    17,    66,    84,    67,    -1,    11,    66,    84,
      67,    -1,    12,    66,    84,    67,    -1,    13,    66,    84,
      67,    -1,    18,    66,    84,    67,    -1,    19,    66,    84,
      67,    -1,    20,    66,    84,    67,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   101,   105,   106,   107,   108,   109,   110,
     114,   115,   117,   129,   132,   138,   144,   152,   160,   163,
     168,   169,   171,   179,   185,   186,   187,   189,   196,   204,
     209,   220,   227,   234,   240,   252,   260,   264,   266,   268,
     271,   275,   277,   281,   286,   290,   294,   298,   302,   308,
     312,   318,   322,   326,   331,   337,   341,   345,   350,   351,
     353,   359,   366,   372,   377,   382,   387,   392,   398,   403,
     408,   413,   420,   424,   429,   438,   443,   448,   453,   457,
     461,   466,   471,   476,   481,   485,   489
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTEGER", "DOUBLE",
  "IDIV", "SQRT", "SIN", "COS", "TAN", "ASIN", "ACOS", "ATAN", "EXP",
  "SINH", "COSH", "TANH", "ASINH", "ACOSH", "ATANH", "LOG", "LN", "INT",
  "SOLVE", "QUIT", "HELP", "WARRANTY", "IF", "ELSE", "WHILE", "FOR",
  "ASSIGN_OP", "INCR_DECR", "REL_OP", "REL_OP_EQ", "BIT_OP", "AND", "OR",
  "COMBO", "PERM", "ARG", "REAL", "IMAG", "CONJ", "STAT", "ENDSTAT",
  "OB_SET", "FUNC", "'?'", "':'", "'!'", "'-'", "'+'", "'*'", "'/'", "'%'",
  "'^'", "UNARY", "'\\n'", "'='", "'{'", "'}'", "','", "'['", "']'", "'('",
  "')'", "';'", "'I'", "'|'", "$accept", "LINES", "LINE", "STAT_LINES",
  "OB_LINE", "OB_LIST", "ID_LIST", "EXPR_LIST", "E", "VARIABLE",
  "EXEC_STATEMENT", "ST_LIST", "NUMBER", "EXPR", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    63,
      58,    33,    45,    43,    42,    47,    37,    94,   304,    10,
      61,   123,   125,    44,    91,    93,    40,    41,    59,    73,
     124
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      79,    79,    80,    80,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    82,    82,    83,    83,    83,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     2,     2,     2,     5,
       3,     0,     5,     1,     1,     3,     1,     3,     1,     3,
       2,     1,     1,     4,     3,     2,     1,     3,     3,     7,
       2,     5,     7,     5,     9,     3,     0,     1,     1,     1,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     1,     2,     2,     1,     3,
       7,     4,     4,     3,     4,     4,     4,     4,     4,     4,
       4,     4,     3,     3,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    22,    37,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    36,     0,    39,     0,     2,     0,    55,     0,
      58,    26,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,     7,     5,     6,     0,     0,     0,    22,
      56,     0,     0,     0,     0,    11,     0,    55,    51,    40,
      41,    20,     0,     0,    36,     0,     0,    25,     0,    57,
       0,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,     0,    36,
      24,     0,    59,    63,    27,    28,    47,    49,    50,    54,
      52,    53,    72,    73,     0,    43,    42,    44,    45,    48,
      46,    23,    61,     0,    68,    75,    76,    77,    81,    82,
      83,    69,    78,    79,    80,    84,    85,    86,    70,    71,
      62,     0,     0,     0,    64,    65,    66,    67,     0,     0,
      11,    16,     0,    35,     0,     0,    19,    31,    33,     0,
       0,     9,    10,     0,     0,     0,    74,     0,     0,     0,
      14,    17,     0,     0,    32,     0,    12,     0,    29,    60,
       0,    15,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    46,   145,   146,   219,   202,   118,    47,    87,
      92,    93,    50,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -94
static const yytype_int16 yypact[] =
{
     -94,   274,   -94,   -45,   -51,   -94,   -94,   -48,   -47,   -46,
     -44,   -43,   -41,   -40,   -39,   -38,   -37,   -35,   -24,   -17,
      -4,    -3,     0,     3,    17,   -14,     5,     6,     7,     8,
       9,    64,    10,    12,    14,    15,    11,    68,   546,   546,
     546,    13,   410,   478,   -94,   546,   -94,   410,   -21,    23,
     -94,  1322,   -94,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   -94,   -94,   -94,   -94,   546,   546,   410,    19,
     -94,   546,   546,   546,   546,   342,    24,    52,  1254,   -94,
     -94,   -94,    32,    33,   410,   171,    -2,   -94,   546,   -94,
     546,   -94,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,  1192,    29,  1228,
     568,   594,   620,   646,   672,   698,   724,   750,   776,   802,
     828,   854,   880,   906,   932,   958,   984,  1010,  1036,    30,
    1062,  1088,  1114,  1140,    37,    53,    41,   -94,    98,   410,
     -94,    59,   -94,   -94,  1322,  1322,   -33,   196,   196,   -23,
    1254,  1219,   -94,   -94,  1298,     4,   140,   468,   -33,   -33,
     -31,   -94,   -94,   546,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   410,   410,   546,   -94,   -94,   -94,   -94,    61,    65,
     342,    60,    62,   -94,    71,   546,   -94,    99,   -94,   132,
     546,   -94,   -94,    98,    67,   546,  1357,   410,   410,    73,
    1263,   -94,   546,  1166,   -94,    69,   -94,   546,  1322,   -94,
     410,   -94,   -94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   -94,   -63,   -94,   -88,   -73,   -32,   101,    -1,
       1,   -93,   -94,    49
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      48,   151,    49,   105,   102,   105,   108,   109,   108,   109,
     102,    98,    99,    53,    52,    54,   108,   109,    55,    56,
      57,    72,    58,    59,   116,    60,    61,    62,    63,    64,
      80,    65,   103,   104,   105,   106,   107,   108,   109,   100,
     105,    48,    66,   108,   109,    73,    48,   110,    97,    67,
     111,   112,   113,   114,   115,   116,   203,   112,   113,   114,
     115,   116,    68,    69,    74,    75,    70,    79,   153,    71,
      85,    86,    41,    76,    77,    78,    81,    48,    82,   139,
      83,    84,   101,    53,    48,    99,   147,    88,    89,    90,
     148,   149,    95,    48,    96,   150,   172,   198,   193,   199,
     200,   201,   117,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   204,   210,   213,   211,   137,   138,   222,   217,   214,
     140,   141,   142,   143,   215,   226,   230,   212,   102,   231,
     221,   206,    91,     0,     0,     0,   102,   154,    48,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   103,   104,   105,   106,
     107,   108,   109,     0,     0,     0,   105,   102,     0,   108,
     109,   110,     0,     0,   111,   112,   113,   114,   115,   116,
      48,    48,   207,   208,   113,   114,   115,   116,     0,    48,
     218,   147,   102,     0,     0,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,     0,    48,    48,   224,   225,
     110,     0,   119,   111,   112,   113,   114,   115,   116,    48,
       0,   232,   105,     0,     0,   108,   109,     0,   152,     0,
       0,     0,   209,     0,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   216,     0,     0,     0,     0,   220,
       0,     0,     0,     0,   223,     0,     0,     0,     0,     0,
       0,   228,     0,     0,     2,     3,   220,     4,     5,     6,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,    29,    30,     0,    31,     0,     0,
       0,     0,     0,     0,     0,    32,    33,    34,    35,    36,
       0,     0,    37,     0,     0,    38,    39,    40,     0,     0,
       0,     0,     0,    41,     0,    42,     0,     0,     0,     0,
      43,     0,     0,    44,    45,     4,     5,     6,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,     0,     0,
      28,     0,    29,    30,     0,    31,     0,     0,     0,     0,
       0,     0,     0,    32,    33,    34,    35,     0,     0,   144,
      37,     0,     0,    38,    39,    40,     0,     0,     0,     0,
       0,    41,     0,    42,     0,     0,     0,     0,    43,     0,
       0,    44,    45,     4,     5,     6,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,     0,     0,    28,     0,
      29,    30,     0,    31,     0,     0,     0,     0,     0,     0,
       0,    32,    33,    34,    35,     0,     0,     0,    37,     0,
       0,    38,    39,    40,     0,     0,     0,     0,     0,    41,
       0,    42,     0,     0,   102,     0,    43,     0,     0,    44,
      45,     4,     5,     6,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     0,     0,   105,     0,     0,   108,   109,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,    32,
      33,    34,    35,   114,   115,   116,     0,     0,     0,    38,
      39,    40,     0,     0,     0,     0,     0,     0,     0,    94,
       0,     0,     0,     0,    43,     0,     0,    44,    45,     4,
       5,     6,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       0,     0,     0,     0,   102,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,     0,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,    38,    39,    40,
     102,     0,   103,   104,   105,   106,   107,   108,   109,     0,
       0,     0,    43,     0,     0,    44,    45,   110,     0,     0,
     111,   112,   113,   114,   115,   116,   102,     0,   103,   104,
     105,   106,   107,   108,   109,   174,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,   111,   112,   113,   114,
     115,   116,   102,     0,   103,   104,   105,   106,   107,   108,
     109,   175,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,   111,   112,   113,   114,   115,   116,   102,     0,
     103,   104,   105,   106,   107,   108,   109,   176,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,   111,   112,
     113,   114,   115,   116,   102,     0,   103,   104,   105,   106,
     107,   108,   109,   177,     0,     0,     0,     0,     0,     0,
       0,   110,     0,     0,   111,   112,   113,   114,   115,   116,
     102,     0,   103,   104,   105,   106,   107,   108,   109,   178,
       0,     0,     0,     0,     0,     0,     0,   110,     0,     0,
     111,   112,   113,   114,   115,   116,   102,     0,   103,   104,
     105,   106,   107,   108,   109,   179,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,   111,   112,   113,   114,
     115,   116,   102,     0,   103,   104,   105,   106,   107,   108,
     109,   180,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,   111,   112,   113,   114,   115,   116,   102,     0,
     103,   104,   105,   106,   107,   108,   109,   181,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,   111,   112,
     113,   114,   115,   116,   102,     0,   103,   104,   105,   106,
     107,   108,   109,   182,     0,     0,     0,     0,     0,     0,
       0,   110,     0,     0,   111,   112,   113,   114,   115,   116,
     102,     0,   103,   104,   105,   106,   107,   108,   109,   183,
       0,     0,     0,     0,     0,     0,     0,   110,     0,     0,
     111,   112,   113,   114,   115,   116,   102,     0,   103,   104,
     105,   106,   107,   108,   109,   184,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,   111,   112,   113,   114,
     115,   116,   102,     0,   103,   104,   105,   106,   107,   108,
     109,   185,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,   111,   112,   113,   114,   115,   116,   102,     0,
     103,   104,   105,   106,   107,   108,   109,   186,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,   111,   112,
     113,   114,   115,   116,   102,     0,   103,   104,   105,   106,
     107,   108,   109,   187,     0,     0,     0,     0,     0,     0,
       0,   110,     0,     0,   111,   112,   113,   114,   115,   116,
     102,     0,   103,   104,   105,   106,   107,   108,   109,   188,
       0,     0,     0,     0,     0,     0,     0,   110,     0,     0,
     111,   112,   113,   114,   115,   116,   102,     0,   103,   104,
     105,   106,   107,   108,   109,   189,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,   111,   112,   113,   114,
     115,   116,   102,     0,   103,   104,   105,   106,   107,   108,
     109,   190,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,   111,   112,   113,   114,   115,   116,   102,     0,
     103,   104,   105,   106,   107,   108,   109,   191,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,   111,   112,
     113,   114,   115,   116,   102,     0,   103,   104,   105,   106,
     107,   108,   109,   192,     0,     0,     0,     0,     0,     0,
       0,   110,     0,     0,   111,   112,   113,   114,   115,   116,
     102,     0,   103,   104,   105,   106,   107,   108,   109,   194,
       0,     0,     0,     0,     0,     0,     0,   110,     0,     0,
     111,   112,   113,   114,   115,   116,   102,     0,   103,   104,
     105,   106,   107,   108,   109,   195,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,   111,   112,   113,   114,
     115,   116,   102,     0,   103,   104,   105,   106,   107,   108,
     109,   196,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,   111,   112,   113,   114,   115,   116,   102,     0,
     103,   104,   105,   106,   107,   108,   109,   197,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,   111,   112,
     113,   114,   115,   116,     0,   102,   103,   104,   105,   106,
     107,   108,   109,   229,   102,     0,     0,     0,     0,     0,
       0,   110,     0,     0,   111,   112,   113,   114,   115,   116,
       0,     0,     0,   103,   104,   105,   106,   171,   108,   109,
     102,     0,   103,   104,   105,   106,   107,   108,   109,   102,
       0,   111,   112,   113,   114,   115,   116,   110,     0,     0,
     111,   112,   113,   114,   115,   116,     0,     0,   103,   104,
     105,   173,     0,   108,   109,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   102,     0,   111,   112,   113,   114,
     115,   116,   110,     0,     0,   111,   112,   113,   114,   115,
     116,     0,     0,     0,     0,     0,   227,     0,   102,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   109,     0,
       0,     0,     0,     0,     0,     0,     0,   110,   205,     0,
     111,   112,   113,   114,   115,   116,   103,   104,   105,   106,
     107,   108,   109,   102,     0,     0,     0,     0,     0,     0,
       0,   110,     0,     0,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116
};

static const yytype_int16 yycheck[] =
{
       1,    94,     1,    36,     6,    36,    39,    40,    39,    40,
       6,    32,    33,    64,    59,    66,    39,    40,    66,    66,
      66,     4,    66,    66,    57,    66,    66,    66,    66,    66,
      31,    66,    34,    35,    36,    37,    38,    39,    40,    60,
      36,    42,    66,    39,    40,    59,    47,    49,    47,    66,
      52,    53,    54,    55,    56,    57,   149,    53,    54,    55,
      56,    57,    66,    66,    59,    59,    66,     3,    70,    66,
      59,     3,    59,    66,    66,    66,    66,    78,    66,    78,
      66,    66,    59,    64,    85,    33,    85,    38,    39,    40,
      66,    59,    43,    94,    45,    62,    67,    60,    68,    46,
      59,     3,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    62,    61,    63,    59,    76,    77,    60,    29,    67,
      81,    82,    83,    84,    63,    62,    67,   200,     6,   227,
     213,   173,    41,    -1,    -1,    -1,     6,    98,   149,   100,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    36,     6,    -1,    39,
      40,    49,    -1,    -1,    52,    53,    54,    55,    56,    57,
     191,   192,   191,   192,    54,    55,    56,    57,    -1,   200,
      68,   200,     6,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,   217,   218,   217,   218,
      49,    -1,   173,    52,    53,    54,    55,    56,    57,   230,
      -1,   230,    36,    -1,    -1,    39,    40,    -1,    67,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,
      -1,   222,    -1,    -1,     0,     1,   227,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    31,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      -1,    -1,    48,    -1,    -1,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    61,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    69,    70,     3,     4,     5,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      28,    -1,    30,    31,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    -1,    -1,    47,
      48,    -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    61,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    69,    70,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,
      30,    31,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    61,    -1,    -1,     6,    -1,    66,    -1,    -1,    69,
      70,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    36,    -1,    -1,    39,    40,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    55,    56,    57,    -1,    -1,    -1,    51,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    69,    70,     3,
       4,     5,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
       6,    -1,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    66,    -1,    -1,    69,    70,    49,    -1,    -1,
      52,    53,    54,    55,    56,    57,     6,    -1,    34,    35,
      36,    37,    38,    39,    40,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,    55,
      56,    57,     6,    -1,    34,    35,    36,    37,    38,    39,
      40,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    54,    55,    56,    57,     6,    -1,
      34,    35,    36,    37,    38,    39,    40,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      54,    55,    56,    57,     6,    -1,    34,    35,    36,    37,
      38,    39,    40,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    54,    55,    56,    57,
       6,    -1,    34,    35,    36,    37,    38,    39,    40,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    54,    55,    56,    57,     6,    -1,    34,    35,
      36,    37,    38,    39,    40,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,    55,
      56,    57,     6,    -1,    34,    35,    36,    37,    38,    39,
      40,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    54,    55,    56,    57,     6,    -1,
      34,    35,    36,    37,    38,    39,    40,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      54,    55,    56,    57,     6,    -1,    34,    35,    36,    37,
      38,    39,    40,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    54,    55,    56,    57,
       6,    -1,    34,    35,    36,    37,    38,    39,    40,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    54,    55,    56,    57,     6,    -1,    34,    35,
      36,    37,    38,    39,    40,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,    55,
      56,    57,     6,    -1,    34,    35,    36,    37,    38,    39,
      40,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    54,    55,    56,    57,     6,    -1,
      34,    35,    36,    37,    38,    39,    40,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      54,    55,    56,    57,     6,    -1,    34,    35,    36,    37,
      38,    39,    40,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    54,    55,    56,    57,
       6,    -1,    34,    35,    36,    37,    38,    39,    40,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    54,    55,    56,    57,     6,    -1,    34,    35,
      36,    37,    38,    39,    40,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,    55,
      56,    57,     6,    -1,    34,    35,    36,    37,    38,    39,
      40,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    54,    55,    56,    57,     6,    -1,
      34,    35,    36,    37,    38,    39,    40,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      54,    55,    56,    57,     6,    -1,    34,    35,    36,    37,
      38,    39,    40,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    54,    55,    56,    57,
       6,    -1,    34,    35,    36,    37,    38,    39,    40,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    54,    55,    56,    57,     6,    -1,    34,    35,
      36,    37,    38,    39,    40,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,    55,
      56,    57,     6,    -1,    34,    35,    36,    37,    38,    39,
      40,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    54,    55,    56,    57,     6,    -1,
      34,    35,    36,    37,    38,    39,    40,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      54,    55,    56,    57,    -1,     6,    34,    35,    36,    37,
      38,    39,    40,    67,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    34,    35,    36,    37,    65,    39,    40,
       6,    -1,    34,    35,    36,    37,    38,    39,    40,     6,
      -1,    52,    53,    54,    55,    56,    57,    49,    -1,    -1,
      52,    53,    54,    55,    56,    57,    -1,    -1,    34,    35,
      36,    63,    -1,    39,    40,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,     6,    -1,    52,    53,    54,    55,
      56,    57,    49,    -1,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    -1,    63,    -1,     6,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      52,    53,    54,    55,    56,    57,    34,    35,    36,    37,
      38,    39,    40,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    72,     0,     1,     3,     4,     5,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    30,
      31,    33,    41,    42,    43,    44,    45,    48,    51,    52,
      53,    59,    61,    66,    69,    70,    73,    79,    80,    81,
      83,    84,    59,    64,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,     4,    59,    59,    59,    66,    66,    66,     3,
      80,    66,    66,    66,    66,    59,     3,    80,    84,    84,
      84,    79,    81,    82,    61,    84,    84,    81,    32,    33,
      60,    59,     6,    34,    35,    36,    37,    38,    39,    40,
      49,    52,    53,    54,    55,    56,    57,    84,    78,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    81,
      84,    84,    84,    84,    47,    74,    75,    81,    66,    59,
      62,    82,    67,    70,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    65,    67,    63,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    67,    67,    67,    67,    60,    46,
      59,     3,    77,    82,    62,    50,    78,    81,    81,    84,
      61,    59,    74,    63,    67,    63,    84,    29,    68,    76,
      84,    77,    60,    84,    81,    81,    62,    63,    84,    67,
      67,    76,    81
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1455 of yacc.c  */
#line 105 "rutc_yacc.y"
    { if((yyvsp[(1) - (2)].sval)) execute_statement((yyvsp[(1) - (2)].sval)); destroy_statement((yyvsp[(1) - (2)].sval));}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 106 "rutc_yacc.y"
    { print_help(); }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 107 "rutc_yacc.y"
    { print_warranty(); }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 108 "rutc_yacc.y"
    { YYACCEPT; }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 117 "rutc_yacc.y"
    {struct value print;
					populate_list((yyvsp[(4) - (5)].obval));
					print=calculate_mean((yyvsp[(4) - (5)].obval));
					printf("\nmean = ");
					print_value(&print);
					print=calculate_sd((yyvsp[(4) - (5)].obval));
					printf("standard deviation = ");
					print_value(&print);
					print=calculate_median((yyvsp[(4) - (5)].obval));
					printf("median = ");
					print_value(&print);
					}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 129 "rutc_yacc.y"
    { if((yyvsp[(1) - (1)].sval)) execute_statement((yyvsp[(1) - (1)].sval)); destroy_statement((yyvsp[(1) - (1)].sval));}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 132 "rutc_yacc.y"
    {
					 (yyval.obval) = create_oblist(); 
					 (yyval.obval)->ob_expr=(yyvsp[(1) - (1)].eval);
					 (yyval.obval)->next=NULL;
					}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 138 "rutc_yacc.y"
    {
					(yyval.obval) = create_oblist();
					(yyval.obval)->ob_expr=(yyvsp[(1) - (3)].eval);
					(yyval.obval)->next=(yyvsp[(3) - (3)].obval);
					}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 144 "rutc_yacc.y"
    {
					(yyval.fval) = malloc(sizeof(struct var_name_list));
					(yyval.fval) -> name = malloc(strlen((yyvsp[(1) - (1)].idval)) + 4);
					sprintf((yyval.fval) -> name, "%s[0]", (yyvsp[(1) - (1)].idval));
					(yyval.fval) -> next = NULL;
					free((yyvsp[(1) - (1)].idval));

					}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 152 "rutc_yacc.y"
    {
					(yyval.fval) = malloc(sizeof(struct var_name_list));
					(yyval.fval) -> name = malloc(strlen((yyvsp[(1) - (3)].idval)) + 4);
					sprintf((yyval.fval) -> name, "%s[0]", (yyvsp[(1) - (3)].idval));
					(yyval.fval) -> next = (yyvsp[(3) - (3)].fval);
					free((yyvsp[(1) - (3)].idval));
					}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 160 "rutc_yacc.y"
    {
					(yyval.eval) = (yyvsp[(1) - (1)].eval);
					}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 163 "rutc_yacc.y"
    {
					(yyval.eval) = (yyvsp[(1) - (3)].eval);
					(yyval.eval) -> next = (yyvsp[(3) - (3)].eval);
					}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 171 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					(yyval.eval) -> type = ID_EXPR;
					(yyval.eval) -> ops.var_op.var = (yyvsp[(1) - (1)].idval);
					(yyval.eval) -> ops.var_op.index = create_expr();
					copy_int_to_expr(0, (yyval.eval) -> ops.var_op.index);
					}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 179 "rutc_yacc.y"
    {					//Array
					(yyval.eval) = create_expr();
					(yyval.eval) -> type = ID_EXPR;
					(yyval.eval) -> ops.var_op.var = (yyvsp[(1) - (4)].idval);
					(yyval.eval) -> ops.var_op.index = (yyvsp[(3) - (4)].eval);
					}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 185 "rutc_yacc.y"
    { (yyval.sval) = (yyvsp[(2) - (3)].sval); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 186 "rutc_yacc.y"
    { (yyval.sval) = (yyvsp[(2) - (2)].sval); }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 187 "rutc_yacc.y"
    { (yyval.sval) = create_statement(); (yyval.sval) -> type = PRINT_ST; (yyval.sval) -> ops.my_expr = (yyvsp[(1) - (1)].eval); }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 189 "rutc_yacc.y"
    {
					(yyval.sval) = create_statement();
					(yyval.sval) -> type = ASSIGN_ST;
					(yyval.sval) -> ops.assign.var = (yyvsp[(1) - (3)].eval);
					(yyval.sval) -> ops.assign.rval = (yyvsp[(3) - (3)].eval);
					(yyval.sval) -> ops.assign.operator = (yyvsp[(2) - (3)].ival);
					}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 196 "rutc_yacc.y"
    {
					(yyval.sval) = create_statement();
					(yyval.sval) -> type = ASSIGN_ST;
					(yyval.sval) -> ops.assign.var = (yyvsp[(1) - (3)].eval);
					(yyval.sval) -> ops.assign.rval = (yyvsp[(3) - (3)].eval);
					(yyval.sval) -> ops.assign.operator = '=';
					}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 204 "rutc_yacc.y"
    {
					(yyval.sval) = NULL;
					make_func((yyvsp[(2) - (7)].idval), (yyvsp[(4) - (7)].fval), (yyvsp[(7) - (7)].eval));
					}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 209 "rutc_yacc.y"
    {
					(yyval.sval) = create_statement();
					(yyval.sval) -> type = SOLVE_ST;
					(yyval.sval) -> ops.no_vars = (yyvsp[(2) - (2)].ival);
					}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 220 "rutc_yacc.y"
    {
						(yyval.sval) = create_statement();
						(yyval.sval) -> type = IF_ST;
						(yyval.sval) -> ops.if_else.condition = (yyvsp[(3) - (5)].eval);
						(yyval.sval) -> ops.if_else.branch[0] = (yyvsp[(5) - (5)].sval);
						(yyval.sval) -> ops.if_else.branch[1] = NULL;
						}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 227 "rutc_yacc.y"
    {
						(yyval.sval) = create_statement();
						(yyval.sval) -> type = IF_ST;
						(yyval.sval) -> ops.if_else.condition = (yyvsp[(3) - (7)].eval);
						(yyval.sval) -> ops.if_else.branch[0] = (yyvsp[(5) - (7)].sval);
						(yyval.sval) -> ops.if_else.branch[1] = (yyvsp[(7) - (7)].sval);
						}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 234 "rutc_yacc.y"
    {
						(yyval.sval) = create_statement();
						(yyval.sval) -> type = WHILE_ST;
						(yyval.sval) -> ops.while_c.condition = (yyvsp[(3) - (5)].eval);
						(yyval.sval) -> ops.while_c.loop_body = (yyvsp[(5) - (5)].sval);
						}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 241 "rutc_yacc.y"
    {
						(yyval.sval) = create_statement();
						(yyval.sval) -> type = FOR_ST;
						(yyval.sval) -> ops.for_c.first = (yyvsp[(3) - (9)].sval);
						(yyval.sval) -> ops.for_c.condition = (yyvsp[(5) - (9)].eval);
						(yyval.sval) -> ops.for_c.incr = (yyvsp[(7) - (9)].sval);
						(yyval.sval) -> ops.for_c.loop_body = (yyvsp[(9) - (9)].sval);
						}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 252 "rutc_yacc.y"
    {
					if((yyvsp[(1) - (3)].sval))
					{
					(yyval.sval) = (yyvsp[(1) - (3)].sval);
					(yyval.sval) -> next = (yyvsp[(3) - (3)].sval); 
					}
					else (yyval.sval) = (yyvsp[(3) - (3)].sval);
					}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 260 "rutc_yacc.y"
    { (yyval.sval) = NULL; }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 264 "rutc_yacc.y"
    { (yyval.eval) = create_expr(); copy_int_to_expr((yyvsp[(1) - (1)].ival), (yyval.eval));}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 266 "rutc_yacc.y"
    { (yyval.eval) = create_expr(); copy_double_to_expr((yyvsp[(1) - (1)].dval), (yyval.eval)); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 268 "rutc_yacc.y"
    { (yyval.eval) = create_expr(); copy_complex_const_to_expr((gsl_complex){0, 1}, (yyval.eval)); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 271 "rutc_yacc.y"
    { (yyval.eval) = create_expr();
					  (yyval.eval) -> type = NEG_EXPR;
					  (yyval.eval) -> ops.to_negate = (yyvsp[(2) - (2)].eval);
					}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 275 "rutc_yacc.y"
    { (yyval.eval) = (yyvsp[(2) - (2)].eval); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 277 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, '+', (yyvsp[(1) - (3)].eval), (yyvsp[(3) - (3)].eval), (yyval.eval));
					}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 281 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, '-', (yyvsp[(1) - (3)].eval), (yyvsp[(3) - (3)].eval), (yyval.eval));
					}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 286 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, '*', (yyvsp[(1) - (3)].eval), (yyvsp[(3) - (3)].eval), (yyval.eval));
					}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 290 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, '/', (yyvsp[(1) - (3)].eval), (yyvsp[(3) - (3)].eval), (yyval.eval));
					}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 294 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, '^', (yyvsp[(1) - (3)].eval), (yyvsp[(3) - (3)].eval), (yyval.eval));
					}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 298 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, IDIV, (yyvsp[(1) - (3)].eval), (yyvsp[(3) - (3)].eval), (yyval.eval));
					}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 302 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, '%', (yyvsp[(1) - (3)].eval), (yyvsp[(3) - (3)].eval), (yyval.eval));
					}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 308 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(COMPARE_EXPR, (yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].eval), (yyvsp[(3) - (3)].eval), (yyval.eval));
					}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 312 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(COMPARE_EXPR, (yyvsp[(2) - (3)].ival) | 0xFF00, (yyvsp[(1) - (3)].eval), (yyvsp[(3) - (3)].eval), (yyval.eval));
					}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 318 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, '!', (yyvsp[(2) - (2)].eval), NULL, (yyval.eval));
					}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 322 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, AND, (yyvsp[(1) - (3)].eval), (yyvsp[(3) - (3)].eval), (yyval.eval));
					}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 326 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, OR, (yyvsp[(1) - (3)].eval), (yyvsp[(3) - (3)].eval), (yyval.eval));
					}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 331 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, (yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].eval), (yyvsp[(3) - (3)].eval), (yyval.eval));
					}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 337 "rutc_yacc.y"
    { (yyval.eval) = (yyvsp[(1) - (1)].eval);
					  (yyval.eval) -> ops.var_op.incr = 0;
					  (yyval.eval) -> ops.var_op.pre = 0;
					 }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 341 "rutc_yacc.y"
    { (yyval.eval) = (yyvsp[(2) - (2)].eval);
					  (yyval.eval) -> ops.var_op.incr = (yyvsp[(1) - (2)].ival);
					  (yyval.eval) -> ops.var_op.pre = 1;
					}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 345 "rutc_yacc.y"
    { (yyval.eval) = (yyvsp[(1) - (2)].eval);
					  (yyval.eval) -> ops.var_op.incr = (yyvsp[(2) - (2)].ival);
					  (yyval.eval) -> ops.var_op.pre = 0;
					}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 350 "rutc_yacc.y"
    { (yyval.eval) = (yyvsp[(1) - (1)].eval); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 351 "rutc_yacc.y"
    { (yyval.eval) = (yyvsp[(2) - (3)].eval); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 354 "rutc_yacc.y"
    {
					(yyvsp[(6) - (7)].eval) -> st_list = (yyvsp[(3) - (7)].sval);
					(yyval.eval) = (yyvsp[(6) - (7)].eval);
					}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 359 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					(yyval.eval) -> type = FUNC_EXPR;
					(yyval.eval) -> ops.func_op.my_func = search_func((yyvsp[(1) - (4)].idval), func_head);
					(yyval.eval) -> ops.func_op.expr_list = (yyvsp[(3) - (4)].eval);
					}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 366 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, INT, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 372 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, '|', (yyvsp[(2) - (3)].eval), NULL, (yyval.eval));
					}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 377 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, ARG, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 382 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, REAL, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 387 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, IMAG, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 392 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, CONJ, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 398 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, SQRT, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 403 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, EXP, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 408 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, LOG, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 413 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, LN, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 420 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, COMBO, (yyvsp[(1) - (3)].eval), (yyvsp[(3) - (3)].eval), (yyval.eval));
					}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 424 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, PERM, (yyvsp[(1) - (3)].eval), (yyvsp[(3) - (3)].eval), (yyval.eval));
					}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 429 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					(yyval.eval) -> type = COND_EXPR;
					(yyval.eval) -> ops.cond.condition = (yyvsp[(1) - (5)].eval);
					(yyval.eval) -> ops.cond.expr1 = (yyvsp[(3) - (5)].eval);
					(yyval.eval) -> ops.cond.expr2 = (yyvsp[(5) - (5)].eval);
					}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 438 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, SIN, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 443 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, COS, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 448 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, TAN, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 453 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, SINH, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 457 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, COSH, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 461 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, TANH, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 466 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, ASIN, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 471 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, ACOS, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 476 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, ATAN, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 481 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, ASINH, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 485 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, ACOSH, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 489 "rutc_yacc.y"
    {
					(yyval.eval) = create_expr();
					make_expr(EXPR_EXPR, ATANH, (yyvsp[(3) - (4)].eval), NULL, (yyval.eval));
					}
    break;



/* Line 1455 of yacc.c  */
#line 2665 "rutc_yacc.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 495 "rutc_yacc.y"




