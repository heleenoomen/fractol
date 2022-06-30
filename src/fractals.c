/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:37:07 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/30 21:12:50 by hoomen           ###   ########.fr       */
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

t_cplx	cplx_mul(t_cplx x, t_cplx y)
{
	t_cplx	m;

	m.re = x.re * y.re - x.im * y.im;
	m.im = x.re * y.im + x.im * y.re;
	return (m);
}

/*
// divide x by y, from: https://www.cuemath.com/numbers/division-of-complex-numbers/
*/
t_cplx	cplx_div(t_cplx x, t_cplx y)
{
	t_cplx	m;

	m.re = ((x.re * y.re) + (x.im * y.im)) / ((y.re * y.re) + (y.im * y.im));
	m.im = ((x.im * y.re) - (x.re * y.im)) / ((y.re * y.re) + (y.im * y.im));
	return (m);
}

/*
// find nearest root for newton
*/
void	make_roots(t_cplx *roots1, t_cplx *roots2, t_cplx *roots3)
{
	roots1->re = 1;
	roots1->im = 0;
	roots2->re = -.5;
	roots2->im = sqrt(3) / 2;
	roots3->re = -.5;
	roots3->im = -1 * roots2->im;
}
/*
// multiply real number by complex number
*/
t_cplx	create_complex(double re, double im)
{
	t_cplx cplx_nbr;

	cplx_nbr.re = re;
	cplx_nbr.im = im;

	return(cplx_nbr);
}

/*
// calculate iterations for newton fractal
*/
int	calc_newton(t_fr *fr, double x, double y)
{
	int		i;
	t_cplx	z;
	t_cplx	function;
	t_cplx	derivative;
	t_cplx	roots[3];

	conv_to_complex_plain_coord(fr, &x, &y);
	make_roots(&roots[0], &roots[1], &roots[2]);
	i = 0;
	z.re = x;
	z.im = y;
	while (i < fr->zoom.depth_max)
	{
		if (pow(z.im - roots[0].im, 2) < 0.00001 && pow(z.re - roots[0].re, 2) < 0.00001)
			// return (i);
		{
			if (i % 3 == 0)
				return (3);
			return (i % 3);
		}
		if (pow(z.im - roots[1].im, 2) < 0.00001 && pow(z.re - roots[1].re, 2) < 0.00001)
			//return (i);
		{
			if (i % 3 == 0)
				return (3);
			return (i % 3);
		}
		if (pow(z.im - roots[2].im, 2) < 0.00001 && pow(z.re - roots[2].re, 2) < 0.00001)
			//return (i);
		{
			if (i % 3 == 0)
				return (3);
			return (i % 3);
		}
		derivative = cplx_mul(cplx_mul(z, z), create_complex((double)3, (double)0));
		// if ((derivative.im * derivative.im) < 0.00001 && (derivative.re * derivative.re) < 0.00001)
		// {
		// 	if (i % 3 == 0)
		// 		return (3);
		// 	return (i % 3);
		// }
		function = cplx_mul(z, cplx_mul(z, z));
		function.re--;
		function = cplx_div(function, derivative);
		z.re -= function.re;
		z.im -= function.im;
		i++;
	}
	//return (i);
	return (0);
}
