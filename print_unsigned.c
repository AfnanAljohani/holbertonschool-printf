#include "main.h"

/**
 * get_uarg - gets unsigned arg based on length modifier
 * @ap: va_list
 * @fl: flags struct
 * Return: unsigned long value
 */
static unsigned long get_uarg(va_list ap, flags_t *fl)
{
	if (fl->l)
		return (va_arg(ap, unsigned long));
	if (fl->h)
		return ((unsigned short)va_arg(ap, unsigned int));
	return ((unsigned long)va_arg(ap, unsigned int));
}

/**
 * print_u_base - prints unsigned with width/precision/flags
 * @n: number
 * @base: base
 * @upper: uppercase flag
 * @buf: buffer
 * @idx: index
 * @fl: flags struct
 * @prefix: string prefix (0x, 0X, 0) or NULL
 * Return: count
 */
static int print_u_base(unsigned long n, int base, int upper,
	char *buf, int *idx, flags_t *fl, char *prefix)
{
	int count = 0, nlen, plen = 0, pad;
	char padc;

	if (prefix)
		while (prefix[plen])
			plen++;
	nlen = unum_len(n, base);
	if (fl->precision >= 0 && n == 0 && fl->precision == 0)
		nlen = 0;
	if (fl->precision > nlen)
		pad = fl->width - plen - fl->precision;
	else
		pad = fl->width - plen - nlen;
	padc = (fl->zero && !fl->minus && fl->precision < 0) ? '0' : ' ';
	if (!fl->minus && padc == ' ' && pad > 0)
		count += pad_output(buf, idx, pad, ' ');
	if (prefix)
		count += add_str(buf, idx, prefix);
	if (!fl->minus && padc == '0' && pad > 0)
		count += pad_output(buf, idx, pad, '0');
	if (fl->precision > nlen)
		count += pad_output(buf, idx, fl->precision - nlen, '0');
	if (nlen > 0)
		count += print_unumber(n, base, upper, buf, idx);
	if (fl->minus && pad > 0)
		count += pad_output(buf, idx, pad, ' ');
	return (count);
}

/**
 * pr_unsigned - prints unsigned int
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags struct
 * Return: count
 */
int pr_unsigned(va_list ap, char *buf, int *idx, flags_t *fl)
{
	unsigned long n = get_uarg(ap, fl);

	return (print_u_base(n, 10, 0, buf, idx, fl, NULL));
}

/**
 * pr_octal - prints unsigned int in octal
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags struct
 * Return: count
 */
int pr_octal(va_list ap, char *buf, int *idx, flags_t *fl)
{
	unsigned long n = get_uarg(ap, fl);
	char *pref = (fl->hash && n != 0) ? "0" : NULL;

	return (print_u_base(n, 8, 0, buf, idx, fl, pref));
}
