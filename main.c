
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

/* printf("test1 : str\n");
printf("%s", "ft_printf\n");
int		pstr = ft_printf("[%s][%s][%s][%s]\n", str1, str2, str3, str4);
printf("%s", "printf\n");
int		rpstr = printf("[%s][%s][%s][%s]\n", str1, str2, str3, str4);
printf("%s", "ft_printf\n");
int		pstr_bis = ft_printf("[%10.s][%.5s][%5.5s][%50.2s]\n", str1, str2, str3, str4);
printf("%s", "printf\n");
int		rpstr_bis = printf("[%10.s][%.5s][%5.5s][%50.2s]\n", str1, str2, str3, str4);

printf("result:[%i:%i][%i:%i]\n", pstr, rpstr, pstr_bis, rpstr_bis); */

/* printf("test 2: %%i and %%d\n");
printf("%s", "ft_printf\n");
int		pid = ft_printf("[%-15i][%i][%i] [%d][%d][%d]\n", rand, min, max, rand, min, max);
printf("%s", "printf\n");
int		rpid =   printf("[%-15i][%i][%i] [%d][%d][%d]\n", rand, min, max, rand, min, max);

printf("%s", "ft_printf\n");
int		pid_bis = ft_printf("[%5.2i][%020i][%+12i] [%5.2d][% 0d][% -30d]\n", rand, min, max, rand, min, max);
printf("%s", "printf\n");
int		rpid_bis =   printf("[%5.2i][%020i][%+12i] [%5.2d][% 0d][% -30d]\n", rand, min, max, rand, min, max);

printf("result:[ft_printf:%i::printf:%i][ft_printf:%i::printf:%i]\n", pid, rpid, pid_bis, rpid_bis); */


/* printf("test 3: %%x and %%X\n");
printf("%s", "ft_printf\n");
int		pid = ft_printf("[%-15x][%-20x][%010x] [%.4X][%#10X][%#X]\n", rand, min, max, rand, min, max);
printf("%s", "printf\n");
int		rpid =   printf("[%-15x][%-20x][%010x] [%.4X][%#10X][%#X]\n", rand, min, max, rand, min, max);

printf("%s", "ft_printf\n");
int		pid_bis = ft_printf("[%5.2x][%020x][%12x] [%5.2x][%0x][%30x]\n", rand, min, max, rand, min, max);
printf("%s", "printf\n");
int		rpid_bis =   printf("[%5.2x][%020x][%12x] [%5.2x][%0x][%30x]\n", rand, min, max, rand, min, max);

printf("result:[ft_printf:%i::printf:%i][ft_printf:%i::printf:%i]\n", pid, rpid, pid_bis, rpid_bis);
 */

/* printf("test 4: %%u");
printf("%s", "ft_printf\n");
int		pid = ft_printf("[%-15u][%-20u][%010u] [%.4u][%10u][%u]\n", rand, min, max, rand, min, max);
printf("%s", "printf\n");
int		rpid =   printf("[%-15u][%-20u][%010u] [%.4u][%10u][%u]\n", rand, min, max, rand, min, max);
printf("%s", "ft_printf\n");
int		pid_bis = ft_printf("[%5.2u][%020u][%12u] [%5.2u][%0u][%30u]\n", rand, min, max, rand, min, max);
printf("%s", "printf\n");
int		rpid_bis =   printf("[%5.2u][%020u][%12u] [%5.2u][%0u][%30u]\n", rand, min, max, rand, min, max);
printf("result:[ft_printf:%i::printf:%i][ft_printf:%i::printf:%i]\n", pid, rpid, pid_bis, rpid_bis); */

/* printf("text 5: %%p");
printf("%s", "ft_printf\n");
int		pid = ft_printf("[%-15p][%-20p][%10p] [%4p][%10p][%p]\n", (void *)rand, (void*)min, (void*)max, (void*)rand, (void*)min, (void*)max);
printf("%s", "printf\n");
int		rpid =   printf("[%-15p][%-20p][%10p] [%4p][%10p][%p]\n", (void *)rand, (void*)min, (void*)max, (void*)rand, (void*)min, (void*)max);
printf("%s", "ft_printf\n");
int		pid_bis = ft_printf("[%5.2p][%20p][%12p] [%52p][%0p][%30p]\n", (void *)rand, (void*)min, (void*)max, (void*)rand, (void*)min, (void*)max);
printf("%s", "printf\n");
int		rpid_bis =   printf("[%5.2p][%20p][%12p] [%52p][%0p][%30p]\n", (void *)rand, (void*)min, (void*)max, (void*)rand, (void*)min, (void*)max);

printf("result:[ft_printf:%i::printf:%i][ft_printf:%i::printf:%i]\n", pid, rpid, pid_bis, rpid_bis); */

printf("test 6: %%c\n");
int		pid_bis = ft_printf("[%10c][%-5c][%4c][%3c][%2c][%2c][%20c]\n", 0, -'b', 'c', 'd', 'e', 'f', 'g');
printf("%s", "printf\n");
int		rpid_bis = printf("[%10c][%-5c][%4c][%3c][%2c][%2c][%20c]\n", 0, -'b', 'c', 'd', 'e', 'f', 'g');
printf("[%i][%i]\n", pid_bis, rpid_bis);

/* printf("test 69: %%%%\n");
int		pid_bis = ft_printf("I'm a little teapot short and stout, heres my %% here's my %%%%\n");
printf("%s", "printf\n");
int		rpid_bis = printf("I'm a little teapot short and stout, heres my %% here's my %%%%\n");
printf("[%i][%i]\n", pid_bis, rpid_bis); */
}