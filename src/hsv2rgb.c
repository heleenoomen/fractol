#include "fractol.h"

/*
// make a color spectrum using 'clamped'  sine waves for red, green and blue
// http://justinparrtech.com/JustinParr-Tech/spectrum-generating-color-function-using-sine-waves/
*/
int	spectrum(double i_normalized)
{
	double	a;
	int		r;
	int		g;
	int		b;

	a = ((2 * M_PI * 255) / (3 * i_normalized)) + (M_PI / 2);
	r = round((sin(a) * 192) + 128);
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	g =  round((sin(a - (2 * M_PI / 3)) * 192) + 128);
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	b = round((sin(a - (4 * M_PI / 3)) * 192) + 128);
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	return (r << 16 | g << 8 | b);
}


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