#include "main.h"

/**
 * pr_char - prints a char with width
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags struct
 * Return: count
 */
int pr_char(va_list ap, char *buf, int *idx, flags_t *fl)
{
	char c = (char)va_arg(ap, int);
	int count = 0, pad = fl->width - 1;

	if (!fl->minus && pad > 0)
		count += pad_output(buf, idx, pad, ' ');
	add_to_buf(buf, idx, c);
	count++;
	if (fl->minus && pad > 0)
		count += pad_output(buf, idx, pad, ' ');
	return (count);
}

/**
 * pr_string - prints a string with width and precision
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags struct
 * Return: count
 */
int pr_string(va_list ap, char *buf, int *idx, flags_t *fl)
{
	char *s = va_arg(ap, char *);
	int len, i = 0, count = 0, pad;

	if (s == NULL)
		s = "(null)";
	len = _strlen(s);
	if (fl->precision >= 0 && fl->precision < len)
		len = fl->precision;
	pad = fl->width - len;
	if (!fl->minus && pad > 0)
		count += pad_output(buf, idx, pad, ' ');
	while (i < len)
	{
		add_to_buf(buf, idx, s[i]);
		i++;
		count++;
	}
	if (fl->minus && pad > 0)
		count += pad_output(buf, idx, pad, ' ');
	return (count);
}

/**
 * pr_percent - prints a literal %
 * @ap: va_list (unused)
 * @buf: buffer
 * @idx: index
 * @fl: flags (unused)
 * Return: 1
 */
int pr_percent(va_list ap, char *buf, int *idx, flags_t *fl)
{
	(void)ap;
	(void)fl;
	add_to_buf(buf, idx, '%');
	return (1);
}

/**
 * pr_int - prints integer with width, precision, flags
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags struct
 * Return: count
 */
int pr_int(va_list ap, char *buf, int *idx, flags_t *fl)
{
	long n;
	unsigned long un;
	char signc = 0, padc = ' ';
	int nlen, total, pad, count = 0, prec = fl->precision;

	if (fl->l)
		n = va_arg(ap, long);
	else if (fl->h)
		n = (short)va_arg(ap, int);
	else
		n = va_arg(ap, int);
	if (n < 0)
	{
		signc = '-';
		un = (unsigned long)(-n);
	}
	else
	{
		un = (unsigned long)n;
		if (fl->plus)
			signc = '+';
		else if (fl->space)
			signc = ' ';
	}
	nlen = unum_len(un, 10);
	if (prec == 0 && un == 0)
		nlen = 0;
	if (prec > nlen)
		total = (signc ? 1 : 0) + prec;
	else
		total = (signc ? 1 : 0) + nlen;
	pad = fl->width - total;
	if (fl->zero && !fl->minus && prec < 0)
		padc = '0';
	if (!fl->minus && padc == ' ' && pad > 0)
		count += pad_output(buf, idx, pad, ' ');
	if (signc)
	{
		add_to_buf(buf, idx, signc);
		count++;
	}
	if (!fl->minus && padc == '0' && pad > 0)
		count += pad_output(buf, idx, pad, '0');
	if (prec > nlen)
		count += pad_output(buf, idx, prec - nlen, '0');
	if (nlen > 0)
		count += print_unumber(un, 10, 0, buf, idx);
	if (fl->minus && pad > 0)
		count += pad_output(buf, idx, pad, ' ');
	return (count);
}

/**
 * pr_binary - prints integer in binary
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags (unused)
 * Return: count
 */
int pr_binary(va_list ap, char *buf, int *idx, flags_t *fl)
{
	unsigned int n = va_arg(ap, unsigned int);

	(void)fl;
	return (print_unumber((unsigned long)n, 2, 0, buf, idx));
}
