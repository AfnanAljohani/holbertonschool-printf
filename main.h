#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 1024

/**
 * struct flags - active format flags, width and precision
 * @plus: flag for +
 * @space: flag for space
 * @hash: flag for #
 * @zero: flag for 0 (pad with zeros)
 * @minus: flag for - (left align)
 * @l: length modifier l (long)
 * @h: length modifier h (short)
 * @width: minimum field width
 * @precision: precision (-1 if not set)
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
	int zero;
	int minus;
	int l;
	int h;
	int width;
	int precision;
} flags_t;

/**
 * struct conv - maps specifier to handler
 * @spec: specifier character
 * @f: pointer to handler function
 */
typedef struct conv
{
	char spec;
	int (*f)(va_list, char *, int *, flags_t *);
} conv_t;

int _printf(const char *format, ...);
void flush_buffer(char *buf, int *idx);
void add_to_buf(char *buf, int *idx, char c);
int add_str(char *buf, int *idx, char *s);
int handle_format(const char *fmt, int *i, va_list ap,
	char *buf, int *idx);

int pr_char(va_list ap, char *buf, int *idx, flags_t *fl);
int pr_string(va_list ap, char *buf, int *idx, flags_t *fl);
int pr_percent(va_list ap, char *buf, int *idx, flags_t *fl);
int pr_int(va_list ap, char *buf, int *idx, flags_t *fl);
int pr_binary(va_list ap, char *buf, int *idx, flags_t *fl);

int pr_unsigned(va_list ap, char *buf, int *idx, flags_t *fl);
int pr_octal(va_list ap, char *buf, int *idx, flags_t *fl);
int pr_hex_low(va_list ap, char *buf, int *idx, flags_t *fl);
int pr_hex_up(va_list ap, char *buf, int *idx, flags_t *fl);
int pr_pointer(va_list ap, char *buf, int *idx, flags_t *fl);

int pr_S(va_list ap, char *buf, int *idx, flags_t *fl);
int pr_rev(va_list ap, char *buf, int *idx, flags_t *fl);
int pr_rot13(va_list ap, char *buf, int *idx, flags_t *fl);

int print_number(long n, int base, int upper, char *buf, int *idx);
int print_unumber(unsigned long n, int base, int upper,
	char *buf, int *idx);
int _strlen(char *s);
int parse_flags(const char *fmt, int *i, flags_t *fl);
int parse_length(const char *fmt, int *i, flags_t *fl);
int parse_width(const char *fmt, int *i, va_list ap, flags_t *fl);
int parse_precision(const char *fmt, int *i, va_list ap, flags_t *fl);
int num_len(long n, int base);
int unum_len(unsigned long n, int base);
int pad_output(char *buf, int *idx, int count, char pad);

#endif /* MAIN_H */
