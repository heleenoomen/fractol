#include "fractol_def.h"

int	main(void)
{
	int	(*calc_fractal)(t_fr *fr, double x, double y);
	char name;
	short i;
	bool b;

	printf("%lu\n", sizeof(calc_fractal));
	printf("%lu\n", sizeof(name));
	printf("%lu\n", sizeof(i));
	printf("%lu\n", sizeof(b));
}