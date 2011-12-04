#ifndef __CALCI_H__
#define __CALCI_H__

#include <gsl/gsl_complex.h>

#include <setjmp.h>

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


#define var_value(a) ((a -> is_int)?(a -> val.ival):(a -> val.dval))

//#define var_value_c(a) ((a -> is_int == 0)?(a -> val.dval):((a -> is_int == 1)?(a -> val.ival):(a -> val.cval)))



#define val_value(a) ((a.is_int)?(a.val.ival):(a.val.dval))
//#define val_value_c(a) ((a.is_int == 0)?(a.val.dval):((a.is_int == 1)?(a.val.ival):(a.val.cval)))

struct value
{
 int is_int;
 union { double dval; int ival; gsl_complex cval; } val;
};
void print_value(const struct value *to_print);

struct variable
{
 union { double dval; int ival; gsl_complex cval; } val;
 int is_int;
 char *var_name;
 struct expr *var_expr;
 struct variable *next;
};

struct variable *get_var(char *check);		//Use this to locate a variable, or make it if not found. If created, starts with a double value of 0
struct variable *create_var(char *check);


struct expr					//Contains an expression
{
 int type;
 union
	{
		struct {char *var; struct expr *index; int incr; int pre; } var_op;		//as a variable 
		struct expr *to_negate;
		struct value constant;						//as a constant
		struct { struct expr *condition; struct expr *expr1; struct expr *expr2; } cond; //conditional
		struct { struct function *my_func; struct expr *expr_list; struct variable *local_vars; } func_op;	//as a user-defined function
		struct { struct expr *operands[2]; int operator; } expr_vals;	//as a function of expression(s)
	}ops;
 struct statement *st_list; 
 struct expr *next;
};

enum { CONST_EXPR, NEG_EXPR, ID_EXPR, EXPR_EXPR, COMPARE_EXPR, FUNC_EXPR, COND_EXPR };

struct expr *create_expr();							//create an expression on the heap
void make_expr(int type, int operator, struct expr *, struct expr *, struct expr *);
void print_expr(struct expr *);							//evaluate and print on screen
void incr_decr_id(struct variable *, int);
void copy_id_to_expr(struct variable *, struct expr *, int negate);		//evaluate and copy to variable
void copy_val_to_id(struct value *, struct variable *);
void copy_int_to_expr(int, struct expr *);					//make a constant expression
void copy_double_to_expr(double, struct expr *);				//ditto
void copy_complex_const_to_expr(gsl_complex src, struct expr *dest);
void copy_complex_to_expr(struct expr *expr1, struct expr *expr2, struct expr *dest);

struct value evaluate_expr(struct expr *to_evaluate);			//evaluate an expression

struct variable *extract_var(struct expr *);

gsl_complex var_value_c(const struct variable *);
gsl_complex val_value_c(const struct value *);

struct var_name_list
{
 char *name;
 struct var_name_list *next;
};

struct function
{
 char *func_name;
 int num_vars;
 struct expr *my_expr;
 struct var_name_list *var_list;

 struct function *next; 
};
struct function *make_func(char *name, struct var_name_list *vars, struct expr *my_expr);
struct function *search_func(char *name, struct function *this_func);

struct statement
{
 int type;									//determines which fields of the union to use
 union
	{
		struct expr *my_expr;						//used for printing
		int no_vars;							//solve system of equations
		struct { struct expr *var; struct expr *rval; int operator; } assign;	//assignment: var <op>= epxr
		struct { struct expr *condition; struct statement *branch[2]; } if_else;
		struct { struct expr *condition; struct statement *loop_body; } while_c;	//while loops
		struct { struct statement *first;
			 struct expr *condition;
			 struct statement *incr;
			 struct statement *loop_body; } for_c;				//'for' loops
	} ops;
 struct statement *next;							//statement to execute next
};

enum { PRINT_ST, ASSIGN_ST, IF_ST, WHILE_ST, FOR_ST, SOLVE_ST };

struct statement *create_statement();
void destroy_statement(struct statement *p);

void execute_statement(struct statement *);

#define INSUFFICIENT_MEM		{ yyerror("Out of memory... Exiting\n"); exit(1); }	//Oops


/*stat mode*/
struct ob_list
{
	struct expr *ob_expr;
	struct value ob_val;
	struct ob_list *next;

};

struct ob_list* create_oblist(void);
struct value calculate_median(struct ob_list *this_list);
struct value calculate_sd(struct ob_list *this_list);
struct value calculate_mean(struct ob_list *this_list);
void populate_list (struct ob_list *this_list);

int from_bin(char *);
int from_oct(char *);
int from_hex(char *);

double btod(char *);
double otod(char *);
double htod(char *);

char *convert_base_int(int dest_base, int src);
char *convert_base_double(int dest_base, double src);

void solve_linear_equations();							//Solve equations of form: a1x + b1y = c1, a2x + b2y = c2
void solve_linear_equations_2(int);						//Solve 'n' linear equations in 'n' variables: results are in x1,..., xn

int combo(int n, int r);
int perm(int n, int r);

void print_help();
void print_warranty();

extern jmp_buf main_buf;

//Parser functions:
int yylex();
void yyerror(char *);
int yyparse();

//Experimental
struct expr *create_expr_var(char *name, int index);


#endif
