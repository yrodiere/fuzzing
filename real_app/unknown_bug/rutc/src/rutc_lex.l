/* This is the lexical analyser for rutc */
%{
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "rutc.h"
#include "rutc_yacc.h"

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
	MErutcHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

void yyerror(char*);

%}

/* Keywords:
int				int(a) will be equal to the integer of a
div				a div b = int(a / b)
mod				remainder when a is divided by b
pi				3.14159
e				2.71828
exp				exp(a) = e ^ a
sin
cos
tan
sinh
cosh
tanh
atan
asin
acos
asinh
acosh
atanh
sqrt
ln
log
C				n C r
P				n P r
stat				to enter statistic mode
endstat				to leave statistics mode
ob_set				to enter a list of observation

change the value of obase to your favourite base. Only binary, octal, decimal and hex supported.

if
else
solve
quit

*/

%%
\t						;
" "						;
([0-9]*\.[0-9]+)				{ yylval.dval = atof(yytext); return DOUBLE; }
([0-9]+)					{ yylval.ival = atoi(yytext); return INTEGER; }



([0-1]*\.[0-1]+)b				{ yylval.dval = btod(yytext); return DOUBLE; }
([0-7]*\.[0-7]+)o				{ yylval.dval = otod(yytext); return DOUBLE; }
([0-9a-fA-F]*\.[0-9a-fA-F]+)h			{ yylval.dval = htod(yytext); return DOUBLE; }

([0-1]+)b					{ yylval.ival = from_bin(yytext); return INTEGER; }
([0-7]+)o					{ yylval.ival = from_oct(yytext); return INTEGER; }
([0-9a-fA-F]+)h					{ yylval.ival = from_hex(yytext); return INTEGER; }

	 /* First the extra operators */
"if"						return IF;
"else"						return ELSE;
"while"						return WHILE;
"for"						return FOR;
"div"						return IDIV;
"int"						return INT;
"sin"						return SIN;
"cos"						return COS;
"tan"						return TAN;
"sinh"						return SINH;
"cosh"						return COSH;
"tanh"						return TANH;
"asin"						return ASIN;
"acos"						return ACOS;
"atan"						return ATAN;
"asinh"						return ASINH;
"acosh"						return ACOSH;
"atanh"						return ATANH;

"arg"						return ARG;
"real"						return REAL;
"imag"						return IMAG;
"conj"						return CONJ;

"sqrt"						return SQRT;
"ln"						return LN;
"exp"						return EXP;
"log"						return LOG;

"C"						return COMBO;
"P"						return PERM;

"stat"						return STAT;
"endstat"					return ENDSTAT;
"ob_set"					return OB_SET;

"func"						return FUNC;


						  /* Now constants */
"pi"						{yylval.dval = M_PI; return DOUBLE; }
"e"						{yylval.dval = exp(1); return DOUBLE; }
"I"						return 'I';

"solve"						return SOLVE;


"quit"						return QUIT;
"exit"						return QUIT;
"help"						return HELP;
"warranty"					return WARRANTY;

						  /* If nothing else, it is an identifier */
[_a-zA-Z][_a-zA-Z0-9]*				{  yylval.idval = strdup(yytext); return IDENTIFIER; }

"+="|"-="|"*="|"/="|"^="|"%="			{ yylval.ival = (int)yytext[0]; return ASSIGN_OP; }
"++"|"--"					{ yylval.ival = (int)yytext[0]; return INCR_DECR; }
"<"|">"|"=="					{ yylval.ival = (int)yytext[0]; return REL_OP;    }
"<="|">="|"!="					{ yylval.ival = (int)yytext[0]; return REL_OP_EQ; }

"&&"						{ return AND; }
"||"						{ return OR; }

"<<"|">>"					{ yylval.ival = (int)yytext[0]; return BIT_OP;    }
"\\\n"
\n						{ return *yytext; }
"/*"  {						/* Ok, ok, this part's copied from bc */
	int c;

	for (;;)
	  {
	    while ( ((c=input()) != '*') && (c != EOF)) 
	      /* eat it */
	      if (c == '\n');
	    if (c == '*')
 	      {
		while ( (c=input()) == '*') /* eat it*/;
		if (c == '/') break; /* at end of comment */
	      }
	    if (c == EOF)
	      {
		fprintf (stderr,"EOF encountered in a comment.\n");
		break;
	      }
	  }
      }
				
.						{ return *yytext; }
%%

