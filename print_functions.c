#include "main.h"

/**
 * print_char - Prints a character
 * @args: va_list of arguments
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Prints a string
 * @args: va_list of arguments
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *s;
	int i = 0;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

/**
 * print_percent - Prints a percent sign
 * @args: va_list (unused)
 * Return: 1
 */
int print_percent(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}

/**
 * print_binary - Prints an unsigned int in binary
 * @args: va_list of arguments
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int n;
	unsigned int bits[32];
	int i;
	int count;

	n = va_arg(args, unsigned int);
	i = 0;
	count = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		bits[i] = n % 2;
		n /= 2;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, bits[i] ? "1" : "0", 1);
		count++;
		i--;
	}
	return (count);
}

/**
 * print_int - prints an integer
 * @args: va_list containing the integer
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n;
	int count;
	unsigned int num;

	n = va_arg(args, int);
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
		num = n;
	if (num / 10)
		count += print_int_helper(num / 10);
	_putchar('0' + (num % 10));
	count++;
	return (count);
}

/**
 * print_int_helper - helper to print digits recursively
 * @n: the number
 * Return: number of digits printed
 */
int print_int_helper(unsigned int n)
{
	int count;

	count = 0;
	if (n / 10)
		count += print_int_helper(n / 10);
	_putchar('0' + (n % 10));
	count++;
	return (count);
}
