#include "main.h"
/**
 * _built_in - function that checks for builtin functions
 * @lineptr: string entered by user
 * @linecmd: array of tokens
 *
 * Return: 0 if builtin found, else -1
 */
int _built_in(char **linecmd, char *lineptr)
{
	void (*func_ptr)(char *);

	func_ptr = _check_builtin(linecmd[0]);
	if (func_ptr == NULL)
		return (-1);

	if (_strcmp("exit", linecmd[0]) == 0)
		custom_free(linecmd);
	func_ptr(lineptr);
	return (0);
}



/**
 * _check_builtin - function that returns the right builtin function
 * @func: builtin function
 *
 * Return: pointer to the function
 */
void (*_check_builtin(char *func))(char *str)
{
	int i;

	built_t built_cmds[] = {
		{"env", _env},
		{"exit", _exit_},
		{NULL, NULL}
	};

	for (i = 0; built_cmds[i].built_in != NULL; i++)
	{
		if (_strcmp(built_cmds[i].built_in, func) == 0)
		{
			return (built_cmds[i].fptr);
		}
	}
	return (NULL);
}

/**
 * custom_free - function that frees an array of strings
 * @str: array of strings
 *
 * Return: nothing
 */
void custom_free(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
