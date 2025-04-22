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
void parse_inputs(char *input, char **args, const char *delim);
int handle_cd(char **args);
int handle_exit(char **args, int exit_status); /* changed to void as test */
void handle_pipes(char *input);
char *find_executable(const char *command, const char *path);
int fork_and_execute(char **args);
pid_t create_process(void);
void execute_program(char *args[], char *path);
#endif
