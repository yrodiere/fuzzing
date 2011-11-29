#include <stdlib.h>
#include <stdio.h>

void foo ()
{
	char buffer[20];

	printf("Input: ");
	// Buffer overflow here if message longer than 19 characters
	scanf("%s",buffer);
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

