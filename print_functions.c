#include "main.h"
#include <stdlib.h>

/**
 * print_char - Prints a character
 * @args: va_list of arguments
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
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
 * print_int - Prints an integer
 * @args: va_list of arguments
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
	int n;
	int count = 0;
	int divisor = 1;
	int temp;

	n = va_arg(args, int);
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		if (n == -2147483648)
		{
			write(1, "2147483648", 10);
			return (11);
		}
		n = -n;
	}
	temp = n;
	while (temp >= 10)
	{
		divisor *= 10;
		temp /= 10;
	}
	while (divisor >= 1)
	{
		char digit = '0' + (n / divisor);

		write(1, &digit, 1);
		count++;
		n %= divisor;
		divisor /= 10;
	}
	return (count);
}
