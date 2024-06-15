#include "ft_printf.h"

static int  ft_selectConversion(va_arg arg, char *str)
{
    t_flags     flags;

    flags = ft_initFlags(str);

}

int     ft_printf(const char *str, ...)
{
    int     i;
    size_t  len;
	va_list args;

    i = 0;
    len = 0;
	va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1])
        {
            i++;
            if (str[i] == '%')
                len += write(1, "%", 1);
            else
                len += ft_selectConversion(args, &str[i]);
        }
        else
            len += write(1, &str[i], 1);
        i++;
    }
	va_end(args);
    return (len);
}

int     main(void)
{
        //  test if width = 0
    printf("[%s][%i][%0i]", "hello world", 69, 123456789);
}