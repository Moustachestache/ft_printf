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

# define    F_ZERO =    0x0;
# define    F_MIN =     0x2;
# define    F_DOT =     0x4;
# define    F_POUND =   0x8;
# define    F_SPACE =   0x10;
# define    F_PLUS =    0x20;

# define    C_CHAR =    0x0;
# define    C_STR =     0x2;
# define    C_PTR =     0x4;
# define    C_DEC =     0x8;
# define    C_UDEC =    0x10;
# define    C_UNS =     0x20;
# define    C_HEX =     0x40;
# define    C_UHEX =    0x80;

typedef struct  s_flags {
    char        flagField;
    char        convField;
    size_t      width;
    size_t      precision;
    size_t      size;       // not needed? // probably no, no
}               t_flags;

int     ft_printf(const char *, ...);