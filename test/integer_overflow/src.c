#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void foo ()
{
	short i;
	int max;

	printf("SHRT_MAX: %d\nInput: ", SHRT_MAX);
	scanf("%d", &max);

	// Infinite loop if entered 'max' was > SHRT_MAX
	for (i = 0 ; i < max ; ++i)
	{
		// Do something
	}
}

int main (int argc, char **argv)
{
	if (argc > 1)
	{
		printf("Usage: %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	foo();

	exit(EXIT_SUCCESS);
}

