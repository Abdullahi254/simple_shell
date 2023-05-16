# SIMPLE SHELL
This repository contains a simple shell clone written in C. The project was developed in collaboration with fr13nd-X Gichia, and it aims to provide a basic understanding of how shells work and how they can be implemented using the C programming language.

## FEATURES
The shell clone includes the following features:
1. Display a prompt and wait for the user to type a command. A command line always ends with a new line.
2. The prompt is displayed again each time a command has been executed.
3. The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
4. The command lines are made only of one word. No arguments will be passed to programs.
5. If an executable cannot be found, print an error message and display the prompt again.
6. Handle errors.
7. You have to handle the “end of file” condition (Ctrl+D)

## USAGE
Once you have started the shell, you can enter commands and execute them. The shell will display the output of the executed command, if any.

Here are some examples of commands you can try:

1. Execute a system command:
'''
ls -l
'''

2. Run a built-in command:
'''
cd /path/to/directory
'''

## ACKNOWLEDGEMENTS
We would like to acknowledge the following resources and references that helped in the development of this shell clone:

* [Linux man pages](https://man7.org/linux/man-pages/): Documentation for various system calls and functions used in the shell implementation.
* [Beej's Guide to Unix IPC](https://beej.us/guide/bgipc/): A comprehensive guide to inter-process communication on Unix systems.

## CONTRIBUTORS
1. Abdullahi MOhamud
2. Fr13nd-X Gichia
