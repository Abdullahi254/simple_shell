#include "main.h"
/**
 * execute_command - executes command entered by user
 * @args: argument or arguments  param entered by user
 * Return: 0 on success, -1 on exit and 1  when error
 */
int execute_command(char *args[])
{
	pid_t pid;
	int status;

	if (strncmp("exit", args[0], 4) == 0)
		return (-1);
	pid = fork();
	if (pid < 0)
	{
		perror("Error");
		return(1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
	}
	else
		wait(&status);
	return (0);
}
