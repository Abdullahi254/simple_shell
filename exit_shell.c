#include "main.h"
/**
 * exit_shell - function that exits the simple shell
 * @lineptr: command line input string from user
 * Return: exit shell if success, -1 if error
 */
void exit_shell(char *lineptr)
{
	int status = 0;
	char **exit_token;
	int token_count = 0;
	const char *delim = "\n\t ";

	exit_token = string_to_token(token_count, lineptr, delim);
	if (exit_token == NULL)
	{
		free(lineptr);
		custom_free(exit_token);
		return;
	}

	if (exit_token[1] != NULL)
	{
		status = _atoi(exit_token[1]);
	}

	if (status == -1)
	{
		perror("Error ");
		custom_free(exit_token);
		return;
	}

	custom_free(exit_token);
	free(lineptr);
	exit(statuscode);
}
