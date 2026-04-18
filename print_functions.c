#include "main.h"

/**
 * print_char - Stores a character into the buffer
 * @args: va_list containing the character
 * @b: Pointer to the output buffer
 *
 * Return: Number of characters stored
 */
int print_char(va_list args, buffer_t *b)
{
	char c;

	c = (char)va_arg(args, int);
	return (buffer_add_char(b, c));
}

/**
 * print_string - Stores a string into the buffer
 * @args: va_list containing the string
 * @b: Pointer to the output buffer
 *
 * Return: Number of characters stored
 */
int print_string(va_list args, buffer_t *b)
{
	char *s;
	int i = 0;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	while (s[i] != '\0')
	{
		buffer_add_char(b, s[i]);
		i++;
	}
	return (i);
}

/**
 * print_percent - Stores a percent sign into the buffer
 * @args: va_list (unused)
 * @b: Pointer to the output buffer
 *
 * Return: 1
 */
int print_percent(va_list args, buffer_t *b)
{
	(void)args;
	return (buffer_add_char(b, '%'));
}

/**
 * get_func - Returns the handler matching the given specifier
 * @s: The format specifier character
 *
 * Return: Pointer to the handler function, or NULL if none match
 */
int (*get_func(char s))(va_list, buffer_t *)
{
	spec_t specs[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{0, NULL}
	};
	int i = 0;

	while (specs[i].func != NULL)
	{
		if (specs[i].specifier == s)
			return (specs[i].func);
		i++;
	}
	return (NULL);
}
