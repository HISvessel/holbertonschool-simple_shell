#include "shell.h"

/**
 * find_executable - Looks for executable command
 * @command: Command string
 * @path: Commands paths
 *
 * Return: Executable command
 */

char *find_executable(const char *command, const char *path)
{
	char *full_path = NULL;
	char *path_token = strtok((char *)path, ":");

	while (path_token != NULL)
	{
		full_path = malloc(strlen(path_token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc failed");
			exit(EXIT_FAILURE);
		}

		sprintf(full_path, "%s/%s", path_token, command);

		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		path_token = strtok(NULL, ":");

	}
	return (NULL);
}
