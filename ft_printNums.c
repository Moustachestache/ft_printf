#include "ft_printf.h"

static int  ft_itoaLen(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char *ft_itoa(long int n)
{
	int				i;
	long int		j;
	char			*itoa;

	j = n;
	i = ft_itoaLen(j);
	itoa = ft_calloc(i-- + 1, sizeof(char));
	if (j < 0)
	{
		j *= -1;
		itoa[0] = '-';
	}
	while (j > 9)
	{
		itoa[i] = (j % 10) + '0';
		j /= 10;
		i--;
	}
	itoa[i] = j + '0';
	return (itoa);
}

int     ft_printNum(long int n, t_flags flags)
{
    int     returnValue;
    char    *itoa;
    int     len;
    char    spacer;

    returnValue = 0;
    spacer = ' ';
    len = 0;
    if (flags.flagField & F_ZERO && (flags.flagField & F_DOT) == 0)
        spacer = '0';
    if (n < 0)
    {
        n = n / -(write(1, "-", 1));
        len += 1;
        returnValue++;
    }
    itoa = ft_itoa(n);
    len += ft_strLen(itoa);
    if (flags.flagField & F_DOT)
        len = flags.precision;
    flags.width -= len;
    while ((flags.flagField & F_MIN) == 0 && flags.width > 0)
    {
        returnValue += write(1, &spacer, 1);
        flags.width--;
    }
    if (flags.flagField & F_SPACE && n > 0)
        returnValue += write(1, " ", 1);
    returnValue += ft_staticPutstr(itoa, len);
    while (flags.width > 0)
    {
        returnValue += write(1, " ", 1);
        flags.width--;
    }
    return (returnValue);
}

/* int     ft_printUnsigned(unsigned int n, t_flags flags)
{
    return 0;
} */