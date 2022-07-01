/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:32:54 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/01 16:40:01 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_def.h"

void	zoom(int x, int y, t_fr *fr, double zoom)
{

	double	re_pos;
	double	im_pos;
	
	re_pos = fr->zoom.re_min + (((double) x / WINSIZE) * fr->zoom.scope);
	im_pos = fr->zoom.im_max - (((double) y / WINSIZE) * fr->zoom.scope);
	if ((zoom > 1 && fr->zoom.scope > 10 && fr->calc_fractal != &calc_newton) || (zoom < 1 && fr->zoom.scope < 0.000000000001))
	{
		ft_printf("Zoom max is reached!\n");
		return ;
	}
	fr->zoom.scope = zoom * fr->zoom.scope;
	fr->zoom.re_min = re_pos - (((double) x / WINSIZE) * fr->zoom.scope);
	fr->zoom.im_max = im_pos + (((double) y / WINSIZE) * fr->zoom.scope);
	printf("scope = %.12f\n", fr->zoom.scope);
	make_image(fr);
}

void	reset_zoom(t_fr *fr)
{
	fr->zoom.depth_max = 600;
	if (fr->calc_fractal == &calc_newton)
		fr->zoom.depth_max_sqrt = sqrt((double) fr->zoom.depth_max);
	fr->zoom.im_max = 2;
	fr->zoom.re_min = -2;
	fr->zoom.scope = 4;
	ft_printf("reset fractal\n");
	make_image(fr);
}