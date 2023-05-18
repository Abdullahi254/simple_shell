#include "main.h"
/**
 * execute_command - executes command entered by user
 * @command: command param entered by user
 * Return: void
 */
void execute_command(char *command)
{
	pid_t pid;
	int status, exitStatus, signalStatus;
	char *args[];

	pid = fork();
	if (pid < 0)
		perror("FORK failed");
	else if (pid == 0)
	{
		args = {command, NULL};
		execvp(args[0], args);
		perror("ERROR");
		exit(EXIT_FAILURE);
	}
	waitpid(pid, &status, 0);
	else
	{
		if (WIFSIGNALED(status))
		{
			signalStatus = WTERMSIG(status);

		}
	}
}
