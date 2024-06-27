/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:54 by mjochum           #+#    #+#             */
/*   Updated: 2024/06/18 17:11:22 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printpercent(t_flags flags)
{
	return (write(1, "%", 1));
}

static int	ft_selectconversion(va_list args, const char *str)
{
	t_flags	flags;

	flags = ft_initflags(args, str);
	if (flags.conversion == 'c')
		return (ft_printchar(va_arg(args, int), flags));
	else if (flags.conversion == 's')
		return (ft_printstr(va_arg(args, char *), flags));
	else if (flags.conversion == 'd' || flags.conversion == 'i')
		return (ft_printnum((long long int)va_arg(args, int), flags));
	else if (flags.conversion == 'u')
		return (ft_printunum((long long int)va_arg(args, unsigned int), flags));
	else if (flags.conversion == 'x' || flags.conversion == 'X')
		return (ft_printhex((unsigned long)va_arg(args, unsigned int), flags));
	else if (flags.conversion == 'p')
		return (ft_printhex(va_arg(args, unsigned long), flags));
	else if (flags.conversion == '%')
		return (ft_printpercent(flags));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			len += ft_selectconversion(args, &str[i]);
			while (str[i] && !ft_isconversion(str[i]))
				i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
