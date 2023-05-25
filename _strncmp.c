#include "main.h"
/**
 * _strncmp - function to compare n bytes form string
 * pointed by s2 with s1
 * @s1: pointer to string 1
 * @s2: pointer to string 2
 * @n: number of bytes to compare
 * Return: 0 if s1 and s2 are equal
 * negative integer if s1 is less that s2
 * positive integer if s1 is greater than s2
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	else
		return (s1[i] - s2[i]);
}
