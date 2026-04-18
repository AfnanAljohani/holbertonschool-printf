#include "main.h"

/**
 * pr_S - prints string with non-printables as \\x hex
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags (unused)
 * Return: count
 */
int pr_S(va_list ap, char *buf, int *idx, flags_t *fl)
{
	char *s = va_arg(ap, char *);
	int i = 0, c = 0;
	unsigned char ch;

	(void)fl;
	if (s == NULL)
		return (add_str(buf, idx, "(null)"));
	while (s[i])
	{
		ch = (unsigned char)s[i];
		if (ch != 0 && (ch < 32 || ch >= 127))
		{
			add_to_buf(buf, idx, '\\');
			add_to_buf(buf, idx, 'x');
			c += 2;
			if (ch < 16)
			{
				add_to_buf(buf, idx, '0');
				c++;
			}
			c += print_unumber((unsigned long)ch, 16, 1, buf, idx);
		}
		else
		{
			add_to_buf(buf, idx, s[i]);
			c++;
		}
		i++;
	}
	return (c);
}

/**
 * pr_rev - prints string reversed
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags (unused)
 * Return: count
 */
int pr_rev(va_list ap, char *buf, int *idx, flags_t *fl)
{
	char *s = va_arg(ap, char *);
	int len, c = 0;

	(void)fl;
	if (s == NULL)
		s = "(null)";
	len = _strlen(s);
	while (len-- > 0)
	{
		add_to_buf(buf, idx, s[len]);
		c++;
	}
	return (c);
}

/**
 * pr_rot13 - prints string in rot13
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags (unused)
 * Return: count
 */
int pr_rot13(va_list ap, char *buf, int *idx, flags_t *fl)
{
	char *s = va_arg(ap, char *);
	int i = 0, c = 0;
	char ch;

	(void)fl;
	if (s == NULL)
		s = "(null)";
	while (s[i])
	{
		ch = s[i];
		if ((ch >= 'a' && ch <= 'z'))
			ch = (ch - 'a' + 13) % 26 + 'a';
		else if ((ch >= 'A' && ch <= 'Z'))
			ch = (ch - 'A' + 13) % 26 + 'A';
		add_to_buf(buf, idx, ch);
		c++;
		i++;
	}
	return (c);
}
