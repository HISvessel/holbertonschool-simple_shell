#include "shell.h"

/**
 * execute_command - Function to execute commands
 * @args: Argument string in the function
 *
 * Return: Command to execute, 0 on succes, -1 on error
 */

int execute_command(char **args)
{
	int status = fork_and_execute(args);

	if (status == -1)
	{
		fprintf(stderr, "Failed to execute command\n");
		return (-1);
	}
	return (status);
}
