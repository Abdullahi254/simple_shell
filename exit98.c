#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024
/**
 * my_getline - get command line from std input
 * eval - execute command line
 * builtin_command - check if command is a builtin command
 * 
 * Return: 1 when true otherwise,0 when false while running process in background
 */

char *my_getline();
void eval(char *cmdline);
int builtin_command(char **argv);
int main(void)
{
	while (1)
	{
		printf("$ ");
		fflush(stdout);
		char *cmdline = my_getline();

		if (cmdline == NULL)
			exit(0);
		eval(cmdline);
		free(cmdline);
	}
	return (0);
}
/* Custom getline function */
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
				break;
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
void eval(char *cmdline)
{
	char *argv[BUFFER_SIZE];
	char buf[BUFFER_SIZE];
	int bg;
	pid_t pid;
	int i = 1;
	int status;

	strcpy(buf, cmdline);
	argv[0] = strtok(buf, " ");
	while ((argv[i] = strtok(NULL, " ")) != NULL)
	{
		i++;
	}
	bg = (strcmp(argv[i - 1], "&") == 0);
	char *environ;

	if (!builtin_command(argv))
	{
		if ((pid == fork()) == 0)
		{
			if (argv[0][0] == '/')
			{
				execve(argv[0], argv, environ);
			}
			else
			printf("%s: Command not found.\n", argv[0]);
			exit(0);
		}
	}
}
int builtin_command(char **argv)
{
	if (!strcmp(argv[0], "exit"))
	{
		int status = 0;

		if (argv[1] != NULL)
		{
			status = atoi(argv[1]);
		}
		exit(status);
	}
	else if (!strcmp(argv[0], "env"))
	{
		char **env = environ;

		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
		return (1);
	}
	else if (!strcmp(argv[0], "&"))
	{
		return (1);
	}
	return (0);
}
