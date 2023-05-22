#include "main.h"
/**
 * get_line - fetches commands from command line
 * @buffer: line argument to be read
 * @buffer_size: size of buffer read
 * Return: 0 for end, -1 for error, 1 for success
 */
char get_line(char **buffer, size_t *buffer_size)
{
	ssize_t char_read;

	if (char_read == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			return (0);
		}
		else
		{
			perror("./hsh");
			return (-1);
		}
	}
	(*buffer)[char_read - 1] = '\0';
	return (1);
}
