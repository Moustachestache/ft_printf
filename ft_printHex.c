#include "ft_printf.h"

static int ft_nbrLen(unsigned long int n)
{
    int retVal;

    retVal = 0;
    while (n > 0)
    {
        n /= 16;
        retVal++;
    }
    return (retVal);
}

static  int ft_putHex(unsigned long int n, char x)
{
    int retVal;

    retVal = 0;
    if (n > 16)
        retVal += ft_putHex(n / 16, x);
    if (x == 'X')
        retVal += write(1, &"0123456789ABCDEF"[n % 16], 1);
    else
        retVal += write(1, &"0123456789abcdef"[n % 16], 1);
    return (retVal);
}

int     ft_printHex(unsigned long int n, t_flags flags)
{
    int     retVal;
    int     len;
    char    spacer;

    spacer = ' ';
    len = 0;
    if (flags.flagField & F_ZERO && (flags.flagField & F_DOT) == 0)
        spacer = '0';
    len += ft_nbrLen(n);
    if (flags.conversion == 'p' && n == 0)
        len = 5;
//  pre
    flags.width -= len;
    while ((flags.flagField & F_MIN) == 0 && flags.width > 0)
    {
        retVal += write(1, &spacer, 1);
        flags.width--;
    }
// nbr
    if (flags.conversion == 'p')
    {
        if (n == 0)
            retVal += write(1, "(nil)", 5);
        else
            retVal += write(1, "0x", 2);
    }
    else if ((flags.conversion == 'x' || flags.conversion == 'X'))
    {
        if (flags.flagField & F_POUND)
            retVal += write(1, "0x", 2);
    }
    retVal += ft_putHex(n, flags.conversion);
// post
    while (flags.width > 0)
    {
        retVal += write(1, " ", 1);
        flags.width--;
    }
    return (retVal);
}