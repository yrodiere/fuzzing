
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 52 "rutc_yacc.y"
int ival; double dval; char *idval; struct statement *sval; struct expr *eval; struct ob_list *obval; struct var_name_list *fval; 


/* Line 1676 of yacc.c  */
#line 154 "rutc_yacc.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


