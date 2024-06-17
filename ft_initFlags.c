#include "ft_printf.h"

static int  ft_initFlagWidth(va_list args, const char *str, char _flagField)
{
    int  retVal;
    int i;

    i = 0;
    retVal = 0;
    while (str[i] && ft_isFlag(str[i]) == 1)
        i++;
    if (_flagField & F_FIELDMIN)
        retVal = va_arg(args, int);
    else if (str[i])
        retVal = ft_atoi(str + i);
    return (retVal);
}

static char    ft_initFlagField(const char *str)
{
    int i;
    char    retVal;

    retVal = 0;
    i = 0;
    while (str[i] && (!ft_isDigit(str[i]) || str[i] == '0') && !ft_isConversion(str[i]))
    {
        if (str[i] == '-')
            retVal |= F_MIN;
        else if (str[i] == '0')
           retVal |= F_ZERO;
        else if (str[i] == '#')
            retVal |= F_POUND;
        else if (str[i] == ' ')
            retVal |= F_SPACE;
        else if (str[i] == '+')
            retVal |= F_PLUS;
        else if (str[i] == '*')
            retVal |= F_FIELDMIN;
        i++;
    }
    while (str[i] && !ft_isConversion(str[i]))
    {
        if (str[i] == '.')
            retVal |= F_DOT;
        i++;
    }
    return (retVal);
}

static int  ft_initFlagPrec(va_list args, const char *str)
{
    int i;
    int retVal;

    i = 0;
    retVal = 0;
    while (str[i] && str[i] != '.')
        i++;
    if (str[i] && str[i] == '.' && str[i] + 1)
    {
        if (str[i + 2] && str[i + 2] == '*')
            retVal = va_arg(args, int);
        else
            retVal = ft_atoi(str + i + 1);
    }
    return (retVal);
}

static char ft_initConversion(const char *str)
{
    int i;

    i = 0;
    while(str[i] && !ft_isConversion(str[i]))
        i++;
    if (str[i])
        return (str[i]);
    return (0);
}

t_flags   ft_initFlags(va_list args, const char *str)
{
    t_flags returnFlags;
    int i;

    i = 0;
    returnFlags = (t_flags){0, 0, 0, 0};
    returnFlags.flagField = ft_initFlagField(str);
    returnFlags.width = ft_initFlagWidth(args, str, returnFlags.flagField);
    returnFlags.conversion = ft_initConversion(str);
    returnFlags.precision = ft_initFlagPrec(args, str);
//    printf("flag debug: [flag field: %i] [width: %i] [conv: %i] [prec: %i]\n", returnFlags.flagField, returnFlags.width, returnFlags.conversion, returnFlags.precision);
    return (returnFlags);
}