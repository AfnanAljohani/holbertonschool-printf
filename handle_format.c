#include "main.h"

/**
 * get_handler - returns handler for a specifier
 * @c: specifier character
 * Return: function pointer or NULL
 */
static int (*get_handler(char c))(va_list, char *, int *, flags_t *)
{
	conv_t table[] = {
		{'c', pr_char}, {'s', pr_string}, {'%', pr_percent},
		{'d', pr_int}, {'i', pr_int}, {'b', pr_binary},
		{'u', pr_unsigned}, {'o', pr_octal},
		{'x', pr_hex_low}, {'X', pr_hex_up},
		{'p', pr_pointer},
		{'S', pr_S}, {'r', pr_rev}, {'R', pr_rot13},
		{0, NULL}
	};
	int k = 0;

	while (table[k].spec)
	{
		if (table[k].spec == c)
			return (table[k].f);
		k++;
	}
	return (NULL);
}

/**
 * parse_flags - parses +, space, # flags
 * @fmt: format string
 * @i: pointer to current index (advanced past flags)
 * @fl: flags struct to fill
 * Return: 1 if any flag found, 0 otherwise
 */
int parse_flags(const char *fmt, int *i, flags_t *fl)
{
	int found = 0;

	fl->plus = 0;
	fl->space = 0;
	fl->hash = 0;
	fl->l = 0;
	fl->h = 0;
	while (fmt[*i] == '+' || fmt[*i] == ' ' || fmt[*i] == '#')
	{
		if (fmt[*i] == '+')
			fl->plus = 1;
		else if (fmt[*i] == ' ')
			fl->space = 1;
		else
			fl->hash = 1;
		(*i)++;
		found = 1;
	}
	return (found);
}

/**
 * parse_length - parses l/h length modifiers
 * @fmt: format string
 * @i: pointer to current index (advanced past modifiers)
 * @fl: flags struct to fill
 * Return: 1 if modifier found, 0 otherwise
 */
int parse_length(const char *fmt, int *i, flags_t *fl)
{
	int found = 0;

	while (fmt[*i] == 'l' || fmt[*i] == 'h')
	{
		if (fmt[*i] == 'l')
			fl->l = 1;
		else
			fl->h = 1;
		(*i)++;
		found = 1;
	}
	return (found);
}

/**
 * handle_format - handles one % specifier
 * @fmt: format string
 * @i: pointer to position of %
 * @ap: va_list
 * @buf: local buffer
 * @idx: pointer to buffer index
 * Return: number of chars printed, or -1 on error
 */
int handle_format(const char *fmt, int *i, va_list ap,
	char *buf, int *idx)
{
	flags_t fl;
	int (*handler)(va_list, char *, int *, flags_t *);
	int printed = 0;

	(*i)++;
	parse_flags(fmt, i, &fl);
	parse_length(fmt, i, &fl);
	if (fmt[*i] == '\0')
		return (-1);
	handler = get_handler(fmt[*i]);
	if (handler == NULL)
	{
		add_to_buf(buf, idx, '%');
		add_to_buf(buf, idx, fmt[*i]);
		(*i)++;
		return (2);
	}
	printed = handler(ap, buf, idx, &fl);
	(*i)++;
	return (printed);
}
