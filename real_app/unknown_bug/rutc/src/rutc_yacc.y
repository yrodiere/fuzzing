/* Grammar file for rutc */
%{
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

%}

%union {int ival; double dval; char *idval; struct statement *sval; struct expr *eval; struct ob_list *obval; struct var_name_list *fval; }

/* Here are the terminals: I've used CAPS to prevent confusion with C keywords */
%token <idval> IDENTIFIER
%token <ival> INTEGER
%token <dval> DOUBLE
%token IDIV SQRT
%token SIN COS TAN ASIN ACOS ATAN EXP SINH COSH TANH ASINH ACOSH ATANH
%token LOG LN
%token INT SOLVE QUIT HELP WARRANTY
%token IF ELSE
%token WHILE FOR
%token <ival> ASSIGN_OP INCR_DECR REL_OP REL_OP_EQ BIT_OP
%token AND OR
%token COMBO PERM
%token ARG REAL IMAG CONJ
%token STAT ENDSTAT OB_SET FUNC

/* And now the type of non-terminals */
%type <eval> EXPR NUMBER
%type <eval> VARIABLE
%type <sval> EXEC_STATEMENT ST_LIST
%type <obval> OB_LIST
%type <fval> ID_LIST
%type <eval> EXPR_LIST


/* Setting associativity and precedence */
%left '?' ':'
%left OR
%left AND
%right '!'
%left REL_OP REL_OP_EQ
%left '-'
%left '+'
%left '*'
%left '/' IDIV '%'
%left '^'
%left BIT_OP
%left PERM COMBO
%nonassoc INCR_DECR
%right UNARY

%start LINES

%%

//Session consists of possibly many lines
LINES	: LINES LINE			
	|
	;

//A line may be a statement and executed immediately
LINE	: EXEC_STATEMENT '\n'		{ if($1) execute_statement($1); destroy_statement($1);} 	//Have to work this out. What can we free?
	| HELP '\n'		 	{ print_help(); }			//Put this here, or in EXEC_STATEMENT?
	| WARRANTY '\n'			{ print_warranty(); }
	| QUIT '\n'			{ YYACCEPT; }				//Type quit to exit
	| error '\n'
	| STAT '\n' STAT_LINES  ENDSTAT '\n'
	;

STAT_LINES :
	OB_LINE '\n' STAT_LINES
	| /* empty */
	
OB_LINE:	OB_SET '=' '{' OB_LIST '}' {struct value print;
					populate_list($4);
					print=calculate_mean($4);
					printf("\nmean = ");
					print_value(&print);
					print=calculate_sd($4);
					printf("standard deviation = ");
					print_value(&print);
					print=calculate_median($4);
					printf("median = ");
					print_value(&print);
					}
	|	EXEC_STATEMENT		{ if($1) execute_statement($1); destroy_statement($1);}

OB_LIST :
		EXPR			{
					 $$ = create_oblist(); 
					 $$->ob_expr=$1;
					 $$->next=NULL;
					}

	|	EXPR ',' OB_LIST	{
					$$ = create_oblist();
					$$->ob_expr=$1;
					$$->next=$3;
					}
	
ID_LIST		: IDENTIFIER		{
					$$ = malloc(sizeof(struct var_name_list));
					$$ -> name = malloc(strlen($1) + 4);
					sprintf($$ -> name, "%s[0]", $1);
					$$ -> next = NULL;
					free($1);

					}
	| IDENTIFIER ',' ID_LIST	{
					$$ = malloc(sizeof(struct var_name_list));
					$$ -> name = malloc(strlen($1) + 4);
					sprintf($$ -> name, "%s[0]", $1);
					$$ -> next = $3;
					free($1);
					}

EXPR_LIST	: EXPR			{
					$$ = $1;
					}
	| EXPR ',' EXPR_LIST		{
					$$ = $1;
					$$ -> next = $3;
					}

E	: '\n' E
	| '\n'

VARIABLE	: IDENTIFIER		{
					$$ = create_expr();
					$$ -> type = ID_EXPR;
					$$ -> ops.var_op.var = $1;
					$$ -> ops.var_op.index = create_expr();
					copy_int_to_expr(0, $$ -> ops.var_op.index);
					}
					
	| IDENTIFIER '[' EXPR ']'	{					//Array
					$$ = create_expr();
					$$ -> type = ID_EXPR;
					$$ -> ops.var_op.var = $1;
					$$ -> ops.var_op.index = $3;
					}
EXEC_STATEMENT	: '{' ST_LIST '}'	{ $$ = $2; }
	| E EXEC_STATEMENT		{ $$ = $2; }
	| EXPR		{ $$ = create_statement(); $$ -> type = PRINT_ST; $$ -> ops.my_expr = $1; }
					
	| VARIABLE ASSIGN_OP EXPR	{
					$$ = create_statement();
					$$ -> type = ASSIGN_ST;
					$$ -> ops.assign.var = $1;
					$$ -> ops.assign.rval = $3;
					$$ -> ops.assign.operator = $2;
					}
	| VARIABLE '=' EXPR		{
					$$ = create_statement();
					$$ -> type = ASSIGN_ST;
					$$ -> ops.assign.var = $1;
					$$ -> ops.assign.rval = $3;
					$$ -> ops.assign.operator = '=';
					}

	| FUNC IDENTIFIER '(' ID_LIST ')' '=' EXPR {
					$$ = NULL;
					make_func($2, $4, $7);
					}

	| SOLVE INTEGER			{
					$$ = create_statement();
					$$ -> type = SOLVE_ST;
					$$ -> ops.no_vars = $2;
					} 
//I'll fix it up later, but for now:
// if(a) { b = a
// c = b
// } else { c = -1
// }
//Note placement of } and else
	| IF '(' EXPR ')' EXEC_STATEMENT {
						$$ = create_statement();
						$$ -> type = IF_ST;
						$$ -> ops.if_else.condition = $3;
						$$ -> ops.if_else.branch[0] = $5;
						$$ -> ops.if_else.branch[1] = NULL;
						}
	| IF '(' EXPR ')' EXEC_STATEMENT ELSE EXEC_STATEMENT	{
						$$ = create_statement();
						$$ -> type = IF_ST;
						$$ -> ops.if_else.condition = $3;
						$$ -> ops.if_else.branch[0] = $5;
						$$ -> ops.if_else.branch[1] = $7;
						}
	| WHILE '(' EXPR ')' EXEC_STATEMENT {
						$$ = create_statement();
						$$ -> type = WHILE_ST;
						$$ -> ops.while_c.condition = $3;
						$$ -> ops.while_c.loop_body = $5;
						}
	| FOR '(' EXEC_STATEMENT ';' EXPR ';' EXEC_STATEMENT ')' EXEC_STATEMENT
						{
						$$ = create_statement();
						$$ -> type = FOR_ST;
						$$ -> ops.for_c.first = $3;
						$$ -> ops.for_c.condition = $5;
						$$ -> ops.for_c.incr = $7;
						$$ -> ops.for_c.loop_body = $9;
						}
	;

//For deferred execution (in loops and if's)
ST_LIST	: EXEC_STATEMENT '\n' ST_LIST	{
					if($1)
					{
					$$ = $1;
					$$ -> next = $3; 
					}
					else $$ = $3;
					}
	|				{ $$ = NULL; }
	;

//Does it make it simpler?
NUMBER	: INTEGER			{ $$ = create_expr(); copy_int_to_expr($1, $$);}

	| DOUBLE			{ $$ = create_expr(); copy_double_to_expr($1, $$); }

	| 'I'				{ $$ = create_expr(); copy_complex_const_to_expr((gsl_complex){0, 1}, $$); }
	;

EXPR	: '-' EXPR %prec UNARY		{ $$ = create_expr();
					  $$ -> type = NEG_EXPR;
					  $$ -> ops.to_negate = $2;
					}
	| '+' EXPR %prec UNARY		{ $$ = $2; }

	| EXPR '+' EXPR			{
					$$ = create_expr();
					make_expr(EXPR_EXPR, '+', $1, $3, $$);
					}
	| EXPR '-' EXPR			{
					$$ = create_expr();
					make_expr(EXPR_EXPR, '-', $1, $3, $$);
					}

	| EXPR '*' EXPR			{
					$$ = create_expr();
					make_expr(EXPR_EXPR, '*', $1, $3, $$);
					}
	| EXPR '/' EXPR			{
					$$ = create_expr();
					make_expr(EXPR_EXPR, '/', $1, $3, $$);
					} 
	| EXPR '^' EXPR			{
					$$ = create_expr();
					make_expr(EXPR_EXPR, '^', $1, $3, $$);
					}
	| EXPR IDIV EXPR		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, IDIV, $1, $3, $$);
					}
	| EXPR '%' EXPR		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, '%', $1, $3, $$);
					}

/* Comparisons */
	| EXPR REL_OP EXPR		{
					$$ = create_expr();
					make_expr(COMPARE_EXPR, $2, $1, $3, $$);
					}
	| EXPR REL_OP_EQ EXPR		{
					$$ = create_expr();
					make_expr(COMPARE_EXPR, $2 | 0xFF00, $1, $3, $$);
					}

/* Boolean */
	| '!' EXPR			{
					$$ = create_expr();
					make_expr(EXPR_EXPR, '!', $2, NULL, $$);
					}
	| EXPR AND EXPR			{
					$$ = create_expr();
					make_expr(EXPR_EXPR, AND, $1, $3, $$);
					}
	| EXPR OR EXPR			{
					$$ = create_expr();
					make_expr(EXPR_EXPR, OR, $1, $3, $$);
					} 
/* Bitwise */
	| EXPR BIT_OP EXPR		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, $2, $1, $3, $$);
					}


	| VARIABLE			{ $$ = $1;
					  $$ -> ops.var_op.incr = 0;
					  $$ -> ops.var_op.pre = 0;
					 }
	| INCR_DECR VARIABLE		{ $$ = $2;
					  $$ -> ops.var_op.incr = $1;
					  $$ -> ops.var_op.pre = 1;
					}
	| VARIABLE INCR_DECR		{ $$ = $1;
					  $$ -> ops.var_op.incr = $2;
					  $$ -> ops.var_op.pre = 0;
					}

	| NUMBER			{ $$ = $1; }
	| '(' EXPR ')'			{ $$ = $2; }

	| '(' '{' ST_LIST '}' ',' EXPR ')'	//Execute the statements and evaluate the EXPR part
					{
					$6 -> st_list = $3;
					$$ = $6;
					}

	| IDENTIFIER '(' EXPR_LIST ')'	{
					$$ = create_expr();
					$$ -> type = FUNC_EXPR;
					$$ -> ops.func_op.my_func = search_func($1, func_head);
					$$ -> ops.func_op.expr_list = $3;
					}

	| INT '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, INT, $3, NULL, $$);
					}

/* Absolute */
	| '|' EXPR '|'			{
					$$ = create_expr();
					make_expr(EXPR_EXPR, '|', $2, NULL, $$);
					}
/* For complex expressions */
	| ARG '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, ARG, $3, NULL, $$);
					}

	| REAL '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, REAL, $3, NULL, $$);
					}

	| IMAG '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, IMAG, $3, NULL, $$);
					}

	| CONJ '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, CONJ, $3, NULL, $$);
					}

/* Arithmetic functions */
	| SQRT '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, SQRT, $3, NULL, $$);
					}

	| EXP '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, EXP, $3, NULL, $$);
					}

	| LOG '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, LOG, $3, NULL, $$);
					}

	| LN '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, LN, $3, NULL, $$);
					}

/* Permutation, Combination */

	| EXPR COMBO EXPR		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, COMBO, $1, $3, $$);
					}
	| EXPR PERM EXPR		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, PERM, $1, $3, $$);
					}

	| EXPR '?' EXPR ':' EXPR	{
					$$ = create_expr();
					$$ -> type = COND_EXPR;
					$$ -> ops.cond.condition = $1;
					$$ -> ops.cond.expr1 = $3;
					$$ -> ops.cond.expr2 = $5;
					}

/* Trigo functions */
	| SIN '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, SIN, $3, NULL, $$);
					}

	| COS '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, COS, $3, NULL, $$);
					}

	| TAN '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, TAN, $3, NULL, $$);
					}

	| SINH '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, SINH, $3, NULL, $$);
					}
	| COSH '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, COSH, $3, NULL, $$);
					}
	| TANH '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, TANH, $3, NULL, $$);
					}

	| ASIN '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, ASIN, $3, NULL, $$);
					}

	| ACOS '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, ACOS, $3, NULL, $$);
					}

	| ATAN '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, ATAN, $3, NULL, $$);
					}

	| ASINH '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, ASINH, $3, NULL, $$);
					}
	| ACOSH '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, ACOSH, $3, NULL, $$);
					}
	| ATANH '(' EXPR ')'		{
					$$ = create_expr();
					make_expr(EXPR_EXPR, ATANH, $3, NULL, $$);
					}
	;

%%


