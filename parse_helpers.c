#include "main.h"

/**
 * parse_width - parses field width (number or *)
 * @fmt: format string
 * @i: pointer to current index
 * @ap: va_list for *
 * @fl: flags struct
 * Return: 1 if found, 0 otherwise
 */
int parse_width(const char *fmt, int *i, va_list ap, flags_t *fl)
{
	int found = 0;

	if (fmt[*i] == '*')
	{
		fl->width = va_arg(ap, int);
		if (fl->width < 0)
		{
			fl->minus = 1;
			fl->width = -fl->width;
		}
		(*i)++;
		return (1);
	}
	while (fmt[*i] >= '0' && fmt[*i] <= '9')
	{
		fl->width = fl->width * 10 + (fmt[*i] - '0');
		(*i)++;
		found = 1;
	}
	return (found);
}

/**
 * parse_precision - parses .precision (number or *)
 * @fmt: format string
 * @i: pointer to current index
 * @ap: va_list for *
 * @fl: flags struct
 * Return: 1 if found, 0 otherwise
 */
int parse_precision(const char *fmt, int *i, va_list ap, flags_t *fl)
{
	if (fmt[*i] != '.')
		return (0);
	(*i)++;
	fl->precision = 0;
	if (fmt[*i] == '*')
	{
		fl->precision = va_arg(ap, int);
		(*i)++;
		return (1);
	}
	while (fmt[*i] >= '0' && fmt[*i] <= '9')
	{
		fl->precision = fl->precision * 10 + (fmt[*i] - '0');
		(*i)++;
	}
	return (1);
}

/**
 * num_len - length of signed long in given base
 * @n: number
 * @base: base
 * Return: number of digits (plus sign if negative)
 */
int num_len(long n, int base)
{
	int len = 0;
	unsigned long un;

	if (n < 0)
	{
		len++;
		un = (unsigned long)(-n);
	}
	else
	{
		un = (unsigned long)n;
	}
	if (un == 0)
		return (len + 1);
	while (un > 0)
	{
		un /= (unsigned long)base;
		len++;
	}
	return (len);
}

/**
 * unum_len - length of unsigned long in given base
 * @n: number
 * @base: base
 * Return: number of digits
 */
int unum_len(unsigned long n, int base)
{
	int len = 0;

	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= (unsigned long)base;
		len++;
	}
	return (len);
}

/**
 * pad_output - adds padding characters to buffer
 * @buf: buffer
 * @idx: index
 * @count: number of padding chars
 * @pad: padding character
 * Return: count
 */
int pad_output(char *buf, int *idx, int count, char pad)
{
	int i = 0;

	while (i < count)
	{
		add_to_buf(buf, idx, pad);
		i++;
	}
	return (count);
}
