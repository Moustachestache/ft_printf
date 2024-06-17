#include "ft_printf.h"

static int  ft_selectConversion(va_list args, const char *str)
{
    t_flags     flags;

    flags = ft_initFlags(args, str);
    if (flags.conversion == 'c')
        return (ft_printChar(va_arg(args, int), flags));
    else if (flags.conversion == 's')
        return (ft_printStr(va_arg(args, char *), flags));
    else if (flags.conversion == 'd' || flags.conversion == 'i')
        return (ft_printNum((long long int)va_arg(args, int), flags));
    else if (flags.conversion == 'u')
        return (ft_printNum((long long int)va_arg(args, unsigned int), flags));
    else if (flags.conversion == 'x' || flags.conversion == 'X')
        return (ft_printHex((unsigned long)va_arg(args, unsigned int), flags));
    else if (flags.conversion == 'p')
        return (ft_printHex(va_arg(args, unsigned long), flags));
    else
        return (0);
}

int     ft_printf(const char *str, ...)
{
    int     i;
    int  len;
	va_list args;

    i = 0;
    len = 0;
	va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1])
        {
            i++;
            if (str[i] == '%')
                len += write(1, "%", 1);
            else
                len += ft_selectConversion(args, &str[i]);
            while (str[i] && !ft_isConversion(str[i]))
                i++;
        }
        else
            len += write(1, &str[i], 1);
        i++;
    }
	va_end(args);
    return (len);
}