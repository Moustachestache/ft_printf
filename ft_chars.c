/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:09 by mjochum           #+#    #+#             */
/*   Updated: 2024/06/23 17:37:18 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isflag(const char c)
{
	if (c == '-' || c == '0' || c == '*' || \
		c == '#' || c == ' ' || c == '+' || \
		c == '%')
		return (1);
	if (c == '.')
		return (2);
	return (0);
}

int	ft_isconversion(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || \
		c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	ft_getflagval(char c)
{
	if (c == '-')
		return (F_MIN);
	else if (c == '0')
		return (F_ZERO);
	else if (c == '#')
		return (F_POUND);
	else if (c == ' ')
		return (F_SPACE);
	else if (c == '+')
		return (F_PLUS);
	else if (c == '*')
		return (F_FIELDMIN);
	else if (c == '.')
		return (F_DOT);
	else
		return (0);
}
