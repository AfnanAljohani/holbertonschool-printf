#include "main.h"

/**
 * get_hex_arg - gets unsigned arg for hex based on length
 * @ap: va_list
 * @fl: flags struct
 * Return: unsigned long
 */
static unsigned long get_hex_arg(va_list ap, flags_t *fl)
{
	if (fl->l)
		return (va_arg(ap, unsigned long));
	if (fl->h)
		return ((unsigned short)va_arg(ap, unsigned int));
	return ((unsigned long)va_arg(ap, unsigned int));
}

/**
 * hex_helper - shared helper for hex printing
 * @n: number
 * @upper: 1 for X, 0 for x
 * @buf: buffer
 * @idx: index
 * @fl: flags struct
 * Return: count
 */
static int hex_helper(unsigned long n, int upper, char *buf,
	int *idx, flags_t *fl)
{
	int count = 0, nlen, plen = 0, pad;
	char padc;
	char *prefix = NULL;

	if (fl->hash && n != 0)
		prefix = upper ? "0X" : "0x";
	if (prefix)
		plen = 2;
	nlen = unum_len(n, 16);
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
		count += print_unumber(n, 16, upper, buf, idx);
	if (fl->minus && pad > 0)
		count += pad_output(buf, idx, pad, ' ');
	return (count);
}

/**
 * pr_hex_low - prints unsigned int in lowercase hex
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags struct
 * Return: count
 */
int pr_hex_low(va_list ap, char *buf, int *idx, flags_t *fl)
{
	unsigned long n = get_hex_arg(ap, fl);

	return (hex_helper(n, 0, buf, idx, fl));
}

/**
 * pr_hex_up - prints unsigned int in uppercase hex
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags struct
 * Return: count
 */
int pr_hex_up(va_list ap, char *buf, int *idx, flags_t *fl)
{
	unsigned long n = get_hex_arg(ap, fl);

	return (hex_helper(n, 1, buf, idx, fl));
}

/**
 * pr_pointer - prints a pointer address
 * @ap: va_list
 * @buf: buffer
 * @idx: index
 * @fl: flags struct
 * Return: count
 */
int pr_pointer(va_list ap, char *buf, int *idx, flags_t *fl)
{
	void *p = va_arg(ap, void *);
	int count = 0, nlen, pad;
	char padc;

	if (p == NULL)
		return (add_str(buf, idx, "(nil)"));
	nlen = unum_len((unsigned long)p, 16) + 2;
	pad = fl->width - nlen;
	padc = (fl->zero && !fl->minus) ? '0' : ' ';
	if (!fl->minus && padc == ' ' && pad > 0)
		count += pad_output(buf, idx, pad, ' ');
	add_to_buf(buf, idx, '0');
	add_to_buf(buf, idx, 'x');
	count += 2;
	if (!fl->minus && padc == '0' && pad > 0)
		count += pad_output(buf, idx, pad, '0');
	count += print_unumber((unsigned long)p, 16, 0, buf, idx);
	if (fl->minus && pad > 0)
		count += pad_output(buf, idx, pad, ' ');
	return (count);
}
