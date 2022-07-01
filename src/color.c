/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:50:05 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/01 15:51:19 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_def.h"

void	my_mlx_pixel_put(t_fr *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->window.img_addr + (y * fr->window.line_length + x * (fr->window.bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void	natural(t_fr *fr, double c_re, double c_im, int i)
{
	double	i_;
	int	r;
	int	g;
	int	b;

	i_ = (double) i / (double) fr->zoom.depth_max;
	r = round (9 * (1 - i_) * pow(i_, 3) * 255);
	g = round (15 * pow((1 - i_), 2) * pow(i_, 2) * 255);
	b = round (8.5 * pow((1 - i_), 3) * i_ * 255);
	my_mlx_pixel_put(fr, c_re, c_im, (r << 16 | g << 8 | b));
}

void	psychedelic(t_fr *fr, double c_re, double c_im, int i)
{
	my_mlx_pixel_put(fr, c_re, c_im, 70000 * i);
}

void	pink(t_fr *fr, double c_re, double c_im, int i)
{
	my_mlx_pixel_put(fr, c_re, c_im, (0x00FF0000 + (100 * i)));
}

void	three_colors_only(t_fr *fr, double x, double y, int i)
{
	if (i == 0)
		my_mlx_pixel_put(fr, x, y, 0);
	if ((i % 3) + 1 == 1)
		my_mlx_pixel_put(fr, x, y, 0xCCFFE5);
	if ((i % 3) + 1 == 2)
		my_mlx_pixel_put(fr, x, y, 0xDA8404);
	if ((i % 3) + 1 == 3)
		my_mlx_pixel_put(fr, x, y, 0x921414);
}

void	rainbow(t_fr *fr, double c_re, double c_im, int i)
{
	double	i_;

	if (i == fr->zoom.depth_max)
	{
		my_mlx_pixel_put(fr, c_re, c_im, 0);
		return ;
	}
	i_ = (double) i * 360 / (double) fr->zoom.depth_max;
	my_mlx_pixel_put(fr, c_re, c_im, hsv2rgb(i_, 0.85, 0.85));
}

void	color_newton(t_fr *fr, double x, double y, int i)
{
	double	j;
	
	if (fr->color == &three_colors_only)
	{
		three_colors_only(fr, x, y, i);
		return ;
	}
	j = sqrt(i);
	while ((i * j) > fr->zoom.depth_max)
	{
		i = (i - fr->zoom.depth_max_sqrt) / j;
		j = sqrt(i);
	}
	i = (int) round(i * j);
	color_pixel(fr, x, y, i);
}

void	color_pixel(t_fr *fr, double x, double y, int i)
{
	fr->color(fr, x, y, i);
	
	// if (fr->parms.color == NATURAL || fr->parms.color == DEFAULT_COLORS)
	// 	natural(fr, c_re, c_im, i);
	// else if (fr->parms.color  == PINK)
	// 	pink(fr, c_re, c_im, i);
	// else if (fr->parms.color  == GREEN)
	// 	psychedelic(fr, c_re, c_im, i);
	// else if (fr->parms.color  == RAINBOW)
	// 	rainbow(fr, c_re, c_im, i);
}

