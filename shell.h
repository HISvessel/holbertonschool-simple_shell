#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define COMMAND_SIZE 1024
#define MAX_ARGS 100

int execute_command(char **args);
void parse_input(char *input, char **args);
int handle_cd(char **args);
int handle_exit(char **args);
void handle_pipes(char *input);

#endif
