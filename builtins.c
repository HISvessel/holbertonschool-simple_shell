#include "shell.h"

/**
 * handle_exit - Built in function to exit the shell
 * @args: Argument string for the function
 * @exit_status: Current exit status of the shell
 *
 * Return: Shell exit with specified status
 */

int handle_exit(char **args, int exit_status, char *lineptr)
{
	int status = exit_status;

	if (args[1] != NULL)
		status = atoi(args[1]);
	free(lineptr);
	exit(status);
}

/**
 * handle_cd - Hanldes change directory
 * @args: Argument string
 *
 * Return: 0 on Success
 */

int handle_cd(char **args)
{
	if (!args[1])
		fprintf(stderr, "cd: missing argument\n");
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd failed");
		}
	}
	return (1);
}
