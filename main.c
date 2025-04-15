#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * shell - a miniature terminal
 * @argc: void
 * @argv: void
 * return: 0 on success
 */
int main(int ac, char **argv)
{
	char *prompt = "($) ";
	char *lineptr;
	size_t n = 0;
	ssize_t nchars_read;

	(void)ac; (void)argv;

	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);

		if (nchars_read == -1)
		{
			printf("Exiting shell...\n");
			return (-1);
		}

		printf("%s\n", lineptr);

		free (lineptr);
	}
	return (0);
}
