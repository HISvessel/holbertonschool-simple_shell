# C - Simple Shell

A lightweight UNIX command interpreter replicating basic shell functionalities.

## Table of Contents
- [Introduction](#introduction)
- [Key Concepts](#key-concepts)
- [Features](#features)
- [System Calls & Functions](#important-system-calls--functions)
- [Allowed Functions](#allowed-functions)
- [Compilation](#compilation)
- [Usage](#usage)
- [Authors](#authors)

## Introduction

### What is a Shell?
A shell is a command-line interface that acts as a bridge between users and the operating system kernel. It interprets user commands and manages program execution.

### This Implementation
Our custom shell (`hsh`) handles:
- Basic command execution
- Built-in functions
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
Access and modify environment variables using `getenv`, `setenv`, and direct access via `extern char **environ`.

### PATH Resolution
The shell searches for executables in directories listed in the `PATH` environment variable.

### Function vs System Call
- **Function**: Predefined routine in a library
- **System Call**: Direct request to the OS kernel (e.g., `read()`, `write()`)

### Main Prototypes
Three valid `main` signatures:
1. `int main(void)`
2. `int main(int argc, char *argv[])`
3. `int main(int argc, char *argv[], char *envp[])`

## Features
- Built-in commands: `exit`, `env`, `cd`
- Command history (up/down arrow support)
- PATH resolution
- Error handling with meaningful messages
- Signal handling (Ctrl+C)
- Basic scripting capability

## Important System Calls & Functions

