#include "main.h"

/**
 * struct format_s - Struct for format specifiers
 * @spec: The format specifier character
 * @func: The function to handle it
 */
typedef struct format_s
{
	char spec;
	int (*func)(va_list);
} format_t;

/**
 * get_func - Returns the function matching the specifier
 * @s: The specifier character
 * @ops: Array of format_t structs
 * Return: Pointer to function, or NULL
 */
int (*get_func(char s, format_t *ops))(va_list)
{
	int i;

	for (i = 0; ops[i].func != NULL; i++)
	{
		if (ops[i].spec == s)
			return (ops[i].func);
	}
	return (NULL);
}

/**
 * _printf - Produces output according to a format
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	int (*func)(va_list);
	format_t ops[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{0, NULL}
	};

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			func = get_func(format[i], ops);
			if (func)
				count += func(args);
			else
			{
				count += write(1, "%", 1);
				count += write(1, &format[i], 1);
			}
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
