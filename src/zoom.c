/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:32:54 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/22 21:42:05 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom(int x, int y, t_fr *fr, double factor)
{
	double	re_pos;
	double	im_pos;
	
	// printf("scope old = %f\n", fr->scope);
	// printf("re_min old = %f\n", fr->re_min);
	// printf("x = %i\n", x);
	// printf("y = %i\n", y);
	printf("factor = %f\n", factor);
	re_pos = fr->re_min + (((double) x / 500) * fr->scope);
	im_pos = fr->im_max - (((double) y / 500) * fr->scope);
	// printf("re_pos = %f\n", re_pos);
	// printf("im_pos = %f\n", im_pos);
	if (factor > 1 && fr->zoom < 1)
		fr->zoom = 1;
	else if (factor < 1 && fr->zoom > 1)
		fr->zoom = 1;
	if ((factor > 1 && fr->scope < 10) || (factor < 1 && fr->scope > 0.0000000000001))
		fr->zoom = factor * fr->zoom;
	else
	{
		printf("zoom max is reached!");
		fr->zoom = 1;
	}	
	fr->scope = fr->zoom * fr->scope;
	// printf("scope new = %f\n", fr->scope);
	fr->re_min = re_pos - (fr->scope / 2);
	fr->re_max = re_pos + (fr->scope / 2);
	fr->im_min = im_pos - (fr->scope / 2);
	fr->im_max = im_pos + (fr->scope / 2);
	// printf("zoom = %f\n", fr->zoom);
	// printf("re_min = %f\n", fr->re_min);
	// printf("re_max = %f\n", fr->re_max);
	// printf("im_min = %f\n", fr->im_min);
	// printf("im_max = %f\n", fr->im_max);
	printf("factor = %.20f\n", factor);
	printf("scope = %.20f\n", fr->scope);
	printf("---------------------------\n");
	make_image(fr);
	return (0);
}

//void	translate(int x, int y, t_fr *fr, double factor)

int	add_depth(t_fr *fr)
{
	fr->depth_min = fr->depth_max;
	fr->depth_max += 10;
	printf("depth = %i\n", fr->depth_max);
	make_image(fr);
	return (0);
}

void	remove_depth(t_fr *fr)
{
	fr->depth_max -= 10;
	if (fr->depth_max < 0)
	{
		printf("Mimimum depth is reached\n");
		fr->depth_max = 0;
	}
}

void	re_init(t_fr *fr)
{
	fr->depth_max = 600;
	fr->depth_min = 0;
	fr->im_min = -2;
	fr->im_max = 2;
	fr->re_min = -2;
	fr->re_max = 2;
	fr->scope = 4;
	fr->zoom = 1;
}

int	reset_my_fractal(t_fr *fr)
{
	printf("reset fractal\n");
	re_init(fr);
	make_image(fr);
	return (0);
}

void	switch_to_bernstein(t_fr *fr)
{
	fr->coloring_algorithm = 'b';
	make_image(fr);
}

void	switch_to_pinkt(t_fr *fr)
{
	fr->coloring_algorithm = 'p';
	make_image(fr);
}

void	print_coords(int x, int y, t_fr *fr)
{
	double	re_coord;
	double	im_coord;

	re_coord = fr->re_min + (x * (fr->scope / 500));
	im_coord = fr->im_max - (y * (fr->scope / 500));
	printf("x = %f\n", re_coord);
	printf("y = %f\n", im_coord);
}
