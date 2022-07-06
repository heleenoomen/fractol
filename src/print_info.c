/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:57:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/06 15:27:51 by hoomen           ###   ########.fr       */
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
	ft_printf("\n\treal axis\t{%f, %f}\n\timaginary axis \
		{%f, %f}\n\n", fr->view.re_min, fr->view.re_min + fr->view.scope,
		fr->view.im_max - fr->view.scope, fr->view.im_max);
}

void	print_coordinates(t_fr *fr, double x, double y)
{	
	conv_to_complex_plain_coord(fr, &x, &y);
	ft_printf("\tcoordinates: {%f, %f}\n", x, y);
}

void	print_julias_parms(t_fr *fr)
{
	if (fr->calc_fractal == &calc_julia)
		ft_printf("\t Julia's parameters: {%f, %f}\n", fr->j_re, fr->j_im);
}

void	print_info(t_fr *fr, int keycode)
{
	if (keycode == KC_C)
		print_current_range(fr);
	else if (keycode == KC_I)
		print_julias_parms(fr);
	else if (keycode == KC_V)
		print_zoom(fr);
	else if (keycode == KC_D)
		ft_printf("\n\tIterations: %i\n", fr->view.depth_max);
	else if (keycode == KC_F1)
		ft_printf("%s\n", USER_INFO);
	else
		ft_printf("Press F1 for available actions\n");
}
