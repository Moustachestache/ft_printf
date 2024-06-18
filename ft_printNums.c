/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printNums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:35:03 by mjochum           #+#    #+#             */
/*   Updated: 2024/06/18 17:12:24 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_itoalen(long long int n)
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

static char	*ft_itoa(long long int n)
{
	int				i;
	long int		j;
	char			*itoa;

	j = n;
	i = ft_itoalen(j);
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

int	ft_nummin(long long int *n, int *len)
{
	int	retval;

	retval = 0;
	if (*n < 0)
	{
		*n /= -(write(1, "-", 1));
		len += 1;
		retval++;
	}
	return (retval);
}

int	ft_printnum(long long int n, t_flags flags)
{
	int		retval;
	char	*itoa;
	int		len;
	char	spacer;

	retval = 0;
	spacer = ' ';
	len = 0;
	if (flags.flagfield & F_ZERO && (flags.flagfield & F_DOT) == 0)
		spacer = '0';
	retval += ft_nummin(&n, &len);
	itoa = ft_itoa(n);
	len += ft_strlen(itoa);
	if (flags.flagfield & F_DOT)
		len = flags.precision;
	flags.width -= len;
	retval += ft_rightalign(&flags, spacer);
	if (flags.flagfield & F_SPACE && n > 0)
		retval += write(1, " ", 1);
	retval += ft_staticputstr(itoa, len);
	retval += ft_leftalign(&flags, spacer);
	return (retval);
}
