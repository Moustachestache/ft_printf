/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:35:44 by mjochum           #+#    #+#             */
/*   Updated: 2024/06/19 17:27:29 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_rightalign(t_flags *flags, char spacer)
{
	int		retval;

	retval = 0;
	while ((flags->flagfield & F_MIN) == 0 && flags->width > 0)
	{
		retval += write(1, &spacer, 1);
		flags->width--;
	}
	return (retval);
}

int	ft_leftalign(t_flags *flags, char spacer)
{
	int		retval;

	(void) spacer;
	retval = 0;
	while (flags->width > 0)
	{
		retval += write(1, " ", 1);
		flags->width--;
	}
	return (retval);
}

int	ft_numrightalign(t_flags *flags, char sign)
{
	int		retval;

	retval = 0;
	if (flags->flagfield & F_ZERO)
	{
		retval += write(1, &sign, 1);
		while (flags->width > 0)
		{
			retval += write(1, "0", 1);
			flags->width--;
		}
		return (retval);
	}
	while (flags->width > 0)
	{
		retval += write(1, " ", 1);
		flags->width--;
	}
	retval += write(1, &sign, 1);
	return (retval);
}
