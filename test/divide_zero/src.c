#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void foo ()
{
	int n = 1;
	int d;

	printf("Input: ");
	scanf("%d", &d);

	n = n / d;
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

