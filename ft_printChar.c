#include "ft_printf.h"



int     ft_printStr(const char *str, t_flags flags)
{
    int     strLen;
    int     i;
    int     retVal;

    retVal = 0;
    strLen = ft_strLen(str);
    if (str == NULL)
        strLen = 6;
    else if (strLen > flags.precision)
        strLen = flags.precision;
    i = flags.width - strLen;
    while (!(flags.flagField & F_MIN) && i > 0)
    {
        retVal += write(1, " ", 1);
        i--;
    }
    if (str == NULL)
    {
        if (strLen >= 6)
            retVal += ft_staticPutstr("(null)", strLen);
        else
            retVal += ft_staticPutstr("      ", strLen);
    }
    else
        retVal += ft_staticPutstr(str, strLen);
    while ((flags.flagField & F_MIN) && i > 0)
    {
        retVal += write(1, " ", 1);
        i--;
    }
    return (retVal);
}

int     ft_printChar(const char c, t_flags flags)
{
    char    *buffer;
    int     i;

    i = 0;
    if (flags.width <= 1)
        return (write(1, &c, 1));
    buffer = ft_calloc(flags.width + 1, sizeof(char));
    buffer = ft_memset(buffer, ' ', flags.width);
    if (flags.flagField & F_MIN)
        buffer[0] = c;
    else
        buffer[flags.width - 1] = c;
    i = ft_staticPutstr(buffer, -1);
    free(buffer);
    return (i);
}