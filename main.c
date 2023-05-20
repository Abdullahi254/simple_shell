#include "main.h"
/**
 * main - entry point to the command line
 * Return: always 0
 */
int main(void)
{
	char *buffer = NULL;
	size_t buffer_size;
	char *command;

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
		command = strtok(buffer, " ");
		execute_command(command);
		free(buffer);
		return (0);
	}
}
