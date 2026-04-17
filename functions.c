#include "main.h"

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
		{0, NULL}
	};

	for (i = 0; specs[i].func != NULL; i++)
	{
		if (specs[i].specifier == s)
			return (specs[i].func);
	}
	return (NULL);
}
