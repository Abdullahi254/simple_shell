#include "main.h"
/**
 * tokens_converter - tokenizes strings
 * @str: string passed as argument
 * Returns: array of tokens
 */
char ** tokens_converter(char *str)
{
	int count;
	int size;
	char **tokens;
	char *token;

	size = space_count(str) + 1;
	tokens = malloc(sizeof(char *) * size);
	if(!tokens)
	{
		fprintf(stderr, "sh: allocation error\n");
		exit(1);
	}
	token = strtok(str, " ");
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, separator);
	}
	tokens[i] = NULL;
	return (tokens);
}
