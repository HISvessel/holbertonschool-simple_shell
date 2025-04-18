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
	size_t n = 0;
	ssize_t nchars_read;
	char *args[MAX_ARGS], *token, *lineptr;
	int i;

	(void)ac, (void) argv;

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

		lineptr[strcspn(lineptr, "\n")] = 0;

		token = strtok(lineptr, " ");
		i = 0;

		while (token != NULL && i < MAX_ARGS - 1)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;

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
