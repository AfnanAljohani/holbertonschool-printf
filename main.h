#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

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
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int print_int_helper(unsigned int n);
int (*get_func(char s))(va_list);

#endif /* MAIN_H */
