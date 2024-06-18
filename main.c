#include "ft_printf.h"
int main(void)
{
	int a = F_ZERO;
	int b = F_MIN;
	int c = a | b;
	int d = a & b;
	int e = F_FIELDMIN;

	int normval;
	int myval;

	char *str = ft_calloc(4,4);
	printf("flag values: \nF_ZERO[%i] F_MIN[%i] F_DOT[%i] \nF_POUND[%i] F_SPACE[%i] F_PLUS[%i] F_FIELDMIN[%i]\n\n", F_ZERO, F_MIN, F_DOT, F_POUND, F_SPACE, F_PLUS, F_FIELDMIN);

/*	 normval =	  printf("[%030x][%-30x][%-30p][%u]\n", -123456789, -123456789, &str, str);
	myval =	 ft_printf("[%030x][%-30x][%-30p][%u]\n", -123456789, -123456789, &str, str); */

	normval =	  printf("[%#-30.3x][%#030.3x][%-30p][%30p]\n", -123456789, 123456789, &str, str);
	myval =	 ft_printf("[%#-30.3x][%#030.3x][%-30p][%30p]\n", -123456789, 123456789, &str, str);

	printf("printf n: %i myval: %i\n", normval, myval);
}