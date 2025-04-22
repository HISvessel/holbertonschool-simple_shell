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

	while (*lineptr == ' ') lineptr++; /*added max counter for index i*/
	
	if (*lineptr == '\0' || *lineptr == '\n')
	{
		args [0] = NULL;
		return;
	}

	token = strtok(lineptr, delim);

	while (token != NULL && i < MAX_ARGS -1)
	{
		args[i++] = token;
		token = strtok(NULL, delim);
	}
	args[i] = NULL;
}
