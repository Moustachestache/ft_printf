/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printNums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:35:03 by mjochum           #+#    #+#             */
/*   Updated: 2024/06/19 18:40:41 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_itoalen(long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_putnbr(long long int n)
{
	int	retval;

	retval = 0;
	if (n > 9)
		retval += ft_putnbr(n / 10);
	retval += write(1, &"0123456789"[n % 10], 1);
	return (retval);
}

char	ft_setsign(long long int *n, int *retval, int *len, t_flags flags)
{
	(void) retval;
	if (*n < 0)
	{
		len++;
		*n *= -1;
		return ('-');
	}
	else if (*n > 0 && flags.flagfield & F_PLUS)
	{
		len++;
		return ('+');
	}
	else if (*n > 0 && flags.flagfield & F_SPACE)
	{
		len++;
		return (' ');
	}
	return (0);
}

int	ft_printnum(long long int n, t_flags flags)
{
	int		retval;
	int		len;
	char	sign;
	
	retval = 0;
	len = 0;
	sign = ft_setsign(&n, &retval, &len, flags);
	len += ft_itoalen(n);
	flags.width -= len;
	retval += ft_numrightalign(&flags, sign);
	retval += ft_putnbr(n);
	retval += ft_leftalign(&flags, sign);
	return (retval);
}
