#include "main.h"
/**
 * tokens_converter - creates token from string
 * @str: string passed as argument
 * Return: array of tokens
 */
char **tokens_converter(char *str)
{
	int count;
	int size;
	char **tokens;
	char *token;

	count = 0;
	size = space_count(str) + 1;
	tokens = malloc(sizeof(char *) * size);
	if (!tokens)
	{
		fprintf(stderr, "sh: allocation error\n");
		exit(1);
	}
	token = strtok(str, " ");
	while (token != NULL)
	{
		tokens[count] = token;
		token = strtok(NULL, " ");
		count++;
	}
	tokens[count] = NULL;
	return (tokens);
}
