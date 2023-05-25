/**
 * print_error_execve - function that prints error message if
 * execve() fails
 * @argv: vector
 * @i: counter
 * @cmd: command in question
 */
void print_error_execve(char *argv, int i, char *cmd)
{
	print_error(argv, i, cmd);
	_puts(": ");
	perror("");
	exit(1);
}
