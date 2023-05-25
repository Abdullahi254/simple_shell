#include "main.h"

/**
 * _atoi - converts a string to integer
 * @str: string to convert
 * Return: integer value of converted string
 */
int _atoi(char *str)
{
	int i;
	unsigned int int_num = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			int_num = int_num * 10 + (str[i] - '0');

		if (str[i] > '9' || str[i] < '0')
			return (-1);
	}
	return (int_num);
}
