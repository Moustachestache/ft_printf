/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printChar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:51 by mjochum           #+#    #+#             */
/*   Updated: 2024/06/23 17:24:26 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(const char *str, t_flags flags)
{
	int	strlen;
	int	retval;

	retval = 0;
	strlen = ft_strlen(str);
	if (str == NULL)
		strlen = 6;
	else if (strlen && flags.flagfield & F_DOT)
		strlen = flags.precision;
	flags.width -= strlen;
	retval += ft_rightalign(&flags, ' ');
	if (str == NULL)
	{
		if (strlen >= 6 && (flags.precision >= 6 || flags.precision == 0))
			retval += ft_staticputstr("(null)", strlen);
		else
			retval += ft_staticputstr("      ", strlen);
	}
	else
		retval += ft_staticputstr(str, strlen);
	retval += ft_leftalign(&flags, ' ');
	return (retval);
}

int	ft_printchar(const char c, t_flags flags)
{
	static char	buffer[2] = {0, 0};
	int		i;

	i = 0;
	if (c == 0)
	{
		flags.width--;
		i++;
	}
	buffer[0] = c;
	i += ft_printstr(buffer, flags);
	return (i);
}
