/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:37:07 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/30 13:51:10 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_def.h"

/*
// convert the coordinate of each pixel 
// to the corresponding coordinate in the complex plain
*/
void	conv_to_complex_plain_coord(t_fr *fr, double *x, double *y)
{
	*x = fr->zoom.re_min + ((*x / WINSIZE) * fr->zoom.scope);
	*y = fr->zoom.im_max - ((*y / WINSIZE) * fr->zoom.scope);
}

/*
// calculate after how many iterations the coordinates of a given 
// pixel escape to infinity (i.e. escape z <= |2| )
*/
int	calc_mandelbrot(t_fr *fr, double x, double y)
{
	int		i;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;

	conv_to_complex_plain_coord(fr, &x, &y);
	i = 0;
	z_re = 0;
	z_im = 0;

	while (i < fr->zoom.depth_max)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4)
			return (i);
		z_im = (2 * z_re * z_im) + y;
		z_re = z_re2 - z_im2 + x;
		i++;
	}
	return (i);
}

/*
// calculate iterations for julia fractol
*/
int	calc_julia(t_fr *fr, double x, double y)
{
	int		i;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;

	conv_to_complex_plain_coord(fr, &x, &y);
	i = 0;
	z_re = x;
	z_im = y;
	while (i < fr->zoom.depth_max)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4)
			return (i);
		z_im = (2 * z_re * z_im) + fr->parms.j_im;
		z_re = z_re2 - z_im2 + fr->parms.j_re;
		i++;
	}
	return (i);
}

/*
// calculate iterations for newton fractal
*/
int	calc_newton(t_fr *fr, double x, double y)
{
	int		i;
	double	z_re;
	double	z_im;
	double	z_re_new;
	double	z_im_new;

	conv_to_complex_plain_coord(fr, &x, &y);
	i = 0;
	z_re = x;
	z_im = y;
	while (i < fr->zoom.depth_max)
	{
		if (z_re * z_re + z_im * z_im > 4)
			return (i);
		z_re_new = pow(z_re, 3) - 3 * z_re * pow(z_re, 2);
		z_im_new = pow(z_im, 3) + 3 * pow(z_re, 2) * z_im;
		z_re = z_re_new;
		z_im = z_im_new;
		i++;
	}
	return (i);
}