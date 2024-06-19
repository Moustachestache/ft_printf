
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include "ft_printf.h"

#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define WHT "\033[0;37m"

int	main(int ac, char **av)
{
time_t	vartime = time(&vartime);
unsigned int timeint = (unsigned int)vartime;
int	rand = rand_r(&timeint);

int	min = INT_MIN;
int	max = INT_MAX;
int	zero = 0;

void *vptr = NULL;
void *vptr2 = malloc(69);

unsigned int umax = UINT_MAX;

long int	lint = LONG_MAX;
long int	mint = LONG_MIN;

char	*str1 = "hello world str1";
char	*str2 = "un deux trois";
char	*str3 = "";
char	*str4 = NULL;

printf("test1 : str\n");
int		pstr = ft_printf("[%s][%s][%s][%s]\n", str1, str2, str3, str4);
int		pstr_bis = printf("[%10.5s][%.5s][%5.5s][%50.2s]\n", str1, str2, str3, str4);
int		rpstr = ft_printf("[%s][%s][%s][%s]\n", str1, str2, str3, str4);
int		rpstr_bis = printf("[%10.5s][%.5s][%5.5s][%50.2s]\n", str1, str2, str3, str4);
printf("result:[%i:%i][%i:%i]\n", pstr, pstr_bis, rpstr, rpstr_bis);

printf("test 2: %%i and %%d\n");
int		pid = ft_printf("[%i][%i][%i] [%d][%d][%d]\n", rand, min, max, rand, min, max);
int		pid_bis = printf("[%i][%i][%i] [%d][%d][%d]\n", rand, min, max, rand, min, max);
int		rpid = ft_printf("[%5.2i][%020i][%+12i] [%5.2d][% 0d][% 0d]\n", rand, min, max, rand, min, max);
int		rpid_bis = printf("[%5.2i][%020i][%+12i] [%5.2d][% 0d][% 0d]\n", rand, min, max, rand, min, max);

printf("result:[%i:%i][%i:%i]\n", pid, pid_bis, rpid, rpid_bis);
}