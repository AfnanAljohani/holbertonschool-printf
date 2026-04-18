#include "main.h"

/**
 * pr_unsigned - prints unsigned int
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags (unused)
 * Return: count
 */
int pr_unsigned(va_list ap, char *buf, int *idx, flags_t *fl)
{
	unsigned int n = va_arg(ap, unsigned int);

	(void)fl;
	return (print_unumber((unsigned long)n, 10, 0, buf, idx));
}

/**
 * pr_octal - prints unsigned int in octal
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags struct
 * Return: count
 */
int pr_octal(va_list ap, char *buf, int *idx, flags_t *fl)
{
	unsigned int n = va_arg(ap, unsigned int);
	int c = 0;

	if (fl->hash && n != 0)
	{
		add_to_buf(buf, idx, '0');
		c++;
	}
	c += print_unumber((unsigned long)n, 8, 0, buf, idx);
	return (c);
}

/**
 * pr_hex_low - prints unsigned int in lowercase hex
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags struct
 * Return: count
 */
int pr_hex_low(va_list ap, char *buf, int *idx, flags_t *fl)
{
	unsigned int n = va_arg(ap, unsigned int);
	int c = 0;

	if (fl->hash && n != 0)
	{
		add_to_buf(buf, idx, '0');
		add_to_buf(buf, idx, 'x');
		c += 2;
	}
	c += print_unumber((unsigned long)n, 16, 0, buf, idx);
	return (c);
}

/**
 * pr_hex_up - prints unsigned int in uppercase hex
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags struct
 * Return: count
 */
int pr_hex_up(va_list ap, char *buf, int *idx, flags_t *fl)
{
	unsigned int n = va_arg(ap, unsigned int);
	int c = 0;

	if (fl->hash && n != 0)
	{
		add_to_buf(buf, idx, '0');
		add_to_buf(buf, idx, 'X');
		c += 2;
	}
	c += print_unumber((unsigned long)n, 16, 1, buf, idx);
	return (c);
}

/**
 * pr_pointer - prints a pointer address
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags (unused)
 * Return: count
 */
int pr_pointer(va_list ap, char *buf, int *idx, flags_t *fl)
{
	void *p = va_arg(ap, void *);
	int c = 0;

	(void)fl;
	if (p == NULL)
		return (add_str(buf, idx, "(nil)"));
	add_to_buf(buf, idx, '0');
	add_to_buf(buf, idx, 'x');
	c = 2;
	c += print_unumber((unsigned long)p, 16, 0, buf, idx);
	return (c);
}
