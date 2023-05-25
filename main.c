#include "main.h"
/**
 * main - entry point to the command line
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: always 0
 */
int main(int argc, char **argv)
{
	char *buffer = NULL;
	size_t buffer_size = BUFSIZ;
	char **tokens;
	int status;
	int is_pipe;

	is_pipe = 0;
	if (argc >= 2)
	{
		if (execve(argv[1], argv, NULL) == -1)
		{
			perror("Error");
			exit(-1)
		}
		return (0);
	}
	buffer = (char *)malloc(buffer_size * sizeof(char));
	if (buffer == NULL)
	{
		perror("Buffer allocation error");
		exit(1);
	}
	do {
		if (isatty(fileno(stdin)))
		{
			is_pipe = 1;
			_puts("cisfun#: ");
			
		}
		getline(&buffer, &buffer_size, stdin);
		buffer[_strlen(buffer) - 1] = '\0';
		tokens = tokens_converter(buffer);
		status = execute_command(tokens);
	}while (is_pipe && status != -1);
	return (0)
}
