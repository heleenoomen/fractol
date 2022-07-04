/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:57:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/04 20:57:57 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_fractal_info(t_fr *fr)
{
	if (fr->calc_fractal == &calc_julia)
		ft_printf(INFO_JULIA);
	else if (fr->calc_fractal == &calc_mandelbrot)
		ft_printf("\n\tMandelbrot set\n");
	else
		ft_printf(INFO_NEWTON);
	ft_printf("\tpress f1 for options\n\n");
}

void	print_current_range(t_fr *fr)
{
	ft_printf("\n\treal axis\t{%.12f, %.12f}\n\timaginary axis \
		{%.12f, %.12f}\n\n", fr->zoom.re_min, fr->zoom.re_min + fr->zoom.scope,
		fr->zoom.im_max - fr->zoom.scope, fr->zoom.im_max);
}

void	print_coordinates(t_fr *fr, double x, double y)
{	
	conv_to_complex_plain_coord(fr, &x, &y);
	ft_printf("\tcoordinates are {%.12f, %.12f}\n", x, y);
}

void	print_julias_parms(t_fr *fr)
{
	if (fr->calc_fractal == &calc_julia)
		ft_printf("\t Julia's parameters: {%.12f, %.12f}\n", fr->j_re, fr->j_im);
}

void	print_info(t_fr *fr, int keycode)
{
	if (keycode == KC_C)
		print_current_range(fr);
	else if (keycode == KC_I)
		print_julias_parms(fr);
	else if (keycode == KC_F1)
		ft_printf("%s\n", USER_INFO);
	else
		ft_printf("Press F1 for available actions\n");
}
