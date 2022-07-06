/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:52:49 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/06 20:37:24 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_julias_parms(t_fr *fr, int keycode)
{
	if (keycode == KC_CURLY_BR_OPEN)
		fr->j_im += 0.001;
	else if (keycode == KC_FW_SLASH)
		fr->j_im -= 0.001;
	else if (keycode == KC_SEMI_COLON)
		fr->j_re -= 0.001;
	else
		fr->j_re += 0.001;
	make_image(fr);
}

void	switch_to_julia(t_fr *fr, double x, double y)
{
	conv_to_complex_plain_coord(fr, &x, &y);
	fr->j_re = x;
	fr->j_im = y;
	fr->calc_fractal = &calc_julia;
	make_image(fr);
	print_fractal_info(fr);
}

void	switch_fractal(t_fr *fr, int keycode)
{
	if (keycode == KC_M)
		fr->calc_fractal = &calc_mandelbrot;
	else if (keycode == KC_N)
	{
		reset_zoom(fr);
		fr->calc_fractal = &calc_newton;
	}
	else if (keycode == KC_J)
	{
		fr->j_im = J_IM_DEFAULT;
		fr->j_re = J_RE_DEFAULT;
		fr->calc_fractal = &calc_julia;
	}
	make_image(fr);
	print_fractal_info(fr);
}
