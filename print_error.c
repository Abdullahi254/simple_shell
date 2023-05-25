#include "main.h"
/**
 * print_error - prints error when command is not found
 * @argv: vector
 * @i: counter
 * @cmd: command in question
 */
void print_error(char *argv, int i, char *cmd)
{
	_puts(argv);
	_puts(": ");
	_print_number(i);
	_puts(": ");
	_puts(cmd);
}
