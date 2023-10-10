

#include "ft_printf.h"

void    ft_parser_char(va_list arg, int *total)
{
    long long   i;

    i = va_arg(arg, unsigned int);
    ft_putchar_fd(i ,1);
    *total++;
}

void    ft_parser_string(va_list arg, int *total)
{
    char    *str;

    str = va_arg(arg, char *);
    ft_putstr_fd(str, 1);
    if (!str)
        *total = *total + 0;
    else
        *total = *total + ft_strlen(str);
}

void    ft_parser_integer(va_list arg, int *total, char step)
{
    long long   i;

    i = va_arg(arg, unsigned int);
}

void    ft_parser_unsigned_int(va_list arg, int *total, char step)
{
    long long   i;

    i = va_arg(arg, unsigned int);
}

void    ft_parser_hexa(va_list arg, int *total, char step)
{
    long long   i;

    i = va_arg(arg, unsigned int);
}

void    ft_parser_pointer(va_list arg, int *total, char step)
{
    long long   i;

    i = va_arg(arg, unsigned int);
}

void    ft_parser_octal(va_list arg, int *total, char step)
{
    long long   i;

    i = va_arg(arg, unsigned int);
}