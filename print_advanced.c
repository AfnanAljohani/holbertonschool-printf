#include "main.h"

/**
 * print_S - prints string, non-printable chars as \x followed by ASCII in hex
 * @args: va_list containing the string
 * Return: number of characters printed
 */
int print_S(va_list args)
{
	char *str;
	int i;
	int count;
	char *hex = "0123456789ABCDEF";

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if ((unsigned char)str[i] < 16)
				_putchar('0');
			_putchar(hex[(unsigned char)str[i] / 16]);
			_putchar(hex[(unsigned char)str[i] % 16]);
			count += 4;
		}
		else
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}
