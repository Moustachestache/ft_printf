/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initFlags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:48 by mjochum           #+#    #+#             */
/*   Updated: 2024/06/23 17:33:45 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_initflagwidth(va_list args, const char *str, char _flagfield)
{
	int	retval;
	int	i;

	i = 0;
	retval = 0;
	while (str[i] && ft_isflag(str[i]) == 1)
		i++;
	if (_flagfield & F_FIELDMIN)
		retval = va_arg(args, int);
	else if (str[i])
		retval = ft_atoi(str + i);
	return (retval);
}

static char	ft_initflagfield(const char *str)
{
	int		i;
	char	retval;

	retval = 0;
	i = 0;
	while (str[i] && (!ft_isdigit(str[i]) || str[i] == '0') && \
		!ft_isconversion(str[i]))
	{
		retval |= ft_getflagval(str[i]);
		i++;
	}
	while (str[i] && !ft_isconversion(str[i]))
	{
		if (str[i] == '.')
			retval |= F_DOT;
		i++;
	}
	return (retval);
}

static int	ft_initflagprec(va_list args, const char *str)
{
	int	i;
	int	retval;

	i = 0;
	retval = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] && str[i] == '.' && str[i + 1])
	{
		if (str[i + 2] && str[i + 2] == '*')
			retval = va_arg(args, int);
		else
			retval = ft_atoi(str + i + 1);
	}
	return (retval);
}

static char	ft_initconversion(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && !ft_isconversion(str[i]))
		i++;
	if (str[i])
		return (str[i]);
	return (0);
}

t_flags	ft_initflags(va_list args, const char *str)
{
	t_flags	returnflags;

	returnflags = (t_flags){0, 0, 0, 0};
	returnflags.flagfield = ft_initflagfield(str);
	returnflags.width = ft_initflagwidth(args, str, returnflags.flagfield);
	returnflags.conversion = ft_initconversion(str);
	returnflags.precision = ft_initflagprec(args, str);
	return (returnflags);
}
