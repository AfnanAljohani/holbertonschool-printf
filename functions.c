#include "main.h"

int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (write(1, &c, 1));
}

int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int i;

    if (str == NULL)
        str = "(null)";
    for (i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
    return (i);
}

int print_percent(va_list args)
{
    (void)args;
    return (write(1, "%", 1));
}

int (*get_func(char s))(va_list)
{
    spec_t specs[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {0, NULL}
    };
    int i;

    for (i = 0; specs[i].func != NULL; i++)
    {
        if (specs[i].specifier == s)
            return (specs[i].func);
    }
    return (NULL);
}
