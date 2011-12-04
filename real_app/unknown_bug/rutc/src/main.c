#include <setjmp.h>
#include <stdio.h>
#include <time.h>

#include "rutc.h"

/*
 	Copyright (C) 2008 - 2009 by Lynus Vaz
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

jmp_buf main_buf;

int main()
{
 time_t now;
 struct tm *now_tm;
 int hr;
 struct variable *obase;

 time(&now);
 now_tm = localtime(&now);

 hr = now_tm -> tm_hour;

 if(hr >= 4 && hr < 6)
	fprintf(stderr, "Go back to bed\n");
 if(hr >= 6 && hr < 12)
	fprintf(stderr, "Good morning!\n");
 else if(hr >= 12 && hr < 17)
	fprintf(stderr, "Good afternoon!\n");
 else if(hr >= 17)
	fprintf(stderr, "Good evening!\n");
 else fprintf(stderr, "Shouldn\'t you be in bed?\n");

 
 fprintf(stderr, "Welcome to rutc, a calculator written using GNU Flex and GNU Bison\n");
 fprintf(stderr, "Type help if you need some\nType quit to leave\n");
 fprintf(stderr, "Your input is my command :)\n");

 setjmp(main_buf); 
 obase = get_var("obase[0]");
 
 obase -> is_int = 1;
 obase -> val.ival = 10;
 
 yyparse();
 return 0;
}
