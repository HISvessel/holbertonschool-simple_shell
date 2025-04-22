#include "shell.h"

/**
 * main - a miniature terminal
 * Return: 0 on success
 */
int main(void)
{
	size_t n = 0;
	ssize_t nchars_read;
	char *args[MAX_ARGS], *lineptr = NULL;

	while (1)
	{
		printf("($) ");
		fflush(stdout);

		nchars_read = getline(&lineptr, &n, stdin);

		if (nchars_read == -1)
		{
			if(feof(stdin))
			{
				free(lineptr);
				write(STDOUT_FILENO, "\n", 1);
				exit(EXIT_SUCCESS);
			}
			perror("getline failed\n");
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		lineptr[strcspn(lineptr, "\n")] = 0;
		parse_inputs(lineptr, args, " ");

		if (strcmp(args[0], "exit") == 0)
			handle_exit(args);
		else if (strcmp(args[0], "cd") == 0)
			handle_cd(args);
		else if (args[0][0] != '\0')
		{
			execute_command(args);
		}
	}
	free(lineptr);
	return (0);
}
