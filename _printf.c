#include "main.h"
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;
	int (*func)(va_list);

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				func = print_char;
			else if (format[i] == 's')
				func = print_string;
			else if (format[i] == '%')
				func = print_percent;
			else if (format[i] == 'd' || format[i] == 'i')
				func = print_int;
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
				i++;
				continue;
			}
			count += func(args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
