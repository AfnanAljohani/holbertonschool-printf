#include "main.h"

/**
 * flush_buffer - writes buffer to stdout and resets index
 * @buf: the local buffer
 * @idx: pointer to current index
 */
void flush_buffer(char *buf, int *idx)
{
	if (*idx > 0)
	{
		write(1, buf, *idx);
		*idx = 0;
	}
}

/**
 * add_to_buf - adds a char to buffer, flushes when full
 * @buf: local buffer
 * @idx: pointer to current index
 * @c: character to add
 */
void add_to_buf(char *buf, int *idx, char c)
{
	if (*idx >= BUF_SIZE)
		flush_buffer(buf, idx);
	buf[*idx] = c;
	(*idx)++;
}

/**
 * add_str - adds a string to buffer
 * @buf: local buffer
 * @idx: pointer to current index
 * @s: string to add
 * Return: number of chars added
 */
int add_str(char *buf, int *idx, char *s)
{
	int n = 0;

	if (s == NULL)
		s = "(null)";
	while (s[n])
	{
		add_to_buf(buf, idx, s[n]);
		n++;
	}
	return (n);
}

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of chars printed, -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char buf[BUF_SIZE];
	int idx = 0, count = 0, i = 0, r;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			add_to_buf(buf, &idx, format[i]);
			count++;
			i++;
			continue;
		}
		r = handle_format(format, &i, ap, buf, &idx);
		if (r == -1)
		{
			flush_buffer(buf, &idx);
			va_end(ap);
			return (-1);
		}
		count += r;
	}
	flush_buffer(buf, &idx);
	va_end(ap);
	return (count);
}
