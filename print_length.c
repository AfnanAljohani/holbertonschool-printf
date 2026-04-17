#include "main.h"

/**
 * print_long - prints long int
 * @args: va_list
 * Return: chars printed
 */
int print_long(va_list args)
{
	long int n;
	unsigned long int num;
	int count = 0;
	char digits[30];
	int i = 0;

	n = va_arg(args, long int);
	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		return (count + _putchar('0'));
	while (num > 0)
	{
		digits[i++] = '0' + (num % 10);
		num /= 10;
	}
	i--;
	while (i >= 0)
	{
		_putchar(digits[i--]);
		count++;
	}
	return (count);
}

/**
 * print_ulong - prints unsigned long
 * @args: va_list
 * @base: the base
 * @upper: uppercase flag
 * Return: chars printed
 */
int print_ulong(va_list args, int base, int upper)
{
	unsigned long int n;
	int count = 0;
	char digits[70];
	int i = 0;
	char *hex;

	if (upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	n = va_arg(args, unsigned long int);
	if (n == 0)
		return (_putchar('0'));
	while (n > 0)
	{
		digits[i++] = hex[n % base];
		n /= base;
	}
	i--;
	while (i >= 0)
	{
		_putchar(digits[i--]);
		count++;
	}
	return (count);
}

/**
 * print_short - prints short int
 * @args: va_list
 * Return: chars printed
 */
int print_short(va_list args)
{
	short int n;
	int num, count = 0;
	char digits[10];
	int i = 0;

	n = (short int)va_arg(args, int);
	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		return (count + _putchar('0'));
	while (num > 0)
	{
		digits[i++] = '0' + (num % 10);
		num /= 10;
	}
	i--;
	while (i >= 0)
	{
		_putchar(digits[i--]);
		count++;
	}
	return (count);
}

/**
 * print_ushort - prints unsigned short
 * @args: va_list
 * @base: the base
 * @upper: uppercase flag
 * Return: chars printed
 */
int print_ushort(va_list args, int base, int upper)
{
	unsigned short int n;
	int count = 0;
	char digits[20];
	int i = 0;
	char *hex;

	if (upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	n = (unsigned short int)va_arg(args, unsigned int);
	if (n == 0)
		return (_putchar('0'));
	while (n > 0)
	{
		digits[i++] = hex[n % base];
		n /= base;
	}
	i--;
	while (i >= 0)
	{
		_putchar(digits[i--]);
		count++;
	}
	return (count);
}
