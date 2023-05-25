#include "main.h"
/**
 * string_to_token - converts string to tokens
 * @num_token: number of token returned by the function calculate_token
 * @lineptr: pointer to the command to be tokenized
 * @delim: the delimiter between tokens
 * Return: array of tokens to be passed to the execve function
 */
char **string_to_token(int num_token, char *lineptr, const char *delim)
{
	char **arr_t;
	int i = 0;
	char *line_copy, *token;

	line_copy = _strdup(lineptr);
	if (line_copy == NULL)
		return (NULL);

	num_token = calculate_tokens(lineptr, delim);
	if (num_token == -1)
	{
		free(lineptr);
		return (NULL);
	}
	arr_t = malloc(sizeof(char *) * (num_token + 1));
	if (arr_t == NULL)
		return (NULL);

	token = strtok(line_copy, delim);
	while (token != NULL)
	{
		arr_t[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	arr_t[i] = NULL;
	if (arr_t == NULL)
	{
		free(lineptr);
		return (NULL);
	}
	free(line_copy);
	return (arr_t);
}