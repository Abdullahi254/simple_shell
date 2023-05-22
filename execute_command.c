#include "main.h"
/**
 * execute_command - executes command entered by user
 * @cmd: command entered by user
 * @args: argument or arguments  param entered by user
 * Return: void
 */
void execute_command(char *cmd, char *args[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("./hsh");
	}
	else if (pid == 0)
	{
		if (execvp(cmd, args) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status))
			WTERMSIG(status);
		else if (WIFEXITED(status))
			WEXITSTATUS(status);
	}
}
