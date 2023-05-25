#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void prompt(void);
int execute_command(char *args[]);
char get_line(char **buffer, size_t *buffer_size);
void print_env(void);
int _strlen(const char *s);
char **tokens_converter(char *str);
unsigned int space_count(char *s);
void _puts(char *str);
int _putchar(char c);
char *path_builder(char *exec_path, char *cmd);
void print_env(void);
extern char **environ;
int _built_in(char **linecmd, char *lineptr);
void (*_check_builtin(char *func))(char *str);
void custom_free(char **str);
int _print_number(int n);
void print_error(char *argv, int i, char *cmd);
void print_error_execve(char *argv, int i, char *cmd);
char *_getpath(char *cmd);
char *_get_full_path(char **tokens, char *cmd);
char **string_to_token(int num_token, char *lineptr, const char *delim);
#endif
