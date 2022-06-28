#include"math.h"
#include"stdio.h"
#include"stdlib.h"

/*
// https://wisotop.de/rgb-nach-hsv.php
*/
void	hsv2rgb(double *r, double *g, double *b, double h, double s, double v)
{
	int	i;
	double f;
	double p;
	double q;
	double t;

	if (s == 0)
	{
		*r = *g = *b = v;
		return ;
	}
	h /= 60;
	i = floor(h);
	f = h - i;
	p = v * (1 - s);
	q = v * (1 - s * f);
	t = v * (1 - s * (1 - f));
	switch(i)
	{
		case 0: *r = v; *g = t; *b = p; break;
		case 1: *r = q; *g = v; *b = p; break;
		case 2: *r = p; *g = v; *b = t; break;
		case 3: *r = p; *g = q; *b = v; break;
		case 4: *r = t; *g = p; *b = v; break;
		default:
			*r = v; *g = p; *b = q; break;
	}
}

// int	main(void)
// {
// 	double	r;
// 	double	g;
// 	double	b;
// 	int		rgb;
// 	hsv2rgb(&r, &g, &b, 10, 1, 1);
// 	printf("%f\n", r);
// 	printf("%f\n", g);
// 	printf("%f\n", b);
// 	rgb = (((int) round(r * 255)) << 16 | ((int) round(g * 255)) << 8 | ((int) round(b * 255)));
// 	printf("%x\n", rgb);
// }