# Pipex - 1337 Project

## Description
Pipex is a project that focuses on replicating the behavior of pipes and input/output redirection in a shell. The goal is to implement a program that allows the user to execute multiple commands connected by pipes (`|`) and with input/output redirection (`<`, `>`). 

This project will help you understand how processes, file descriptors, and redirection work at a low level in Unix-like systems.

## Features
- **Pipes**: Implement pipe functionality to connect multiple processes (commands) and pass data between them.
- **Input/Output Redirection**: Implement redirection using `<` for input and `>` for output.
- **Fork and Exec**: Use the `fork()` system call to create child processes and the `execve()` system call to execute the commands in those processes.
- **File Descriptors**: Manage file descriptors to handle standard input, standard output, and files for redirection.
  
## Project Objective
The objective of this project is to implement a simplified version of the shell's behavior when using pipes and redirection. You will need to:
1. Execute multiple commands connected by pipes.
2. Handle file redirection for both input and output.
3. Ensure the correct handling of standard input/output, closing file descriptors, and forking processes.

### Requirements:
- **Pipes**: Implement a program where you can connect multiple commands via pipes.
- **Redirection**: Handle input (`<`) and output (`>`) redirection.
- **Process Management**: Use `fork()` and `execve()` to manage the execution of commands.

## Installation

### Prerequisites:
- A Linux or macOS system with GCC or Clang installed.
- **Make** should be available to build the project.

### Clone the repository:
```bash
git clone https://github.com/yourusername/pipex.git
cd pipex
make
./pipex file1 cmd1 cmd2 file2
