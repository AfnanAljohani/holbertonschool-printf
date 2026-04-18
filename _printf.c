#include "main.h"

/**
 * _printf - Produces output according to a format, using a local 1024-byte
 *           buffer to minimize the number of write() syscalls
 * @format: The format string
 *
 * Return: Number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	buffer_t b;
	int i = 0, count = 0;
	int (*func)(va_list, buffer_t *);

	if (format == NULL)
		return (-1);

	b.len = 0;
	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			func = get_func(format[i]);
			if (func != NULL)
			{
				count += func(args, &b);
			}
			else
			{
				count += buffer_add_char(&b, '%');
				count += buffer_add_char(&b, format[i]);
			}
		}
		else
		{
			count += buffer_add_char(&b, format[i]);
		}
		i++;
	}

	va_end(args);
	buffer_flush(&b);
	return (count);
}
