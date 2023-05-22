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
	int count;

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
		args = malloc(sizeof(char *));
		count = 0;
		token = strtok(buffer, " ");
		while (token != NULL)
		{
			args = realloc(args, sizeof(char *) * (count + 2));
			if (args == NULL)
			{
				perror("./hsh");
				exit(EXIT_FAILURE)
			}
			args[count] = token;
			args[count + 1] = NULL;
			count++;
			token = strtok(NULL, " ")
		}
		execute_command(args);
		free(args);
	}
	free(buffer);
	return (0);
}
