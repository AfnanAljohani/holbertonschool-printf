#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * struct spec - Struct for specifiers
 * @specifier: The character
 * @func: The function associated
 */
typedef struct spec
{
	char specifier;
	int (*func)(va_list);
} spec_t;

int _printf(const char *format, ...);
int _putchar(char c);
void flush_buffer(char *buf, int *idx);
void buffer_add(char *buf, int *idx, char c);
int handle_specifier(char c, va_list args, char *buf, int *idx);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_int_helper(unsigned int n);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);
int print_S(va_list args);
int print_pointer(va_list args);
int (*get_func(char s))(va_list);

#endif /* MAIN_H */
