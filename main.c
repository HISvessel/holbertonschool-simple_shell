#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * main - a miniature terminal
 * Return: 0 on success
 */
int main(void)
{
	char *prompt = "($) ";
	size_t n = 0;
	ssize_t nchars_read;
	char *args[MAX_ARGS], *lineptr;

	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);

		if (nchars_read == -1)
		{
			perror("getline failed\n");
			free(lineptr);
			exit(EXIT_FAILURE);
		}

		parse_inputs(lineptr, args, " ");

		if (strcmp(args[0], "exit") == 0)
			handle_exit(args);
		else if (strcmp(args[0], "cd") == 0)
			handle_cd(args);
		else
		{
			execute_command(args);
		}
	}
	free(lineptr);
	return (0);
}
