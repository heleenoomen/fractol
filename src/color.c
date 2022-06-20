/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:50:05 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/20 15:58:14 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fr *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->img_addr + (y * fr->line_length + x * (fr->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int	calc_max_iterations(t_fr *fr, double c_re, double c_im)
{
	int		i;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;

	c_re = fr->null_coord + ((c_re / 500) * 4);
	c_im = fr->null_coord + ((c_im / 500) * 4);
	i = fr->depth_min;
	z_re = 0;
	z_im = 0;
	while (i < fr->depth_max)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if ((z_re2 + z_im2) > 4)
			return (i);
		z_im = (2 * z_re * z_im) + c_im;
		z_re = z_re2 - z_im2 + c_re;
		i++;
	}
	return (i);
}

void	color_coord(t_fr *fr, double c_re, double c_im)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = calc_max_iterations(fr, c_re, c_im);
	r = round (9 * (1 - i) * pow(i, 3) * 255);
	g = round (15 * pow((1 - i), 2) * pow(i, 2) * 255);
	b = round (8.5 * pow((1 - i), 3) * i * 255);
	my_mlx_pixel_put(fr, c_re, c_im, (r << 16 | g << 8 | b));
}

void	init_coords(t_fr *fr)
{
	fr->zoom = 0;
	fr->null_coord = -2;
	fr->step = 4 / fr->win_height;
}


void	make_image(t_fr *fr)
{
	double	c[2];

	init_coords(fr);
	c[IM] = 0;
	while (c[IM] <= fr->win_height)
	{
		c[RE] = 0;
		while (c[RE] <= fr->win_width)
		{
			//my_mlx_pixel_put(fr, c[RE], c[IM], 0x00EEAA00);
			color_coord(fr, c[RE], c[IM]);
			c[RE]++;// += fr->step;
		}
		c[IM]++; //+=fr->step;
	}
}
