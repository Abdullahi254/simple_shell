#include "main.h"
/**
 * _strdup - function name
 * Description: a function that returns a pointer to a
 * newly allocated space in memory
 * which contains a copy of the string given as a parameter.
 * @str: pointer to string
 * Return: returns NULL if str is NULL or a pointer to the duplicated string
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int i;

	if (str == NULL)
		return (NULL);
	duplicate = (char *)malloc(sizeof(char) * (_strlen(str) + 1));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		duplicate[i] = str[i];
	}
	duplicate[i] = '\0';
	return (duplicate);
}
