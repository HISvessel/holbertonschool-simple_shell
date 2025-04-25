# C - Simple Shell

A lightweight UNIX command interpreter replicating basic shell functionalities.

## Table of Contents
- [Introduction](#introduction)
- [Key Concepts](#key-concepts)
- [Built-in Commands](#built-in-commands)
- [External Commands](#external-commands)
- [System Calls & Functions](#system-calls--functions)
- [Allowed Functions](#allowed-functions)
- [Usage](#usage)
- [Error Handling](#error-handling)
- [Authors](#authors)

## Introduction

### What is a Shell?
A shell is a command-line interface that acts as a bridge between users and the operating system kernel. It interprets user commands and manages program execution.

### This Implementation
Our custom shell (`hsh`) handles:
- Basic command execution
- Built-in functions
- External functions
- Environment variable management
- Process control
- Error handling
- PATH resolution

## Key Concepts

### PID & PPID
- **PID**: Unique Process IDentifier for each running process
- **PPID**: Parent Process ID - the PID of the process that created this one

### Process Management
- **fork()**: Creates child processes
- **execve()**: Replaces current process with new program
- **wait()/waitpid()**: Synchronize parent-child execution

### Environment Manipulation
Access and modify environment variables with direct access via `extern char **environ`.

### PATH Resolution
The shell searches for executables in directories listed in the `PATH` environment variable.

### Function vs System Call
- **Function**: Predefined routine in a library
- **System Call**: Direct request to the OS kernel (e.g., `read()`, `write()`)

### Compilation
- `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

### Main Prototypes
Three valid `main` signatures:
1. `int main(void)`
2. `int main(int argc, char *argv[])`
3. `int main(int argc, char *argv[], char *envp[])`


## Built-in Commands

- `exit [status]` - Exit the shell

- `env` - Show the current environment variables

- `cd [dir]` - Change the current directory

- `ls` - List directory contents

- `touch [file]` - Create an empty file or update the timestamp of an existing file

- `cat [file]` - Concatenate and display file content


## External Commands

External commands are executable files located in the filesystem. Some common external commands include:

- `ls` - List directory contents

- `touch` - Create an empty file or update the timestamp of an existing file

- `cat` - Concatenate and display file content

- `cp` - Copy files and directories

- `mv` - Move or rename files and directories

- `rm` - Remove files or directories


## System Calls & Functions

| Component          | Key Functions                          | Description                              |
|--------------------|----------------------------------------|------------------------------------------|
| Process Creation   | `fork()`, `waitpid()`                  | Create and manage child processes        |
| Program Execution  | `execve()`                             | Execute external programs                |
| Input Handling     | `getline()`, `read()`                  | Read user input                          |
| Directory Handling | `chdir()`, `getcwd()`                  | Navigate filesystem                      |
| Memory Management  | `malloc()`, `free()`                   | Handle dynamic memory                    |
| File Operations    | `open()`, `close()`, `stat()`          | File system interactions                 |

### Allowed Functions

#### String Handling
`strtok`, `strcpy`, `strlen`, `strcmp`, `strcat`, `strchr`, `strstr`, `memcpy`, `memmove`, `memset`, `memcmp`, `sprintf`, `snprintf`, `vsprintf`, `vsnprintf`

#### Memory Management
`malloc`, `free`

#### Process Control
`fork`, `execve`, `wait`, `waitpid`, `wait3`, `wait4`

#### File Operations
`open`, `close`, `read`, `write`, `stat`, `lstat`, `fstat`

#### Directory Operations
`chdir`, `getcwd`, `opendir`, `readdir`, `closedir`

#### System Information
`getpid`, `isatty`, `kill`

#### Error Handling
`perror`, `exit`, `_exit`, `fflush`
- ### Implementation
  - **Command Errors**:  
  ```c
  fprintf(stderr, "./hsh: 1: %s: not found\n", command);
  ```
  Generated when `execve()` fails to execute a command (exit code `127`).

- **Fork Failures**:  
  ```c
  perror("Error");
  ```
  Used for system call failures (e.g., `fork()` returns `-1`).

- **File Errors**:  
  ```c
  fprintf(stderr, "ls: cannot access '%s': No such file or directory\n", filename);
  ```
  Displayed for missing files/directories (mimics `bash` behavior).
#### Input/Output
`printf`, `fprintf`, `vfprintf`, `putchar`

## Usage
**Interactive Mode:**
```bash
$ ./hsh
($) ls
file1 file2 hsh
($) exit
```

**Non-interactive Mode:**
```bash
echo "ls -l" | ./hsh
```

## Authors
Josniel Ramos - [josnielramos@gmail.com]

Kevin Sanchez - [kevinsanchezdabest@yahoo.com]
