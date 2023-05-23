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
	int count, status;

	while (1)
	{
		prompt();
		status = get_line(&buffer, &buffer_size);
		if (status == -1)
			break;
		else if (status == 0)
			break;
		if (strlen(buffer) == 0)
			continue;
		if (strcmp(buffer, "exit") == 0)
			break;
		args = malloc(sizeof(char *));
		count = 0;
		token = strtok(buffer, " ");
		while (token != NULL)
		{
			args = realloc(args, sizeof(char *) * (count + 2));
			if (args == NULL)
			{
				perror("./hsh");
				exit(EXIT_FAILURE);
			}
			args[count] = token;
			args[count + 1] = NULL;
			count++;
			token = strtok(NULL, " ");
		}
		execute_command(args);
		free(args);
	}
	free(buffer);
	return (0);
}
