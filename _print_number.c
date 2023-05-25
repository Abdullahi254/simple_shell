/**
 * _print_number - prints integer to standard output
 * @n: number to be printed
 * Return: count of numbers printed
 */
int _print_number(int n)
{
	int div = 1;
	int count;
	unsigned int num;

	div = 1;
	count = 0;

	num = n;

	while (num / div > 9)
		div *= 10;

	while (div != 0)
	{
		count += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (count);
}
