//  malloc, free, write,
//  va_start, va_arg, va_copy, va_end

/*You have to implement the following conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.*/

/*• Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions.
also * (field minimum width)
• Manage all the following flags: ’# +’ (Yes, one of them is a space)*/

//  %[flags][width][.precision][size]type

//  https://learn.microsoft.com/fr-fr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170#size
//	https://docs.oracle.com/cd/E19253-01/817-6223/chp-fmt-1.2/index.html
/*




*/

/*
workflow
- add calloc
- create basic dispatcher into functions
- add backtracking to fill flags
- one function par conversion. conversion handles flags where needs be

bear in mind to keep numbers of chars printed to output;
*/
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>

# define    F_ZERO      0x1
# define    F_MIN       0x2
# define    F_DOT       0x4
# define    F_POUND     0x8
# define    F_SPACE     0x10
# define    F_PLUS      0x20
# define    F_FIELDMIN  0x40

typedef struct  s_flags {
    char        flagField;
    char        conversion;
    int      width;
    int      precision;
}               t_flags;

int     ft_printf(const char *, ...);

//  ft_chars.c
int     ft_isConversion(const char c);
int     ft_isFlag(const char c);
int     ft_isDigit(const char c);

//  ft_utils.c
void    *ft_calloc(size_t nmemb, size_t size);
void    *ft_memset(void *ptr, int c, size_t n);
int     ft_atoi(const char *str);
int     ft_strLen(const char *str);
int     ft_staticPutstr(const char *str, size_t limit);

//  ft_initFlags.c
t_flags   ft_initFlags(va_list args, const char *str);

//  ft_printX.c
int     ft_printStr(const char *str, t_flags flags);
int     ft_printChar(const char c, t_flags flags);
int     ft_printNum(long long int n, t_flags flags);
int     ft_printUnsigned(unsigned int n, t_flags flags);
int     ft_printHex(unsigned long n, t_flags flags);
int     ft_printPtr(unsigned long n, t_flags flags);

#endif