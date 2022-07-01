/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:32:54 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/01 14:52:00 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_def.h"

void	zoom(int x, int y, t_fr *fr, double zoom)
{

	double	re_pos;
	double	im_pos;
	
	re_pos = fr->zoom.re_min + (((double) x / WINSIZE) * fr->zoom.scope);
	im_pos = fr->zoom.im_max - (((double) y / WINSIZE) * fr->zoom.scope);
	if ((zoom > 1 && fr->zoom.scope > 10 && fr->parms.fractal != 'N') || (zoom < 1 && fr->zoom.scope < 0.000000000001))
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

