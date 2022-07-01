#include "fractol_def.h"

/*
// https://wisotop.de/rgb-nach-hsv.php
*/
int	hsv2rgb(double h, double s, double v)
{
	int	i;
	double f;
	int p;
	int q;
	int t;

	if (s == 0)
		return (0);
	h /= 60;
	i = floor(h);
	f = h - i;
	p = (int) round((v * (1 - s)) * 255);
	q = (int) round((v * (1 - s * f)) * 255);
	t = (int) round(v * (1 - s * (1 - f)) * 255);
	v = round(v * 255);
	if (i == 0)
		return (((int) v) << 16 | t << 8 | p);
	else if (i == 1)
		return (q << 16 | ((int) v) << 8 | p);
	else if (i == 2)
		return (p << 16 | ((int) v) << 8 | t);
	else if (i == 3)
		return (p << 16 | q << 8 | (int) v);
	else if (i == 4)
		return (t << 16 | p << 8 | (int) v);
	else
		return (((int) v) << 16 | p << 8 | q);
}