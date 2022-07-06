/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:50:05 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/06 12:54:11 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fr *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->window.img_addr + (y * fr->window.line_length + x
			* (fr->window.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	shift_color(int depth, int shift, int *i)
{
	if (shift == 0)
		return ;
	if (*i < depth - shift * depth / 10)
		*i = *i + shift * depth / 10;
	else
		*i = *i - depth + shift * depth / 10;
}

void	bernstein(t_fr *fr, double c_re, double c_im, int i)
{
	double	i_;
	int		r;
	int		g;
	int		b;

	shift_color(fr->view.depth_max, fr->color_shift, &i);
	i_ = (double) i / (double) fr->view.depth_max;
	r = round (9 * (1 - i_) * pow(i_, 3) * 255);
	g = round (15 * pow((1 - i_), 2) * pow(i_, 2) * 255);
	b = round (8.5 * pow((1 - i_), 3) * i_ * 255);
	my_mlx_pixel_put(fr, c_re, c_im, (r << 16 | g << 8 | b));
}

void	rainbow(t_fr *fr, double c_re, double c_im, int i)
{
	double	i_;

	if (i == fr->view.depth_max)
	{
		my_mlx_pixel_put(fr, c_re, c_im, 0);
		return ;
	}
	shift_color(fr->view.depth_max, fr->color_shift, &i);
	i_ = (double) i * 360 / (double) fr->view.depth_max;
	my_mlx_pixel_put(fr, c_re, c_im, hsv2rgb(i_, 0.85, 0.85));
}

void	psychedelic(t_fr *fr, double c_re, double c_im, int i)
{
	int	color;

	shift_color(fr->view.depth_max, fr->color_shift, &i);
	color = RGB_MAX * i / fr->view.depth_max;
	if (color > RGB_MAX)
		color = (color * -1) + RGB_MAX;
	my_mlx_pixel_put(fr, c_re, c_im, color);
}
