/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:56 by mjochum           #+#    #+#             */
/*   Updated: 2024/06/18 17:28:29 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	https://docs.oracle.com/cd/E19253-01/817-6223/chp-fmt-1.2/index.html

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>

# define F_ZERO 0x1
# define F_MIN 0x2
# define F_DOT 0x4
# define F_POUND 0x8
# define F_SPACE 0x10
# define F_PLUS 0x20
# define F_FIELDMIN 0x40

typedef struct s_flags {
	char	flagfield;
	char	conversion;
	int		width;
	int		precision;
}				t_flags;

int		ft_printf(const char *str, ...);

//  ft_chars.c
int		ft_isconversion(const char c);
int		ft_isflag(const char c);
int		ft_isdigit(const char c);
int		ft_getflagval(char c);

//  ft_utils.c
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *ptr, int c, size_t n);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		ft_staticputstr(const char *str, int limit);

//  ft_align.c
int		ft_rightalign(t_flags *flags, char spacer);
int		ft_leftalign(t_flags *flags, char spacer);

//  ft_initflags.c
t_flags	ft_initflags(va_list args, const char *str);

//  ft_printX.c
int		ft_printstr(const char *str, t_flags flags);
int		ft_printchar(const char c, t_flags flags);
int		ft_printnum(long long int n, t_flags flags);
int		ft_printunsigned(unsigned int n, t_flags flags);
int		ft_printhex(unsigned long n, t_flags flags);
int		ft_printptr(unsigned long n, t_flags flags);

#endif