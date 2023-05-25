#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#define PROMPT "$ "

/**
 * struct built_cmd - Defines the builtins functions.
 * @built_in: The name of the build in command.
 * @fptr: A pointer to the right builtin function.
 */
typedef struct built_cmd
{
	char *built_in;
	void (*fptr)(char *);
} built_t;

int statuscode;
void prompt(void);
int execute_command(char *args[]);
char get_line(char **buffer, size_t *buffer_size);
void print_env(void);
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
int calculate_tokens(char *lineptr, const char *delim);
void exit_shell(char *lineptr);
void _signal_ignore(int sig);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
extern char **environ;
int statuscode;
char *_strcpy(char *dest, char *src);
unsigned int _strlen(char *s);
char *_strdup(char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strcat(char *dest, char *src);
void _prompt(char *lineptr, size_t size, int counter, char **argv);
void _exit_d(char *lineptr);
void _execve(char **linecmd, char *lineptr, int counter, char **argv);
int calculate_tokens(char *lineptr, const char *delim);
char **_parse_to_token(int num_token, char *lineptr, const char *delim);
char *_getenv(char *key);
void (*_check_builtin(char *func))(char *str);
void _env(char *lineptr);
int _built_in(char **linecmd, char *lineptr);
void _signal_ignore(int sig);
void _free_double_ptr(char **str);
void _exit_(char *lineptr);
int _atoi(char *str);
char **_pathtokens(char *str);
char *_exec_path(char **tokens, char *cmd);
char *_build_path(char *e_path, char *cmd);
char *_getpath(char *cmd);
int _putchar(char c);
void _puts(char *str);
int _print_number(int n);
void _error_execve(char *argv, int counter, char *cmd);
void _print_error(char *argv, int counter, char *cmd);
char *update_add_env(char *key, char *value);
int cd_setenv(char *key, char *value, int overwrite);
void _cd(char *lineptr);
void _setenv(char *lineptr);
int cd_home(void);
int cd_cwd(void);
int cd_toggle(void);
int cd_abspath(char *path);
ssize_t _getline(char **lineptr, ssize_t size, FILE *stream);
void status_exec(char **argv);
#endif
