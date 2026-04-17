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
