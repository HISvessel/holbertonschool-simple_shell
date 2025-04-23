#include "shell.h"

extern char **environ;
/**
 * create_process - Function to create new process using fork
 *
 * Return: Process created
 */

pid_t create_process(void)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	return (pid);
}
/**
 * execute_program - Looks for programs to execute
 * @path: path to search
 * @args: Arguments in function
 */

void execute_program(char *args[], char *path)
{

	if (path == NULL || args == NULL)
	{
		fprintf(stderr, "Invalid arguments: path or args is NULL\n");
		exit(EXIT_FAILURE);
	}
	if (execve(path, args, environ) == -1)
	{
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
}

