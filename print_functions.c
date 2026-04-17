#include "main.h"

/**
 * print_char - prints a character
 * @args: va_list containing the character
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @args: va_list containing the string
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str;
	int i;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		;
	return (write(1, str, i));
}

/**
 * print_percent - prints a percent sign
 * @args: va_list (unused)
 * Return: 1
 */
int print_percent(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}

/**
 * print_int - prints an integer using single write
 * @args: va_list containing the integer
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n;
	unsigned int num;
	char buf[12];
	int i = 11;
	int count = 0;
	int neg = 0;

	n = va_arg(args, int);
	if (n < 0)
	{
		neg = 1;
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		buf[i--] = '0';
	while (num > 0)
	{
		buf[i--] = '0' + (num % 10);
		num /= 10;
	}
	if (neg)
		buf[i--] = '-';
	count = 11 - i;
	write(1, &buf[i + 1], count);
	return (count);
}

/**
 * print_int_helper - helper (kept for compatibility)
 * @n: the number
 * Return: 0
 */
int print_int_helper(unsigned int n)
{
	(void)n;
	return (0);
}
