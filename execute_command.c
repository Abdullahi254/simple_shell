#include "main.h"
/**
 * execute_command - executes command entered by user
 * @args: command param entered by user
 * Return: void
 */
void execute_command(char *args[])
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
		if (execvp(args[0], args) == -1)
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
