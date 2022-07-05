#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include"ft_printf.h"
#include<ctype.h>
#include<stdbool.h>
// int	ft_pow(int base, int power)
// {
// 	if (power < 0)
// 		return (0);
// 	if (power == 0)
// 		return (1);
// 	return (base * ft_pow(base, power - 1));
// }


int	main(void)
{
	//ft_printf("%f\n", -2);
	double	t;
	unsigned long	sign_bit;
	unsigned long	exponent;
	unsigned long	exp;

	t = 2.0009;
	//sign_bit = (unsigned long) t >> 63;
	exponent = ((unsigned long) t >> 52);
	//exp = sign_bit | exponent;
	s
	printf("%lu\n", exponent);
}