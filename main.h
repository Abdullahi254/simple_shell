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
#endif
