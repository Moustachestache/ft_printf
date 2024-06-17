#include "ft_printf.h"

int ft_isDigit(const char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int ft_isFlag(const char c)
{
    if (c == '-' || c == '0' || c == '*' ||\
        c == '#' || c == ' ' || c == '+' ||\
        c == '%')
        return (1);
    if (c == '.')
        return (2);
    return (0);
}

int ft_isConversion(const char c)
{
    if (c == 'c' || c == 's' || c == 'p' || c == 'd' ||\
        c == 'i' || c == 'u' || c == 'x' || c == 'X')
        return (1);
    return (0);
}