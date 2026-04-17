#include "main.h"

/**
 * print_unsigned - prints unsigned int using single write
 * @args: va_list
 * Return: chars printed
 */
int print_unsigned(va_list args)
{
	unsigned int n;
	char buf[12];
	int i = 11;
	int count;

	n = va_arg(args, unsigned int);
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		buf[i--] = '0' + (n % 10);
		n /= 10;
	}
	count = 11 - i;
	write(1, &buf[i + 1], count);
	return (count);
}

/**
 * print_octal - prints octal using single write
 * @args: va_list
 * Return: chars printed
 */
int print_octal(va_list args)
{
	unsigned int n;
	char buf[16];
	int i = 15;
	int count;

	n = va_arg(args, unsigned int);
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		buf[i--] = '0' + (n % 8);
		n /= 8;
	}
	count = 15 - i;
	write(1, &buf[i + 1], count);
	return (count);
}

/**
 * print_hex_lower - prints hex lowercase using single write
 * @args: va_list
 * Return: chars printed
 */
int print_hex_lower(va_list args)
{
	unsigned int n;
	char buf[16];
	int i = 15;
	int count;
	char *hex = "0123456789abcdef";

	n = va_arg(args, unsigned int);
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		buf[i--] = hex[n % 16];
		n /= 16;
	}
	count = 15 - i;
	write(1, &buf[i + 1], count);
	return (count);
}

/**
 * print_hex_upper - prints hex uppercase using single write
 * @args: va_list
 * Return: chars printed
 */
int print_hex_upper(va_list args)
{
	unsigned int n;
	char buf[16];
	int i = 15;
	int count;
	char *hex = "0123456789ABCDEF";

	n = va_arg(args, unsigned int);
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		buf[i--] = hex[n % 16];
		n /= 16;
	}
	count = 15 - i;
	write(1, &buf[i + 1], count);
	return (count);
}
