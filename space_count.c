#include "main.h"

/**
 * space_count - return the number of spaces in a string
 * @s: string to check
 * Return: int
 */

unsigned int space_count(char *s)
{
	int i, count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i]  == ' ')
			count++;
	}

	return (count);
}
