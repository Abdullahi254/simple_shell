#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024
/**
 * my_getline - takes in the standard input from commandline
 * fflush - flush the output buffer
 *
 */

char *my_getline()
{
	char buffer[BUFFER_SIZE];
	int buffer_pos = 0;
	int buffer_size = 0;
	char *line = NULL;
	int line_pos = 0;

	while (1)
	{
		if (buffer_pos >= buffer_size)
		{
			int bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);

			if (bytes_read <= 0)
			{
				break;
			}
			buffer_pos = 0;
			buffer_size = bytes_read;
		}
		char current_char = buffer[buffer_pos++];
		
		if (current_char == '\n' || current_char == '\0')
		{
			line = realloc(line, (line_pos + 1) * sizeof(char));
			line[line_pos] = '\0';
			break;
		}
		line = realloc(line, (line_pos + 1) * sizeof(char));
		line[line_pos++] = current_char;
	}
	return (line);
}
int main(void)
{
	while (1)
	{
		printf("$ ");
		fflush(stdout);
		char *line = my_getline();

		printf(" %s\n", line);
		free(line);
	}
	return (0);
}
