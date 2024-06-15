#include "ft_printf.h"

static size_t  ft_initFlagWidth(const char *str)
{
    size_t  retVal;
    int i;

    i = 0;
    retVal = 0;
    while (str[i] && ft_isConversion(str[i]))
        i++;
    retVal = ft_atoi(str + i);
    return (retVal);
}

static char    ft_initFlagField(const char *str)
{
    int i;
    char    retVal;

    retVal = 0;
    i = 0;
    while (str[i] && !ft_isConversion(str[i]))
    {
        if (str[i] == '-')
            retval |= F_MIN;
        else if (str[i] == '0')
           retval |= F_ZERO;
        else if (str[i] == '.')
            retval |= F_DOT;
        else if (str[i] == '#')
            retval |= F_POUND;
        else if (str[i] == ' ')
            retval |= F_SPACE;
        else if (str[i] == '+')
            retval |= F_PLUS;
        i++;
    }
    return (retVal);
}

static size_t  ft_initFlagPrec(const char *str)
{
    int i;
    size_t retVal;

    i = 0;
    retVal = 0;
    while (str[i] && str[i] != '.')
        i++;
    if (str[i] && str[i] == '.' && str[i] + 1)
        retval = ft_atoi(str + i + 1);
    return (retVal);
}

t_flags   ft_initFLag(const char *str)
{
    t_flags returnFlags;
    int i;

    i = 0;
    returnFlags = {0, 0, 0, 0, 0};
    returnFlags.flagField = ft_initFlagField(str);
    returnFlags.width = ft_initFlagWidth(str);
    returnFlags.precision = ft_initFlagPrec(str);
    return (returnFlags)
}