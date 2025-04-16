#include "shell.h"

/**
 * execute_command - Receives command to execute
 * @argv: Array of command and args to execute
 */
extern char **environ;

int execute_command(char **args)
{
	pid_t pid;
	char *path = getenv("PATH");
	char *full_path = NULL;
	char *path_token;

	pid = fork();
	if (pid == 0)
	{
		path_token = strtok(path, ":");

		while (path_token != NULL)
		{
			full_path = malloc(strlen(path_token) + strlen(args[0]) + 2);
			if (full_path == NULL)
			{
				perror("malloc failed");
				exit(EXIT_FAILURE);
			}

			sprintf(full_path, "%s/%s", path_token, args[0]);

			if (access(full_path, X_OK) == 0)
			{
				if (execve(full_path, args, environ) == -1)
					perror("Error executing command");
				free(full_path);
				exit(EXIT_FAILURE);
			}

			free(full_path);
			path_token = strtok(NULL, ":");
		}

		fprintf(stderr, "%s: command not found\n", args[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Fork failed");
		return (-1);
	}
	else
	{
		wait(NULL);
	}
	return(0);
}
