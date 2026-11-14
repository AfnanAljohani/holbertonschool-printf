#include <stdio.h>
#include "main.h"
int main(void)
{
	int a, b;

	a = _printf("_printf:   [%s]\n", "Hello, Holberton");
	b = printf("printf:    [%s]\n", "Hello, Holberton");
	fflush(stdout);
	_printf("Char:      [%c]\n", 'A');
	_printf("Integer:   [%d] [%i]\n", -2026, 42);
	_printf("Unsigned:  [%u]\n", 4294967295u);
	_printf("Octal:     [%o]\n", 8);
	_printf("Hex:       [%x] [%X]\n", 255, 255);
	_printf("Binary:    [%b]\n", 10);
	_printf("Percent:   [%%]\n");
	_printf("Length:    _printf=%d  printf=%d\n", a, b);
	return (0);
}
