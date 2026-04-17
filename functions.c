#include "main.h"

/**
 * handle_specifier - finds and runs the right handler
 * @c: the format specifier character
 * @args: va_list arguments
 * @buf: the buffer (unused here but for consistency)
 * @idx: pointer to buffer index (unused here)
 * Return: number of characters printed, or prints %x if unknown
 */
int handle_specifier(char c, va_list args, char *buf, int *idx)
{
	int (*func)(va_list);
	int ret;

	(void)buf;
	(void)idx;
	func = get_func(c);
	if (func)
	{
		ret = func(args);
		return (ret);
	}
	write(1, "%", 1);
	write(1, &c, 1);
	return (2);
}

/**
 * get_func - matches specifier to handler function
 * @s: the format specifier character
 * Return: pointer to function or NULL
 */
int (*get_func(char s))(va_list)
{
	int i;
	spec_t specs[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hex_lower},
		{'X', print_hex_upper},
		{'S', print_S},
		{'p', print_pointer},
		{0, NULL}
	};

	for (i = 0; specs[i].func != NULL; i++)
	{
		if (specs[i].specifier == s)
			return (specs[i].func);
	}
	return (NULL);
}
