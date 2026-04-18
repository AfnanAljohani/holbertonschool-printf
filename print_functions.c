#include "main.h"

/**
 * print_char - prints a character (buffered)
 * @args: va_list containing the character
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char buf[BUFFER_SIZE];
	int idx = 0;

	buf[idx++] = (char)va_arg(args, int);
	write(1, buf, idx);
	return (idx);
}

/**
 * print_string - prints a string (buffered, flushes every 1024 chars)
 * @args: va_list containing the string
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str;
	char buf[BUFFER_SIZE];
	int idx = 0;
	int count = 0;
	int i;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		if (idx >= BUFFER_SIZE)
		{
			write(1, buf, idx);
			count += idx;
			idx = 0;
		}
		buf[idx++] = str[i];
	}
	if (idx > 0)
	{
		write(1, buf, idx);
		count += idx;
	}
	return (count);
}

/**
 * print_percent - prints a percent sign (buffered)
 * @args: va_list (unused)
 * Return: 1
 */
int print_percent(va_list args)
{
	char buf[BUFFER_SIZE];
	int idx = 0;

	(void)args;
	buf[idx++] = '%';
	write(1, buf, idx);
	return (idx);
}

/**
 * print_int - prints an integer (buffered, single write)
 * @args: va_list containing the integer
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n;
	unsigned int num;
	char buf[BUFFER_SIZE];
	int i = BUFFER_SIZE - 1;
	int count;
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
	count = (BUFFER_SIZE - 1) - i;
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

/**
 * print_binary - prints unsigned int in binary (buffered, single write)
 * @args: va_list containing the unsigned int
 * Return: number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int n;
	char buf[BUFFER_SIZE];
	int i = BUFFER_SIZE - 1;
	int count;

	n = va_arg(args, unsigned int);
	if (n == 0)
	{
		buf[i--] = '0';
	}
	while (n > 0)
	{
		buf[i--] = '0' + (n % 2);
		n /= 2;
	}
	count = (BUFFER_SIZE - 1) - i;
	write(1, &buf[i + 1], count);
	return (count);
}
