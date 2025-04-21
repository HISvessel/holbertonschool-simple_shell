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
	char *path_copy = strdup(path);
	char *path_token = strtok(path_copy, ":");

	if (!path_copy)
	{
		perror("strdup failed");
		exit(EXIT_FAILURE);
	}
	while (path_token != NULL)
	{
		full_path = malloc(strlen(path_token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc failed");
			free(path_copy);
			exit(EXIT_FAILURE);
		}

		sprintf(full_path, "%s/%s", path_token, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
