#include "shell.h"

/**
 * handle_exit - Built in function to exit the shell
 * @args: Argument string for the function
 *
 * Return: Shell exit
 */

int handle_exit(char **args)
{
<<<<<<< HEAD
	int status = 0; /* sends a status to args */
	if (args[1]) /* if the argument placed is not null*/
	{
		status = atoi(args[1]); /* converts argument to value*/
	}
=======
	int status = 0;

	while (args[1])
		status = atoi(args[1]);
>>>>>>> main
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
