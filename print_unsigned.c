#include "main.h"

/**
 * print_unsigned - prints unsigned int
 * @args: va_list containing the argument
 * Return: number of characters printed
 */
int print_unsigned(va_list args)
{
	unsigned int n;
	int count;
	int digits[32];
	int i;

	n = va_arg(args, unsigned int);
	if (n == 0)
		return (_putchar('0'));
	i = 0;
	while (n > 0)
	{
		digits[i] = n % 10;
		n /= 10;
		i++;
	}
	count = 0;
	i--;
	while (i >= 0)
	{
		_putchar('0' + digits[i]);
		count++;
		i--;
	}
	return (count);
}

/**
 * print_octal - prints unsigned int in octal
 * @args: va_list containing the argument
 * Return: number of characters printed
 */
int print_octal(va_list args)
{
	unsigned int n;
	int count;
	int digits[32];
	int i;

	n = va_arg(args, unsigned int);
	if (n == 0)
		return (_putchar('0'));
	i = 0;
	while (n > 0)
	{
		digits[i] = n % 8;
		n /= 8;
		i++;
	}
	count = 0;
	i--;
	while (i >= 0)
	{
		_putchar('0' + digits[i]);
		count++;
		i--;
	}
	return (count);
}

/**
 * print_hex_lower - prints unsigned int in hex lowercase
 * @args: va_list containing the argument
 * Return: number of characters printed
 */
int print_hex_lower(va_list args)
{
	unsigned int n;
	int count;
	int digits[32];
	int i;
	char *hex = "0123456789abcdef";

	n = va_arg(args, unsigned int);
	if (n == 0)
		return (_putchar('0'));
	i = 0;
	while (n > 0)
	{
		digits[i] = n % 16;
		n /= 16;
		i++;
	}
	count = 0;
	i--;
	while (i >= 0)
	{
		_putchar(hex[digits[i]]);
		count++;
		i--;
	}
	return (count);
}

/**
 * print_hex_upper - prints unsigned int in hex uppercase
 * @args: va_list containing the argument
 * Return: number of characters printed
 */
int print_hex_upper(va_list args)
{
	unsigned int n;
	int count;
	int digits[32];
	int i;
	char *hex = "0123456789ABCDEF";

	n = va_arg(args, unsigned int);
	if (n == 0)
		return (_putchar('0'));
	i = 0;
	while (n > 0)
	{
		digits[i] = n % 16;
		n /= 16;
		i++;
	}
	count = 0;
	i--;
	while (i >= 0)
	{
		_putchar(hex[digits[i]]);
		count++;
		i--;
	}
	return (count);
}
