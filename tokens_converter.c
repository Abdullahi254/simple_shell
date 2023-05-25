#include "main.h"
/**
 * tokens_converter - creates token from string
 * @str: string passed as argument
 * Return: array of tokens
 */
char **tokens_converter(char *str)
{
	int count = 0;
	char **tokens;
	const char *delim = "\n:";

	str = getenv("PATH");
	tokens = string_to_token(count, str, delim);
	if (tokens == NULL)
		return (NULL);

	return (tokens);
}

