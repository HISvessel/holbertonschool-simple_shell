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
	int exit_status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("($) ");
			fflush(stdout);
		}
		nchars_read = getline(&lineptr, &n, stdin);

		if (nchars_read == -1)
		{
			free(lineptr);
			exit(exit_status); /* checking for success, not fail */
		}
		lineptr[strcspn(lineptr, "\n")] = 0;
		parse_inputs(lineptr, args, " ");

		if (args[0] == NULL || args[0][0] == '\0')
			continue;

		if (strcmp(args[0], "exit") == 0)
			handle_exit(args, exit_status, lineptr);
		else if (strcmp(args[0], "cd") == 0)
			handle_cd(args);
		else
		{
			exit_status = execute_command(args);
		}
		free(lineptr);
		lineptr = NULL;
		n = 0; /*RESET BUFFER SIZE*/
	}
	/*free(lineptr);
	return (0);*/
}
