#include "main.h"

/**
 * pr_char - prints a char
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags (unused)
 * Return: 1
 */
int pr_char(va_list ap, char *buf, int *idx, flags_t *fl)
{
	(void)fl;
	add_to_buf(buf, idx, (char)va_arg(ap, int));
	return (1);
}

/**
 * pr_string - prints a string
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags (unused)
 * Return: length printed
 */
int pr_string(va_list ap, char *buf, int *idx, flags_t *fl)
{
	(void)fl;
	return (add_str(buf, idx, va_arg(ap, char *)));
}

/**
 * pr_percent - prints a literal %
 * @ap: va_list (unused)
 * @buf: buffer
 * @idx: index
 * @fl: flags (unused)
 * Return: 1
 */
int pr_percent(va_list ap, char *buf, int *idx, flags_t *fl)
{
	(void)ap;
	(void)fl;
	add_to_buf(buf, idx, '%');
	return (1);
}

/**
 * pr_int - prints an integer
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags struct
 * Return: count printed
 */
int pr_int(va_list ap, char *buf, int *idx, flags_t *fl)
{
	int n = va_arg(ap, int);
	int count = 0;

	if (n >= 0)
	{
		if (fl->plus)
		{
			add_to_buf(buf, idx, '+');
			count++;
		}
		else if (fl->space)
		{
			add_to_buf(buf, idx, ' ');
			count++;
		}
	}
	count += print_number((long)n, 10, 0, buf, idx);
	return (count);
}

/**
 * pr_binary - prints integer in binary
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags (unused)
 * Return: count printed
 */
int pr_binary(va_list ap, char *buf, int *idx, flags_t *fl)
{
	unsigned int n = va_arg(ap, unsigned int);

	(void)fl;
	return (print_unumber((unsigned long)n, 2, 0, buf, idx));
}
