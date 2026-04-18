#include "main.h"

/**
 * flush_buffer - writes the buffer to stdout and resets index
 * @buf: the buffer
 * @idx: pointer to current index in buffer
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
 * buffer_add - adds a character to buffer, flushes if full
 * @buf: the buffer
 * @idx: pointer to current index
 * @c: character to add
 */
void buffer_add(char *buf, int *idx, char c)
{
	if (*idx >= BUFFER_SIZE)
		flush_buffer(buf, idx);
	buf[*idx] = c;
	(*idx)++;
}

/**
 * _printf - produces output according to a format, using a 1024-char
 *           local buffer to minimize write() syscalls
 * @format: the format string
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	char buf[BUFFER_SIZE];
	int idx = 0;
	int i = 0;
	int count = 0;
	int ret;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				flush_buffer(buf, &idx);
				va_end(args);
				return (-1);
			}
			flush_buffer(buf, &idx);
			ret = handle_specifier(format[i], args, buf, &idx);
			if (ret < 0)
			{
				va_end(args);
				return (-1);
			}
			count += ret;
		}
		else
		{
			buffer_add(buf, &idx, format[i]);
			count++;
		}
		i++;
	}
	flush_buffer(buf, &idx);
	va_end(args);
	return (count);
}
