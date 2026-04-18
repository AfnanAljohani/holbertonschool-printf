#include "main.h"

/**
 * _strlen - returns string length
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int n = 0;

	while (s[n])
		n++;
	return (n);
}

/**
 * print_unumber - prints unsigned long in given base
 * @n: number
 * @base: base
 * @upper: 1 for uppercase hex, 0 for lowercase
 * @buf: buffer
 * @idx: index
 * Return: count printed
 */
int print_unumber(unsigned long n, int base, int upper,
	char *buf, int *idx)
{
	char digits_lo[] = "0123456789abcdef";
	char digits_up[] = "0123456789ABCDEF";
	char *d;
	int count = 0;

	d = upper ? digits_up : digits_lo;
	if (n / (unsigned long)base)
		count += print_unumber(n / (unsigned long)base, base,
			upper, buf, idx);
	add_to_buf(buf, idx, d[n % (unsigned long)base]);
	return (count + 1);
}

/**
 * print_number - prints signed long in given base
 * @n: number
 * @base: base
 * @upper: 1 uppercase, 0 lowercase
 * @buf: buffer
 * @idx: index
 * Return: count printed
 */
int print_number(long n, int base, int upper, char *buf, int *idx)
{
	int count = 0;
	unsigned long un;

	if (n < 0)
	{
		add_to_buf(buf, idx, '-');
		count++;
		un = (unsigned long)(-n);
	}
	else
	{
		un = (unsigned long)n;
	}
	count += print_unumber(un, base, upper, buf, idx);
	return (count);
}
