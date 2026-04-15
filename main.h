#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct specifier
{
    char specifier;
    int (*func)(va_list);
} spec_t;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int (*get_func(char s))(va_list);

#endif
