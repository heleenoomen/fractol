#include "fractol.h"

int	calc_iterations_mandelbrot(t_fr *fr, double c_re, double c_im)
{
	int		i;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;

	c_re = fr->re_min + ((c_re / 500) * fr->scope);
	c_im = fr->im_max - ((c_im / 500) * fr->scope);
	i = 0;
	z_re = 0;
	z_im = 0;
	while (i < fr->depth_max)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if ((z_re2 + z_im2) > 4)
			return (i);
		z_im = (2 * z_re * z_im) + c_im;
		z_re = z_re2 - z_im2 + c_re;
		i++;
	}
	return (i);
}

int	calc_iterations_julia(t_fr *fr, double c_re, double c_im)
{
	int		i;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;

	i = 0;
	z_re = fr->re_min + ((c_re / 500) * fr->scope);
	z_im = fr->im_max - ((c_im / 500) * fr->scope);
	while (i < fr->depth_max)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if ((z_re2 + z_im2) > 4)
			return (i);
		z_im = (2 * z_re * z_im) + fr->j_im;
		z_re = z_re2 - z_im2 + fr->j_re;
		i++;
	}
	return (i);
}

int	calc_newton(t_fr *fr, double re, double im)
{
	int	i;
	double	z_re_old;
	double	z_im_old;
	double	z_re;
	double	z_im;

	z_re = fr->re_min + ((re / 500) * fr->scope);
	z_im = fr->im_max - ((im / 500) * fr->scope);
	i = 0;
	while (i < fr->depth_max)
	{

		if ((z_re * z_re + z_im * z_im) > 4)
			return (i);
		z_re_old = z_re;
		z_im_old = z_im;
		z_re = sin(z_re_old) * cosh(z_im_old);
		z_im = cos(z_re_old) * sinh(z_im_old);
		i++;
	}
	return (i);
}


void	color(t_fr *fr, double re, double im, int i)
{
	if (fr->color_shift)
		color_shift(fr->depth_max, fr->color_shift, &i);
	if (fr->color == 'p')
		pink(fr, re, im, i);
	if (fr->color == 'b')
		bernstein(fr, re, im, i);
	if (fr->color == 'i')
		rainbow(fr, re, im, i);
}

void	calc_fractal(t_fr *fr, double re, double im)
{
	int	i;

	if (fr->type == 'M')
		i = calc_iterations_mandelbrot(fr, re, im);
	else if (fr->type == 'J')
		i = calc_iterations_julia(fr, re, im);
	else
		i = calc_newton(fr, re, im);
	color(fr, re, im, i);
}