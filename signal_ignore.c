#include "main.h"
/**
 * signal_ignore - function that ignores ^C (SIGINT) to the process
 * @sig: integer value of signal
 * Return: void
 */

void signal_ignore(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
