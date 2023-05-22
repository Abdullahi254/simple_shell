#include "main.h"
/**
 * main - entry point to the command line
 * Return: always 0
 */
int main(void)
{
	char *buffer = NULL;
	size_t buffer_size;
	char *token;
	char **args;

	while (1)
	{
		prompt();
		if (getline(&buffer, &buffer_size, stdin) == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("./hsh");
				break;
			}
		}
		buffer[strcspn(buffer, "\n")] = '\0';
		if (strlen(buffer) == 0)
		{
			continue;
		}
		token = strtok(buffer, " ");
		if (token != NULL)
		{
			args = malloc(sizeof(char *) * 2);
			args[0] = token;
			args[1] = NULL;
			execute_command(args);
			free(args);
		}
	}
	free(buffer);
	return (0);
}
