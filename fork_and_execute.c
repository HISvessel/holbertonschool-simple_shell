#include "shell.h"

extern char **environ;

/**
 * fork_and_execute - Creates new process and executes command
 * @args: Arguments to execute
 *
 * Return: Exit status of the child process
 */

int fork_and_execute(char **args)
{
	pid_t pid = create_process();

	if (pid == 0)
	{
		int i;
		char *path = NULL;
		char *executable_path;

		if (strchr(args[0], '/') != NULL)
		{
			execve(args[0], args, environ);
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			for (i = 0; environ[i] != NULL; i++)
			{
				if (strncmp(environ[i], "PATH=", 5) == 0)
				{
					path = environ[i] + 5;
					break;
				}
			}

			if (path == NULL)
				path = "/bin:/usr/bin";
			executable_path = find_executable(args[0], path);

			if (executable_path == NULL)
			{
				fprintf(stderr, "Command not found: %s\n", args[0]);
				exit(EXIT_FAILURE);
			}

			execve(executable_path, args, environ);
			perror("execve failed");
			free(executable_path);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Process creation failed");
		return (-1);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
}

