/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:32:54 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/06 12:57:53 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_view(t_fr *fr, int keycode)
{
	if (keycode == KC_ARROW_UP)
		fr->view.im_max += (fr->view.scope / 10);
	else if (keycode == KC_ARROW_DOWN)
		fr->view.im_max -= (fr->view.scope / 10);
	else if (keycode == KC_ARROW_LEFT)
		fr->view.re_min -= (fr->view.scope / 10);
	else
		fr->view.re_min += (fr->view.scope / 10);
	make_image(fr);
}

void	zoom(int x, int y, t_fr *fr, double zoom)
{
	double	re_pos;
	double	im_pos;

	re_pos = fr->view.re_min + (((double) x / WINSIZE) * fr->view.scope);
	im_pos = fr->view.im_max - (((double) y / WINSIZE) * fr->view.scope);
	if ((zoom > 1 && fr->view.scope > 10 && fr->calc_fractal != &calc_newton)
		|| (zoom < 1 && fr->view.scope < 0.000000000001))
	{
		ft_printf("\tZoom max is reached!\n");
		return ;
	}
	fr->view.scope = zoom * fr->view.scope;
	fr->view.re_min = re_pos - (((double) x / WINSIZE) * fr->view.scope);
	fr->view.im_max = im_pos + (((double) y / WINSIZE) * fr->view.scope);
	ft_printf("\tzoom = %.12f\n", 4 / fr->view.scope);
	make_image(fr);
}

void	reset_zoom(t_fr *fr)
{
	fr->view.depth_max = 100;
	if (fr->calc_fractal == &calc_newton)
		fr->view.depth_max_sqrt = sqrt((double) fr->view.depth_max);
	fr->view.im_max = 2;
	fr->view.re_min = -2;
	fr->view.scope = 4;
	ft_printf("\treset fractal\n");
	make_image(fr);
}

void	add_depth(t_fr *fr)
{
	fr->view.depth_max += 20;
	make_image(fr);
	ft_printf("\tdepth: %i iterations\n", fr->view.depth_max);
}

void	remove_depth(t_fr *fr)
{
	if (fr->view.depth_max > 20)
		fr->view.depth_max -= 20;
	else if (fr->view.depth_max > 0)
		fr->view.depth_max--;
	else
	{
		ft_printf("\tdepth is zero\n\tpress x to increase depth\n");
		return ;
	}
	make_image(fr);
	ft_printf("\tdepth: %i iterations\n", fr->view.depth_max);
}
