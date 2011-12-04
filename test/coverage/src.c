#include <stdlib.h>
#include <stdio.h>

int bar (int a)
{
	return a == 54;
}

void foo ()
{
	int a, b, c;

	printf("Input: ");
	scanf("%d %d %d", &a, &b, &c);

	if (bar(a) && bar(b) && bar(c))
	{
		// Crash the program
		*(int*)NULL = 0;
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

