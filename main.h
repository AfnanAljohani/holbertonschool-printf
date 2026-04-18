#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 1024

/**
 * struct flags - active format flags
 * @plus: flag for +
 * @space: flag for space
 * @hash: flag for #
 * @l: length modifier l (long)
 * @h: length modifier h (short)
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
	int l;
	int h;
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

#endif /* MAIN_H */
