#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "shell.h"

/**
 * parse_inputs - this parses the inputs
 * @args: strings to take
 * @lineptr: the input of string
 * @delim: line delimiter
 */

void parse_inputs(char *lineptr, char **args, const char *delim)
{
	char *token;
	int i = 0;

	lineptr[strcspn(lineptr, "\n")] = 0; /*new updates from main*/
	token = strtok(lineptr, delim);
	while (token != NULL && i < MAX_ARGS - 1) /*added max counter for index i*/
	{
		args[i++] = token; /*pointer updated to the new token*/
		token = strtok(NULL, delim);
	}
	args[i] = NULL; /* NULL is found */
}
