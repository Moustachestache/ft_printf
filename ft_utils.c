#include "ft_printf.h"

int	ft_atoi(const char *nptr)
{
	int	r;
	int	s;
	int	i;

	r = 0;
	s = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		r = (r * 10) + (nptr[i] - 48);
		i++;
	}
	return (r * s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*r;
	size_t	i;
	size_t	tmp;

	tmp = nmemb * size;
	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	else if (tmp / size != nmemb)
		return (0);
	r = (char *)malloc(nmemb * size);
	if (!r)
		return (NULL);
	while (i < nmemb * size)
	{
		r[i] = '\0';
		i++;
	}
	return ((void *)r);
}

int  ft_strLen(const char *str)
{
    int i;

    i = 0;
    while (str && str[i])
        i++;
    return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*o;
	size_t	i;

	i = 0;
	o = s;
	while (i < n)
	{
		o[i] = c;
		i++;
	}
	return (s);
}

int    ft_staticPutstr(const char *str, size_t limit)
{
    int i = 0;
    while (str[i] && i < limit)
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}