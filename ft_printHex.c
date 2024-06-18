/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printHex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:35:01 by mjochum           #+#    #+#             */
/*   Updated: 2024/06/18 17:24:58 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(unsigned long int n)
{
	int	retval;

	retval = 0;
	while (n > 0)
	{
		n /= 16;
		retval++;
	}
	return (retval);
}

static int	ft_puthex(unsigned long int n, char x)
{
	int	retval;

	retval = 0;
	if (n > 16)
		retval += ft_puthex(n / 16, x);
	if (x == 'X')
		retval += write(1, &"0123456789ABCDEF"[n % 16], 1);
	else
		retval += write(1, &"0123456789abcdef"[n % 16], 1);
	return (retval);
}

int	ft_printhex(unsigned long int n, t_flags flags)
{
	int		retval;
	int		len;
	char	spacer;

	retval = 0;
	spacer = ' ';
	len = 0;
	if (flags.flagfield & F_ZERO && (flags.flagfield & F_DOT) == 0)
		spacer = '0';
	len += ft_nbrlen(n);
	if (flags.conversion == 'p' && n == 0)
		len = 5;
	if (flags.flagfield & F_POUND || flags.conversion == 'p')
		len += 2;
	flags.width -= len;
	retval += ft_rightalign(&flags, spacer);
	if (flags.conversion == 'p' && n == 0)
		retval += write(1, "(nil)", 5);
	else if (flags.flagfield & F_POUND || flags.conversion == 'p')
		retval += write(1, "0x", 2);
	retval += ft_puthex(n, flags.conversion);
	retval += ft_leftalign(&flags, spacer);
	return (retval);
}
