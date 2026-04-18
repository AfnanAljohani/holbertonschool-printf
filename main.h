#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

#define BUFFER_SIZE 1024

/**
 * struct buffer_s - Local output buffer to minimize write() calls
 * @buf: The character buffer
 * @len: Current number of characters stored in @buf
 */
typedef struct buffer_s
{
	char buf[BUFFER_SIZE];
	int len;
} buffer_t;

/**
 * struct spec_s - Maps a format specifier to its handler function
 * @specifier: The format specifier character
 * @func: The function that handles the specifier
 */
typedef struct spec_s
{
	char specifier;
	int (*func)(va_list, buffer_t *);
} spec_t;

int _printf(const char *format, ...);

int print_char(va_list args, buffer_t *b);
int print_string(va_list args, buffer_t *b);
int print_percent(va_list args, buffer_t *b);

int buffer_add_char(buffer_t *b, char c);
int buffer_flush(buffer_t *b);

int (*get_func(char s))(va_list, buffer_t *);

#endif /* MAIN_H */
