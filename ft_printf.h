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

# define    F_ZERO  0x0;
# define    F_MIN   0x2;
# define    F_DOT   0x4;
# define    F_POUND 0x8;
# define    F_SPACE 0x10;
# define    F_PLUS  0x20;

typedef struct  s_flags {
    char        flagField;
    char        conversion;
    size_t      width;
    size_t      precision;
}               t_flags;

int     ft_printf(const char *, ...);

//  ft_chars.c
int     ft_isConversion(const char c);
int     ft_isFlag(const char c);
int     ft_isDigit(const char c);

//  ft_utils.c
void    *ft_calloc(size_t nmemb, int size);
int     ft_atoi(const char *str);

//  ft_initFlags.c
t_flags   ft_initFLag(const char *str);


#endif