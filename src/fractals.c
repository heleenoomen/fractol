/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:37:07 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/05 11:28:56 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		z_im = (2 * z_re * z_im) + fr->j_im;
		z_re = z_re2 - z_im2 + fr->j_re;
		i++;
	}
	return (i);
}


/*
// for Newton fractal: manipulate iteration number for better coloring
*/
int	adjust_for_coloring(t_fr *fr, int i)
{
	double	j;
	
	j = sqrt(i);
	while ((i * j) > fr->zoom.depth_max)
	{
		i = (i - fr->zoom.depth_max_sqrt) / j;
		j = sqrt(i);
	}
	return ((int) round(i * j));
}

/*
// for Newton fractal: returns true if z is close enough to one of the three solutions for x^3 - 1 = 0
*/
bool	approximates_root(t_cplx z)
{
	t_cplx	roots[3];
	int		i;

	roots[0] = create_complex(1, 0);
	roots[1] = create_complex(-0.5, sqrt(3) / 2);
	roots[2] = create_complex(-0.5, -1 * roots[1].im);
	i = 0;
	while (i < 3)
	{
		if (near_equal_cplx(z, roots[i], TOLERANCE))
			return (true);
		i++;
	}
	return (false);
}

/*
// calculate iterations for newton fractal for fixed function f(x) = x^3 - 1
*/
int	calc_newton(t_fr *fr, double x, double y)
{
	int		i;
	t_cplx	z;
	t_cplx	function;
	t_cplx	derivative;

	conv_to_complex_plain_coord(fr, &x, &y);
	i = 0;
	z = create_complex(x, y);
	while (i < fr->zoom.depth_max)
	{
		if (approximates_root(z))
			return (adjust_for_coloring(fr, i)); 
		derivative = cplx_mul(cplx_mul(z, z), create_complex((double)3, (double)0));
		function = cplx_sub(cplx_mul(z, cplx_mul(z, z)), create_complex((double)1, (double)0));
		function = cplx_div(function, derivative);
		z = cplx_sub(z, function);
		i++;
	}
	return (0);
}
