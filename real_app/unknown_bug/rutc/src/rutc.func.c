#ifdef __GNUC__
#define _GNU_SOURCE
#else
#warning Not compiling on GCC. Some functions may not be available
#endif

#include <ctype.h>
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

#include <gsl/gsl_complex_math.h>
#include <gsl/gsl_matrix_double.h>
#include <gsl/gsl_permutation.h>

#include "rutc.h"
#include "rutc_yacc.h"
//#include "determinant.h"

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


extern struct variable *var_head;
extern struct function *func_head;

extern struct variable *local_var_head;
extern int num_func;

struct variable *create_var(char *check)
{
 struct variable *temp = malloc(sizeof(struct variable));
 if(temp)
 {
	temp -> var_name = malloc((strlen(check) + 1)*sizeof(char));
	if(! (temp -> var_name) )
		return NULL;
	strcpy(temp -> var_name, check);
	temp -> val.ival = 0;
	temp -> is_int = 1;
	temp -> var_expr = NULL;
	temp -> next = NULL;
 }
 return temp;
}

void print_value(const struct value *to_print)
{
 struct variable *obase = get_var("obase[0]");
 int base = var_value(obase);

 char *c1, *c2;

 if(to_print -> is_int == 1)
 {
	c1 = convert_base_int(base, to_print -> val.ival);
	printf("%s\n", c1);
	free(c1);
 }
 else if(to_print -> is_int == 0)
 {
	c1 = convert_base_double(base, to_print -> val.dval);
	printf("%s\n", c1);
	free(c1);
 }
 else
 {
	c1 = convert_base_double(base, GSL_REAL(to_print -> val.cval));
	c2 = convert_base_double(base, fabs(GSL_IMAG(to_print -> val.cval)));
	printf(GSL_IMAG(to_print -> val.cval) >= 0?"%s + I*%s\n":"%s - I*%s\n", c1, c2);
	free(c1);
	free(c2);
 }
 return;
}

void print_expr( struct expr *to_print )
{
 struct value final_val = evaluate_expr( to_print);
 print_value(&final_val);
 return; 
}


struct variable *insert_var(char *check, struct variable *to_insert)
{
 struct variable *temp = create_var(check);
 temp -> next = var_head;
 var_head = temp;
 return temp; 
}

struct variable *search_var(char *check, struct variable *to_check)
{
 if(!to_check) return NULL;
 if(!strcmp(check, to_check -> var_name))
	return to_check;
 return search_var(check, to_check -> next);
}

struct variable *get_var(char *check)
{
 struct variable *retval = NULL;

 //First check in local list
 retval = search_var(check, local_var_head);

 //Next in global list
 if(!retval)
	retval = search_var(check, var_head);

 if(!retval)
 {
	retval = insert_var(check, var_head);
 }
 if(retval == NULL)
	INSUFFICIENT_MEM
 return retval;
}

struct expr *create_expr()
{
 struct expr *p;

 p = malloc(sizeof(struct expr));

 if(!p)
	INSUFFICIENT_MEM

 p -> st_list = NULL;
 p -> next = NULL;
 return p;
}

struct expr *create_expr_var(char *name, int index)
{
 char *new_name = malloc(strlen(name) + 3 + 10);
 struct variable *var;
 sprintf(new_name, "%s[%d]", name, index);

 var = get_var(name);
 if(var -> var_expr == NULL)
 {
	var -> var_expr = create_expr();
	var -> var_expr -> type = ID_EXPR;
	var -> var_expr -> ops.var_op.var = strdup(name);
	var -> var_expr -> ops.var_op.index = create_expr();
	copy_int_to_expr(index, var -> var_expr -> ops.var_op.index);
 }
 return var -> var_expr;
}

void destroy_expr(struct expr *p)
{
 switch(p -> type)
 {
	case CONST_EXPR:
	break;

	case NEG_EXPR:
		if(p -> ops.to_negate) free(p -> ops.to_negate);
	break;

	case ID_EXPR:
		if(p -> ops.var_op.var) free(p -> ops.var_op.var);
		if(p -> ops.var_op.index) destroy_expr(p -> ops.var_op.index);
	break;

	case EXPR_EXPR:
	case COMPARE_EXPR:
		if(p -> ops.expr_vals.operands[0]) destroy_expr(p -> ops.expr_vals.operands[0]);
		if(p -> ops.expr_vals.operands[1]) destroy_expr(p -> ops.expr_vals.operands[1]);
	break;

	case FUNC_EXPR:
		if(p -> ops.func_op.expr_list) destroy_expr(p -> ops.func_op.expr_list);
	break;

	case COND_EXPR:
		if(p -> ops.cond.condition) destroy_expr(p -> ops.cond.condition);
		if(p -> ops.cond.expr1) destroy_expr(p -> ops.cond.expr1);
		if(p -> ops.cond.expr2) destroy_expr(p -> ops.cond.expr2);
	break;
 }
 if(p -> st_list) destroy_statement(p -> st_list);
 if(p -> next) free(p -> next);
 free(p);
}


struct statement *create_statement()
{
 struct statement *p;

 p = malloc(sizeof(struct statement));
 p -> next = NULL;

 if(!p)
	INSUFFICIENT_MEM
 return p;
}

void make_expr(int type, int operator, struct expr *op1, struct expr *op2, struct expr *p)
{
 p -> type = type;
 p -> ops.expr_vals.operator = operator;
 p -> ops.expr_vals.operands[0] = op1;
 p -> ops.expr_vals.operands[1] = op2;
}

void destroy_statement(struct statement *p)
{
 if(!p) return;
 switch(p -> type)
 {
	case PRINT_ST:
		destroy_expr(p -> ops.my_expr);
	break;

	case ASSIGN_ST:
		destroy_expr(p -> ops.assign.rval);
	break;

	case IF_ST:
		if(p -> ops.if_else.condition) destroy_expr(p -> ops.if_else.condition);
		if(p -> ops.if_else.branch[0]) destroy_statement(p -> ops.if_else.branch[0]);
		if(p -> ops.if_else.branch[1]) destroy_statement(p -> ops.if_else.branch[1]);
	break;
	case WHILE_ST:
		if(p -> ops.while_c.condition) destroy_expr(p -> ops.while_c.condition);
		if(p -> ops.while_c.loop_body) destroy_statement(p -> ops.while_c.loop_body);
	break;
 }
 if(p -> next) destroy_statement(p -> next);
 free(p);
}

void incr_decr_id(struct variable *src, int what)
{
 int incr = (what == '+')?1:(what == '-')?-1:0;
 switch(src -> is_int)
 {
	case 0:		
		src -> val.dval += (double)incr;
	break;

	case 1:
		src -> val.ival+= incr;
	break;

	case 2:
		src -> val.cval = gsl_complex_add_real(src -> val.cval, (double)incr);
	break;
 }
}

void copy_id_to_expr(struct variable *src, struct expr *dest, int negate)
{
 dest -> type = CONST_EXPR;
 dest -> ops.constant.is_int = src -> is_int;
 if(src -> is_int == 0)
	dest -> ops.constant.val.dval = src -> val.dval;
 else if(src -> is_int == 1)
	dest -> ops.constant.val.ival = src -> val.ival;
 else
	dest -> ops.constant.val.cval = src -> val.cval;
 return;
}

void copy_expr_to_id(struct expr *src, struct variable *dest)
{
 struct value val1;
 val1 = evaluate_expr(src);
 dest -> is_int = val1.is_int;
 if(dest -> is_int == 1)
	dest -> val.ival = val1.val.ival;
 else if(dest -> is_int == 0)
	dest -> val.dval = val1.val.dval;
 else
	dest -> val.cval = val1.val.cval;
 return;
}

void copy_val_to_id(struct value *src, struct variable *dest)
{
 dest -> is_int = src -> is_int;
 switch(src -> is_int)
 {
	case 0:
		dest -> val.dval = src -> val.dval;
	break;
	case 1:
		dest -> val.ival = src -> val.ival;
	break;
	case 2:
		dest -> val.cval = src -> val.cval;
	break;
 }
 return;
}

void copy_double_to_expr(double src, struct expr *dest)
{
 dest -> type = CONST_EXPR;
 dest -> ops.constant.is_int = 0;
 dest -> ops.constant.val.dval = src;
 return;
}

void copy_complex_const_to_expr(gsl_complex src, struct expr *dest)
{
 dest -> type = CONST_EXPR;
 dest -> ops.constant.is_int = 2;
 dest -> ops.constant.val.cval = src;
}

void copy_int_to_expr(int src, struct expr *dest)
{
 dest -> type = CONST_EXPR;
 dest -> ops.constant.is_int = 1;
 dest -> ops.constant.val.ival = src;
}

void copy_expr_to_expr(struct expr *src, struct expr *dest)
{
 dest -> type = src -> type;
 switch(dest -> type)
 {
	case CONST_EXPR:
		dest -> ops.constant = src -> ops.constant;
	break;

	case ID_EXPR:
		dest -> ops.var_op.var = src -> ops.var_op.var;
	break;

	case EXPR_EXPR:
		dest -> ops.expr_vals.operator = src -> ops.expr_vals.operator;
		dest -> ops.expr_vals.operands[0] = src -> ops.expr_vals.operands[0];
		dest -> ops.expr_vals.operands[1] = src -> ops.expr_vals.operands[1];		
	break;
 }
}

int expr_is_const(const struct expr *to_check)
{
 return (to_check -> type == CONST_EXPR);
}

gsl_complex var_value_c(const struct variable *a)
{
	gsl_complex retval = {0, 0};
	switch(a -> is_int)
	{
		case 0:
			GSL_REAL(retval) = a -> val.dval;
			break;
		case 1:
			GSL_REAL(retval) = a -> val.ival;
			break;
		case 2:
			retval = a -> val.cval;
			break;
	}
	return retval;
}

gsl_complex val_value_c(const struct value *a)
{
	gsl_complex retval = {0, 0};
	switch(a -> is_int)
	{
		case 0:
			GSL_REAL(retval) = a -> val.dval;
			break;
		case 1:
			GSL_REAL(retval) = a -> val.ival;
			break;
		case 2:
			retval = a -> val.cval;
			break;
	}
	return retval;
}

struct value evaluate_expr(struct expr *to_evaluate)
{
 struct value retval;
 struct value val1, val2;
 struct variable *var;
 struct expr *expr1;
 struct variable *var1, *prev_head;
 struct var_name_list *varname;
 int i;

 if(!to_evaluate)
	return retval;
 if(to_evaluate -> st_list)
	execute_statement(to_evaluate -> st_list);

 switch(to_evaluate -> type)
 {
	case CONST_EXPR:
		retval.is_int = to_evaluate -> ops.constant.is_int;
		if(retval.is_int == 1)
			retval.val.ival = to_evaluate -> ops.constant.val.ival;
		else if(retval.is_int == 0)
			retval.val.dval = to_evaluate -> ops.constant.val.dval;
		else
			retval.val.cval = to_evaluate -> ops.constant.val.cval;
	break;

	case NEG_EXPR:
		retval = evaluate_expr(to_evaluate -> ops.to_negate);
		
		if(retval.is_int == 1)
			retval.val.ival *= -1;
		else if(retval.is_int == 0)
			retval.val.dval *= -1;
		else
			retval.val.cval = gsl_complex_negative(retval.val.cval);
	break;

	case ID_EXPR:
		var = extract_var(to_evaluate);
		retval.is_int = var -> is_int;

		if(to_evaluate -> ops.var_op.pre)
			incr_decr_id(var, to_evaluate -> ops.var_op.incr);

		if(retval.is_int == 1)
			retval.val.ival = var -> val.ival;
		else if(retval.is_int == 0)
			retval.val.dval = var -> val.dval;
		else
			retval.val.cval = var -> val.cval;

		if(!to_evaluate -> ops.var_op.pre)
			incr_decr_id(var, to_evaluate -> ops.var_op.incr);

	break;

	case COND_EXPR:
		val1 = evaluate_expr(to_evaluate -> ops.cond.condition);
		if( val_value(val1) )
			retval = evaluate_expr(to_evaluate -> ops.cond.expr1);
		else
			retval = evaluate_expr(to_evaluate -> ops.cond.expr2);
	break;

	case EXPR_EXPR:
		val1 = evaluate_expr(to_evaluate -> ops.expr_vals.operands[0]);
		val2 = evaluate_expr(to_evaluate -> ops.expr_vals.operands[1]);
		retval.is_int = (val1.is_int == 2 || val2.is_int == 2)?2:((val1.is_int == 0 || val2.is_int == 0)?0:1);

		switch(to_evaluate -> ops.expr_vals.operator)
		{			
			case '+': 
				if(retval.is_int == 1)
					retval.val.ival = val_value(val1) + val_value(val2);
				else if(retval.is_int == 0)
					retval.val.dval = val_value(val1) + val_value(val2);					
				else
					retval.val.cval = gsl_complex_add(val_value_c(&val1), val_value_c(&val2));
			break;

			case '-': 
				if(retval.is_int == 1)
					retval.val.ival = val_value(val1) - val_value(val2);
				else if(retval.is_int == 0)
					retval.val.dval = val_value(val1) - val_value(val2);
				else
					retval.val.cval = gsl_complex_sub(val_value_c(&val1), val_value_c(&val2));
			break;

			case '*': 
				if(retval.is_int == 1)
					retval.val.ival = val_value(val1) * val_value(val2);
				else if(retval.is_int == 0)
					retval.val.dval = val_value(val1) * val_value(val2);
				else
					retval.val.cval = gsl_complex_mul(val_value_c(&val1), val_value_c(&val2));
			break;

			case '/': 
				if(retval.is_int == 1 || retval.is_int == 0)
				{
					retval.is_int = 0;
					retval.val.dval = (double)(val_value(val1)) / (double)(val_value(val2));
				}
				else
					retval.val.cval = gsl_complex_div(val_value_c(&val1), val_value_c(&val2));

			break;

			case '^':
				if(retval.is_int == 0 || retval.is_int == 1)
				{
					retval.is_int = 0;
					retval.val.dval = pow((double)(val_value(val1)), (double)(val_value(val2)));
				}
				else
				{
					retval.val.cval = gsl_complex_pow(val_value_c(&val1), val_value_c(&val2));
				}
			break;

			case IDIV:
				retval.is_int = 1;
				retval.val.ival = (int)((double)(val_value(val1))/(double)(val_value(val2)));
			break;

			case '%':
				if(retval.is_int)
					retval.val.ival = val1.val.ival % val2.val.ival;
				else
					retval.val.dval = val_value(val1) - ((int)((double)(val_value(val1))/(double)(val_value(val2))))*val_value(val2);
			break;

			case INT:
				retval.is_int = 1;
				retval.val.ival = (int)(val_value(val1));
				if(to_evaluate -> ops.expr_vals.operands[1])
					retval.val.ival *= (int)val_value(val2);
			break;

			case '!':
				retval.is_int = 1;
				retval.val.ival = (val_value(val1))?0:1;
			break;

			case AND:
				retval.is_int = 1;
				retval.val.ival = (val_value(val1) && val_value(val2))?1:0;
			break;

			case OR:
				retval.is_int = 1;
				retval.val.ival = (val_value(val1) || val_value(val2))?1:0;
			break;

			case '>':
				retval.is_int = 1;
				retval.val.ival = ((int)val_value(val1) >> (int)val_value(val2));
			break;

			case '<':
				retval.is_int = 1;
				retval.val.ival = ((int)val_value(val1) << (int)val_value(val2));
			break;

			case '|':
				retval = val1;
				if(retval.is_int == 1)
				{
					retval.val.ival = abs(val1.val.ival);
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.ival *= val_value(val2);
				}
				else if(retval.is_int == 0)
				{
					retval.val.dval = fabs(val1.val.dval);
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 0;
					retval.val.dval = gsl_complex_abs(val1.val.cval);
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
			break;

			case ARG:
				retval.is_int = 0;
				retval.val.dval = gsl_complex_arg(val_value_c(&val1));
				if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
			break;

			case REAL:
				retval.is_int = 0;
				retval.val.dval = GSL_REAL(val_value_c(&val1));
				if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
			break;

			case IMAG:
				retval.is_int = 0;
				retval.val.dval = GSL_IMAG(val_value_c(&val1));
				if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
			break;

			case CONJ:
				retval.is_int = 2;
				retval.val.cval = gsl_complex_conjugate(val_value_c(&val1));
				if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval, val_value_c(&val2));
			break;


			case SQRT:
				if((val1.is_int == 0 || val1.is_int == 1) && val_value(val1) >= 0)
				{
					retval.is_int = 0;
					retval.val.dval = sqrt(val_value(val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 2;
					retval.val.cval = gsl_complex_sqrt(val_value_c(&val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval, val_value_c(&val2));
				}
			break;

			case EXP:
				if(val1.is_int == 0 || val1.is_int == 1)
				{
					retval.is_int = 0;
					retval.val.dval = exp(val_value(val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 2;
					retval.val.cval = gsl_complex_exp(val_value_c(&val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval,  val_value_c(&val2));
				}
			break;

			case LOG:
				if((val1.is_int == 0 || val1.is_int == 1) && val_value(val1) >= 0)
				{
					retval.is_int = 0;
					retval.val.dval = log10(val_value(val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 2;
					retval.val.cval = gsl_complex_log10(val_value_c(&val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval, val_value_c(&val2));
				}
			break;

			case LN:
				if((val1.is_int == 0 || val1.is_int == 1) && val_value(val1) >= 0)
				{
					retval.is_int = 0;
					retval.val.dval = log(val_value(val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 2;
					retval.val.cval = gsl_complex_log(val_value_c(&val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval, val_value_c(&val2));
				}
			break;

			case COMBO:
				retval.is_int = 1;
				if(val_value(val1) < val_value(val2) || val_value(val2) < 0)
				{
					yyerror("rutc says: WRONG OPERANDS!!");
					longjmp(main_buf, 1);
				}
				retval.val.ival = combo(val_value(val1), val_value(val2));
			break;

			case PERM:
				retval.is_int = 1;
				if(val_value(val1) < val_value(val2) || val_value(val2) < 0)
				{
					yyerror("rutc says: WRONG OPERANDS!!");
					longjmp(main_buf, 1);
				}
				retval.val.ival = perm(val_value(val1), val_value(val2));
			break;

			case SIN:
				if(val1.is_int == 0 || val1.is_int == 1)
				{
					retval.is_int = 0;
					retval.val.dval = sin(val_value(val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 2;
					retval.val.cval = gsl_complex_sin(val_value_c(&val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval, val_value_c(&val2));
				}

			break;

			case COS:
				if(val1.is_int == 0 || val1.is_int == 1)
				{
					retval.is_int = 0;
					retval.val.dval = cos(val_value(val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 2;
					retval.val.cval = gsl_complex_cos(val_value_c(&val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval, val_value_c(&val2));
				}
			break;

			case TAN:
				if(val1.is_int == 0 || val1.is_int == 1)
				{
					retval.is_int = 0;
					retval.val.dval = tan(val_value(val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 2;
					retval.val.cval = gsl_complex_tan(val_value_c(&val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval, val_value_c(&val2));
				}
			break;

			case SINH:
				if(val1.is_int == 0 || val1.is_int == 1)
				{
					retval.is_int = 0;
					retval.val.dval = sinh(val_value(val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 2;
					retval.val.cval = gsl_complex_sinh(val_value_c(&val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval, val_value_c(&val2));
				}

			break;

			case COSH:
				if(val1.is_int == 0 || val1.is_int == 1)
				{
					retval.is_int = 0;
					retval.val.dval = cosh(val_value(val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 2;
					retval.val.cval = gsl_complex_cosh(val_value_c(&val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval, val_value_c(&val2));
				}

			break;

			case TANH:
				if(val1.is_int == 0 || val1.is_int == 1)
				{
					retval.is_int = 0;
					retval.val.dval = tanh(val_value(val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 2;
					retval.val.cval = gsl_complex_tanh(val_value_c(&val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval, val_value_c(&val2));
				}

			break;

			case ASIN:
				if((val1.is_int == 0 || val1.is_int == 1) && fabs(val_value(val1)) <= 1)
				{
					retval.is_int = 0;
					retval.val.dval = asin(val_value(val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 2;
					retval.val.cval = gsl_complex_arcsin(val_value_c(&val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval, val_value_c(&val2));
				}
			break;

			case ACOS:
				if((val1.is_int == 0 || val1.is_int == 1) && fabs(val_value(val1)) <= 1)
				{
					retval.is_int = 0;
					retval.val.dval = acos(val_value(val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 2;
					retval.val.cval = gsl_complex_arccos(val_value_c(&val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval, val_value_c(&val2));
				}
			break;

			case ATAN:
				if(val1.is_int == 0 || val1.is_int == 1)
				{
					retval.is_int = 0;
					retval.val.dval = atan(val_value(val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 2;
					retval.val.cval = gsl_complex_arctan(val_value_c(&val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval, val_value_c(&val2));
				}
			break;

			case ASINH:
				if(val1.is_int == 0 || val1.is_int == 1)
				{
					retval.is_int = 0;
					retval.val.dval = asinh(val_value(val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 2;
					retval.val.cval = gsl_complex_arcsinh(val_value_c(&val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval, val_value_c(&val2));
				}
			break;

			case ACOSH:
				if(val1.is_int == 0 || val1.is_int == 1)
				{
					retval.is_int = 0;
					retval.val.dval = acosh(val_value(val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 2;
					retval.val.cval = gsl_complex_arccosh(val_value_c(&val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval, val_value_c(&val2));
				}
			break;
			case ATANH:
				if(val1.is_int == 0 || val1.is_int == 1)
				{
					retval.is_int = 0;
					retval.val.dval = atanh(val_value(val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.dval *= val_value(val2);
				}
				else
				{
					retval.is_int = 2;
					retval.val.cval = gsl_complex_arctanh(val_value_c(&val1));
					if(to_evaluate -> ops.expr_vals.operands[1])
						retval.val.cval = gsl_complex_mul(retval.val.cval, val_value_c(&val2));
				}
			break;

		}
		break;

	case COMPARE_EXPR:
	{
		val1 = evaluate_expr(to_evaluate -> ops.expr_vals.operands[0]);
		val2 = evaluate_expr(to_evaluate -> ops.expr_vals.operands[1]);
		retval.is_int = 1;

		switch(to_evaluate -> ops.expr_vals.operator)
		{
			case '=':
				retval.val.ival = 
				( GSL_REAL(val_value_c(&val1)) == GSL_REAL(val_value_c(&val2))
				&& GSL_IMAG(val_value_c(&val1)) == GSL_IMAG(val_value_c(&val2)) );
				break;
			case '<':
				if(val1.is_int == 2 || val2.is_int == 2)
				{
					yyerror("rutc says: CANNOT COMPARE COMPLEX NUMBERS!!");
					longjmp(main_buf, 1);
				}
				retval.val.ival = (val_value(val1) < val_value(val2))?(1):(0);
				break;
			case '>':
				if(val1.is_int == 2 || val2.is_int == 2)
				{
					yyerror("rutc says: CANNOT COMPARE COMPLEX NUMBERS!!");
					longjmp(main_buf, 1);
				}
				retval.val.ival = (val_value(val1) > val_value(val2))?1:0;
				break;
			case ('<' | 0xFF00):
				if(val1.is_int == 2 || val2.is_int == 2)
				{
					yyerror("rutc says: CANNOT COMPARE COMPLEX NUMBERS!!");
					longjmp(main_buf, 1);
				}
				retval.val.ival = (val_value(val1) <= val_value(val2))?1:0;
				break;
			case ('>' | 0xFF00):
				if(val1.is_int == 2 || val2.is_int == 2)
				{
					yyerror("rutc says: CANNOT COMPARE COMPLEX NUMBERS!!");
					longjmp(main_buf, 1);
				}
				retval.val.ival = (val_value(val1) >= val_value(val2))?1:0;
				break;
			case ('!' | 0xFF00):
				retval.val.ival = (val_value(val1) != val_value(val2))?1:0;
				break;
		}
	}
	break;

	case FUNC_EXPR:
		if(!to_evaluate -> ops.func_op.my_func)
		{
			yyerror("rutc says: FUNCTION NOT DEFINED!!");
			longjmp(main_buf, 1);
		}

		to_evaluate -> ops.func_op.local_vars = NULL;

		expr1 = to_evaluate -> ops.func_op.expr_list;
		varname = to_evaluate -> ops.func_op.my_func -> var_list;
		for(i = 0; i < to_evaluate -> ops.func_op.my_func -> num_vars; i++)
		{
			if(!expr1)
			{
				char er_msg[100];
				sprintf(er_msg, "rutc says: WRONG NUMBER OF OPERANDS FOR FUNCTION %s!!",
					to_evaluate -> ops.func_op.my_func -> func_name);
				yyerror(er_msg);
				longjmp(main_buf, 1);
			}
			var1 = create_var(varname -> name);
			var1 -> next = to_evaluate -> ops.func_op.local_vars;
			to_evaluate -> ops.func_op.local_vars = var1;
			copy_expr_to_id(expr1, var1);
			varname = varname -> next;
			expr1 = expr1 -> next;
		}
		prev_head = local_var_head;
		local_var_head = to_evaluate -> ops.func_op.local_vars;
		retval = evaluate_expr(to_evaluate -> ops.func_op.my_func -> my_expr);

		//Destroy var list first!!
		local_var_head = prev_head;
	break;
 }
 return retval;
}

struct variable *extract_var(struct expr *orig)
{
 char var_name[100];
 int index;
 struct value ind_value = evaluate_expr(orig -> ops.var_op.index);
 index = val_value(ind_value);

 sprintf(var_name, "%s[%d]", orig -> ops.var_op.var, index);

 if(index < 0)
 {
	yyerror("rutc says: INVALID ARRAY INDEX!!");
	longjmp(main_buf, 1);
 }
 return get_var(var_name);
}

void execute_statement(struct statement *to_execute)
{
 struct variable *var;
 struct expr *temp_expr, *temp_var1;
 struct value temp_var2;
 
 if(!to_execute) return;
 switch(to_execute -> type)
 {
	case PRINT_ST:
		print_expr(to_execute -> ops.my_expr);
		break;

	case ASSIGN_ST:
		var = extract_var(to_execute -> ops.assign.var);
		if(!var)
		{
			yyerror("rutc says: INVALID ARRAY INDEX!!");
			longjmp(main_buf, 1);
			return;
		}
		if(to_execute -> ops.assign.operator == '=')
			copy_expr_to_id(to_execute -> ops.assign.rval, var);
		else
		{
			temp_expr = create_expr();
			temp_var1 = create_expr();
			copy_id_to_expr(var, temp_var1, 0);
			make_expr(EXPR_EXPR, to_execute -> ops.assign.operator,
					temp_var1, to_execute -> ops.assign.rval, temp_expr);
			temp_var2 = evaluate_expr(temp_expr);
			copy_val_to_id(&temp_var2, var);
		}
		break;

	case IF_ST:
		temp_var2 = evaluate_expr(to_execute -> ops.if_else.condition);
		if( val_value(temp_var2) )
			execute_statement(to_execute -> ops.if_else.branch[0]);
		else execute_statement(to_execute -> ops.if_else.branch[1]);
		break;

	case WHILE_ST:
		temp_var2 = evaluate_expr(to_execute -> ops.while_c.condition);
		while( val_value(temp_var2) )
		{
			execute_statement(to_execute -> ops.while_c.loop_body);
			temp_var2 = evaluate_expr(to_execute -> ops.while_c.condition);
		}
		break;

	case FOR_ST:
		execute_statement(to_execute -> ops.for_c.first);
		temp_var2 = evaluate_expr(to_execute -> ops.for_c.condition);
		while( val_value(temp_var2) )
		{
			execute_statement(to_execute -> ops.for_c.loop_body);
			execute_statement(to_execute -> ops.for_c.incr);
			temp_var2 = evaluate_expr(to_execute -> ops.for_c.condition);
		}
		break;

	case SOLVE_ST:
		solve_linear_equations_2(to_execute -> ops.no_vars);
		break;
 }
 execute_statement(to_execute -> next);
}

/*
void solve_linear_equations()			//Solve linear equations of form a1x + b1y = c1, a2x + b2y = c2
{
 double denominator;
 double num1, num2;

 double a1, a2, b1, b2, c1, c2;

 struct variable *x = get_var("x");
 struct variable *y = get_var("y");

 a1 = var_value(get_var("a1"));
 a2 = var_value(get_var("a2"));
 b1 = var_value(get_var("b1"));
 b2 = var_value(get_var("b2"));
 c1 = var_value(get_var("c1"));
 c2 = var_value(get_var("c2"));

 denominator = b2*a1 - b1*a2;
 num1 = b2*c1 - b1*c2;
 num2 = c2*a1 - c1*a2;

 x -> is_int = 0;
 x -> val.dval = num1/denominator;
 y -> val.dval = num2/denominator;

 return;
}

void fill_determinant(double **table, int num, struct determinant *to_fill, int col)
{
 int i, j;
 create_determinant(to_fill, num - 1);

 for(i = 0; i < num - 1; i++)
	for(j = 0; j < num - 1; j++)
		if(j == col)
			to_fill -> values[i][j] = table[i][num - 1];
		else
			to_fill -> values[i][j] = table[i][j];
}
*/

void solve_linear_equations_2(int num)		//Solve num equations of arbitrary no. of variables
{
 double **table;
 int i, j;
 char var_name[10];
 struct variable *var;
 int signum;
	
 gsl_permutation *p = gsl_permutation_alloc(num);
 gsl_matrix *var_matrix = gsl_matrix_alloc(num, num);
 gsl_vector *const_vector = gsl_vector_alloc(num);
	
 for(i = 0; i < num; i++)
 {
	for(j = 0; j < num; j++)
	{
		
		sprintf(var_name, "%c%d[0]", 'a' + j, i + 1);
		gsl_matrix_set(var_matrix, i, j, var_value(get_var(var_name)));
	}
	sprintf(var_name, "%c%d[0]", 'a' + j, i + 1);
	gsl_vector_set(const_vector, i, var_value(get_var(var_name)));
 }
  gsl_linalg_LU_decomp(var_matrix, p, &signum);
  gsl_linalg_LU_svx(var_matrix, p, const_vector);
  for(i = 0; i < num; i++)
  {
	sprintf(var_name, "x%d[0]", i + 1);
	  var = get_var(var_name);
	  var -> is_int = 0;
	  var -> val.dval = gsl_vector_get(const_vector, i);
  }
}

int combo(int n, int r)
{
 int i, num = 1;
 if(r > n-r)
	r = n - r;
 for(i = 0; i < r; i++)
	num = (num*(n - i))/(i+1);
 return num;
}

int perm(int n, int r)
{
 int i;
 int num = combo(n, r);
 for(i = 1; i <= r; i++)
	num *= i;

 return num;
}


/* for stat mode */

struct ob_list * create_oblist()
{
	struct ob_list * p;
	p = malloc(sizeof(struct ob_list));
 	p -> next = NULL;

 	if(!p)
		INSUFFICIENT_MEM
 	return p;
}


void populate_list (struct ob_list *this_list)
{
	while(this_list != NULL)
	{	
		this_list->ob_val = evaluate_expr (this_list->ob_expr);
		this_list=this_list->next;
	}
}

struct value calculate_mean(struct ob_list *this_list)
{
	struct value sum_val,mean_val;
	sum_val.val.dval=0;
	sum_val.is_int=0;
	int size=0;
	while(this_list!=NULL)
	{
		sum_val.val.dval +=val_value(this_list->ob_val);
		this_list=this_list->next;
		size++;
	}
	mean_val.val.dval = ( sum_val.val.dval / size );
	mean_val.is_int=0;
	return mean_val;
		
		

}

struct value calculate_sd(struct ob_list *this_list)
{
	struct value mean_val=calculate_mean(this_list),sd_val,sum_val;
	sum_val.val.dval=0;
	sum_val.is_int=0;
	int size=0;
	while(this_list!=NULL)
	{
		sum_val.val.dval +=( ( val_value(mean_val) - val_value(this_list->ob_val)  ) * ( val_value(mean_val) - val_value(this_list->ob_val)  ) );
		size++;
		this_list=this_list->next;
	}
	sd_val.val.dval = ( sum_val.val.dval / size );
	sd_val.is_int=0;
	return sd_val;
}

struct ob_list * sort_ob_list(struct ob_list *this_list)
{
	struct ob_list *head = this_list, *current_ob, *prev_ob;
	struct ob_list *temp;
	current_ob = head->next;
	prev_ob = head;
	while(current_ob != NULL)
	{
		if( val_value(current_ob->ob_val) > val_value(prev_ob->ob_val) )
		{
			prev_ob=current_ob;
			current_ob=current_ob->next;
		}
		else
		{
			if( val_value(current_ob->ob_val) < val_value(head->ob_val) )
			{
				
				temp = current_ob->next;
				current_ob->next=head;
				prev_ob->next=temp;
				head=current_ob;
				current_ob=prev_ob->next;
			}
			else
			{
				temp=current_ob;
				prev_ob->next=current_ob->next;
				current_ob=head;
				while( val_value(temp->ob_val) > val_value(current_ob->next->ob_val) )
				{
					current_ob=current_ob->next;
				}
				temp->next=current_ob->next;
				current_ob->next=temp;
				current_ob=prev_ob->next;
						
			}
		}

	}
	return head;
	
}

struct value calculate_median(struct ob_list *this_list)
{
	struct ob_list *temp1,*temp2;
	struct value ob;
	this_list=sort_ob_list(this_list);
	temp1=temp2=this_list;
	int size=0,i=0;
	while(temp2!=NULL)
	{
		temp2=(temp2->next);
		size++;
		
	}
	if(size%2==0)
	{
		for(i=1;i<size/2;i++)
			temp1=temp1->next;
		ob.is_int=0;
		ob.val.dval=(  val_value(temp1->ob_val) + val_value(temp1->next->ob_val)  )/2.0;
		return ob;
	}
	else
	{
		for(i=0;i<size/2;i++)
			temp1=temp1->next;
		ob.is_int=0;
		
	}
		return temp1->ob_val;
}


int from_bin(char *text)
{
 int len = strlen(text);
 int pos;
 int num =0, mul = 1;
 
 for(pos = len - 2; pos >= 0; pos--)
 {
 	num += mul*(text[pos] - '0');
 	mul *= 2;
 }
 return num;
}

int from_oct(char *text)
{
 int len = strlen(text);
 int pos;
 int num =0, mul = 1;
 
 for(pos = len - 2; pos >= 0; pos--)
 {
 	num += mul*(text[pos] - '0');
 	mul *= 8;
 }
 return num;
}

int from_hex(char *text)
{
 int len = strlen(text);
 int pos;
 int num =0, mul = 1;
 
 for(pos = len - 2; pos >= 0; pos--)
 {
  if(isdigit(text[pos]))
 	num += mul*(text[pos] - '0');
  else
  	num += mul*((isupper(text[pos])) ? (text[pos] - 'A' + 10) : (text[pos]-'a'+10));
 	mul *= 16;
 }
 return num;

}

int find_dot_pos(char *text, const char c)
{
	int i;
	for(i=0;i<strlen(text);i++)
	{
		if(text[i]== c)
			return i;
	}
	return -1;		
}

double btod(char *text)
{
 int len = strlen(text);
 int pos,dot_pos=find_dot_pos(text, '.');
 double num =0, mul = 0.5;
 
 for(pos = dot_pos + 1; pos < len-1 ; pos++)
 {
 	num += mul*(text[pos] - '0');
 	mul *= 0.5;
 }
 mul = 1; 
 for(pos = dot_pos - 1; pos >= 0; pos--)
 {
 	num += mul*(text[pos] - '0');
 	mul *= 2;
 }
 return num;
}

double otod(char *text)
{
 int len = strlen(text);
 int pos,dot_pos=find_dot_pos(text, '.');
 double num =0, mul = 0.125;
 
 for(pos = dot_pos + 1; pos < len-1 ; pos++)
 {
 	num += mul*(text[pos] - '0');
 	mul *= 0.125;
 }
 mul = 1;
 for(pos = dot_pos - 1; pos >= 0; pos--)
 {
 	num += mul*(text[pos] - '0');
 	mul *= 8;
 }
 return num;
}

double htod(char *text)
{
 int len = strlen(text);
 int pos,dot_pos=find_dot_pos(text, '.');
 double num =0, mul = 0.0625;
 
 for(pos = dot_pos + 1; pos < len-1 ; pos++)
 {
  if(isdigit(text[pos]))
 	num += mul*(text[pos] - '0');
  else
  	num += mul*((isupper(text[pos])) ? (text[pos] - 'A' + 10) : (text[pos]-'a'+10));
 	mul *= 0.0625;
 }
 mul = 1;
 for(pos = dot_pos -1; pos >= 0; pos--)
 {
  if(isdigit(text[pos]))
 	num += mul*(text[pos] - '0');
  else
  	num += mul*((isupper(text[pos])) ? (text[pos] - 'A' + 10) : (text[pos]-'a'+10));
 	mul *= 16;
 }
 return num;
}

void binary_conv(int src, char *dest)
{
 char p[33];
 int mask = 1;
 int pos = sizeof(int)*8 - 1;
 p[pos+1] = '\0';
 while(mask)
 {
 	p[pos] = ((mask & src)?'1':'0');
 	pos--;
 	mask *= 2;
 }
 pos = find_dot_pos(p, '1');
 strcpy(dest, p + pos);
}

char *convert_base_int(int dest_base, int src)
{
 char p[33];
 char *retval;
 switch(dest_base)
 {
 	case 2:
 		binary_conv(src, p);
 	break;
 	case 8:
 		sprintf(p, "%o", src);
 	break;
 	case 10:
 		sprintf(p, "%d", src);
 	break;
 	case 16:
 		sprintf(p, "%x", src);
 	break;
 	
 	default: yyerror("rutc says: WRONG BASE!! Base format not supported");
 	longjmp(main_buf, 1);
 	
 }
 retval = malloc((strlen(p) + 1)*sizeof(char));
 strcpy(retval, p);
 return retval;
}

char *convert_base_double(int dest_base, double src)
{
 char *p1, p2[100];
 char *retval;
 
 int src1 = (int)src;
 double src2 = (double)src - (double)src1;
 
 int pos;
 int digit;
 
 if(dest_base == 10)
 {
	sprintf(p2, "%g", src);
	retval = malloc(strlen(p2) + 1);
 	sprintf(retval, "%s", p2);
 	return retval;	
 }
 
 p1 = convert_base_int(dest_base, src1);
 
 for(pos = 0; pos < 6; pos++)
 {
 	src2 *= dest_base;
 	digit = (int)src2;
 	src2 -= digit;
 	p2[pos] = (digit <= 9)?(digit + '0'):(digit+'a'-10);
 }
 p2[pos] = 0;
 retval = malloc(strlen(p1) + strlen(p2) + 2);
 sprintf(retval, "%s.%s", p1, p2);
 free(p1);
 return retval;
}

struct function *create_func()
{
 struct function *p = malloc(sizeof(struct function));
 if(!p)
	INSUFFICIENT_MEM
 return p;
}

struct function *search_func(char *name, struct function *this_func)
{
 if(this_func == NULL)
	return NULL;

 if(!strcmp(this_func -> func_name, name))
	return this_func;
 return search_func(name, this_func -> next);
}

void insert_func(struct function *to_insert)
{
 to_insert -> next = func_head;
 func_head = to_insert;
}

void destroy_func(struct function *to_destroy)
{
 free(to_destroy -> func_name);
 free(to_destroy);
}

struct function *make_func(char *name, struct var_name_list *vars, struct expr *my_expr)
{
 struct function *found = search_func(name, func_head);
 struct var_name_list *var;
 if(found)
	destroy_func(found);

 found = create_func();
 found -> func_name = strdup(name);
 found -> var_list = vars;
 
 var = found -> var_list;

 found -> num_vars = 0;
 while(var)
 {
	found -> num_vars++;
	var = var -> next;
 }


 found -> my_expr = my_expr;

 insert_func(found);
 return found;
}

void print_warranty()
{
 printf("rutc 0.1.0\n");
 printf("Copyright 2008, Lynus Vaz, Durgesh Samant\n");
 printf("This program is free software; you can redistribute it and/or modify\n" 
	"it under the terms of the GNU General Public License as published by\n"
	"the Free Software Foundation; either version 3 of the License, or\n"
	"(at your option) any later version.\n\n");

 printf("This program is distributed in the hope that it will be useful,\n"
	"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
	"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
	"GNU General Public License for more details.\n\n");

 printf("You should have received a copy of the GNU General Public License\n"
	"along with this program.  If not, see <http://www.gnu.org/licenses/>.\n");
}

void print_help()
{
 printf("rutc is an expression solver written using GNU Flex and GNU Bison\n");
 printf("It supports expressions, variables, arrays and control statements.\n");
 printf("To evaluate a simple expression, just type it in,\n");
 printf("e.g. (2 + 4)*5\n");
 printf("To set the display base, change the obase variable.\nPossible values are 2, 8, 10 and 16\n");
 printf("Variables are assigned using the = sign\n");
 printf("e.g. a = 23\n");
 printf("You can access elements of arrays using square brackets [].\n");
 printf("e.g. a[2] = 2\n");
 printf("Control statements consist of if and while statements,\n");
 printf("e.g. if(a == 2) { b = a \n} else { b = -2\n}\n");
 printf("while(a < 10) { a = a + 1\na\n}\n");
 printf("For both of them, note the position of the }.\nIn the if statement, the else is optional;\nif you use it, it comes on the same line as }\n");
 printf("For more information, see the README file.\n\n");
 return; 
}

