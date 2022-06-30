/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:32:54 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/30 13:25:53 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_def.h"

void	zoom(int x, int y, t_fr *fr, double zoom)
{
	double	re_pos;
	double	im_pos;
	
	re_pos = fr->zoom.re_min + (((double) x / 500) * fr->zoom.scope);
	im_pos = fr->zoom.im_max - (((double) y / 500) * fr->zoom.scope);
	if ((zoom > 1 && fr->scope < 10) || (zoom < 1 && fr->scope > 0.000000000001))
	{
		ft_printf("Zoom max is reached!\n");
		return ;
	}
	fr->zoom.scope = zoom * fr->zoom.scope;
	fr->zoom.re_min = re_pos - (fr->zoom.scope / 2);
	fr->zoom.re_max = re_pos + (fr->zoom.scope / 2);
	fr->zoom.im_min = im_pos - (fr->zoom.scope / 2);
	fr->zoom.im_max = im_pos + (fr->zoom.scope / 2);
	printf("zoom = %.12f\n", fr->zoom);
	printf("scope = %.12f\n", fr->scope);
	make_image(fr);
	return (0);
}

int	add_depth(t_fr *fr)
{
	fr->zoom.depth_min = fr->depth_max;
	fr->zoom.depth_max += 100;
	ft_printf("depth = %i\n", fr->zoom.depth_max);
	make_image(fr);
	return (0);
}

void	remove_depth(t_fr *fr)
{
	fr->zoom.depth_max -= 100;
	ft_printf("depth = %i\n", fr->zoom.depth_max);
	if (fr->zoom.depth_max < 0)
	{
		ft_printf("Mimimum depth is reached\n");
		fr->zoom.depth_max = 0;
	}
	make_image(fr);
}

void	re_init(t_fr *fr)
{
	fr->zoom.depth_max = 600;
	fr->zoom.im_min = -2;
	fr->zoom.im_max = 2;
	fr->zoom.re_max = 2;
	fr->zoom.re_min = -2;
	fr->scope = 4;
	fr->zoom = 1;
}

int	reset_my_fractal(t_fr *fr)
{
	ft_printf("reset fractal\n");
	re_init(fr);
	make_image(fr);
	return (0);
}

// void	switch_to_rainbow(t_fr *fr)
// {
// 	fr->parms.color = 'i';
// 	make_image(fr);
// }

// void	switch_to_bernstein(t_fr *fr)
// {
// 	fr->parms.color = 'b';
// 	make_image(fr);
// }

// void	switch_to_pink(t_fr *fr)
// {
// 	fr->coloring_algorithm = 'p';
// 	make_image(fr);
// }

// void	print_coords(int x, int y, t_fr *fr)
// {
// 	double	re_coord;
// 	double	im_coord;

// 	re_coord = fr->re_min + (x * (fr->scope / 500));
// 	im_coord = fr->im_max - (y * (fr->scope / 500));
// 	printf("x = %f\n", re_coord);
// 	printf("y = %f\n", im_coord);
// }
