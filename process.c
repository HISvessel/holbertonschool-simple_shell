#include "shell.h"

/**
 * create_process - Function to create new process using fork
 *
 * Return: Process created
 */

pid_t create_process(void)
{
	pid_t pid = fork();

	if (pid < 0)
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

void execute_program(const char *path, char **args)
{
	if (execve(path, args, environ) == -1)
	{
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
}

/**
 * fork_and_execute - Creates new process and executes command
 * @args: Arguments to execute
 *
 * Return: 0 on sucess
 *
 */
int fork_and_execute(char **args)
{
	pid_t pid = create_process();

	if (pid == 0)
	{
		char *path = getenv("PATH");
		char *full_path = find_executable(args[0], path);

		if (!full_path)
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
		execute_program(full_path, args);
		free(full_path);
	}
	else
		wait(NULL);
	return (0);
}
