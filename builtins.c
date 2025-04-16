#include "shell.h"

/**
 * handle_exit - Built in function to exit the shell
 * @args: Argument string for the function
 *
 * Return: Shell exit
 */

int handle_exit(char **args)
{
	free(args);
	exit(0);
}

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
