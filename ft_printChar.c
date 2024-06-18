/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printChar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:51 by mjochum           #+#    #+#             */
/*   Updated: 2024/06/18 17:23:53 by mjochum          ###   ########.fr       */
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
	else if (strlen > flags.precision)
		strlen = flags.precision;
	flags.width -= strlen;
	retval += ft_rightalign(&flags, ' ');
	if (str == NULL)
	{
		if (strlen >= 6)
			retval += ft_staticputstr("(null)", strlen);
		else
			retval += ft_staticputstr("	  ", strlen);
	}
	else
		retval += ft_staticputstr(str, strlen);
	retval += ft_leftalign(&flags, ' ');
	return (retval);
}

int	ft_printchar(const char c, t_flags flags)
{
	char	*buffer;
	int		i;

	i = 0;
	if (flags.width <= 1)
		return (write(1, &c, 1));
	buffer = ft_calloc(flags.width + 1, sizeof(char));
	buffer = ft_memset(buffer, ' ', flags.width);
	if (flags.flagfield & F_MIN)
		buffer[0] = c;
	else
		buffer[flags.width - 1] = c;
	i = ft_staticputstr(buffer, -1);
	free(buffer);
	return (i);
}
