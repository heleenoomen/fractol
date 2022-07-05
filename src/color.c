/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:50:05 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/05 19:14:23 by hoomen           ###   ########.fr       */
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

	shift_color(fr->zoom.depth_max, fr->color_shift, &i);
	i_ = (double) i / (double) fr->zoom.depth_max;
	r = round (9 * (1 - i_) * pow(i_, 3) * 255);
	g = round (15 * pow((1 - i_), 2) * pow(i_, 2) * 255);
	b = round (8.5 * pow((1 - i_), 3) * i_ * 255);
	my_mlx_pixel_put(fr, c_re, c_im, (r << 16 | g << 8 | b));
}

void	rainbow(t_fr *fr, double c_re, double c_im, int i)
{
	double	i_;

	if (i == fr->zoom.depth_max)
	{
		my_mlx_pixel_put(fr, c_re, c_im, 0);
		return ;
	}
	shift_color(fr->zoom.depth_max, fr->color_shift, &i);
	i_ = (double) i * 360 / (double) fr->zoom.depth_max;
	my_mlx_pixel_put(fr, c_re, c_im, hsv2rgb(i_, 0.85, 0.85));
}

void	psychedelic(t_fr *fr, double c_re, double c_im, int i)
{
	int	color;

	shift_color(fr->zoom.depth_max, fr->color_shift, &i);
	color = 16581375 * i / fr->zoom.depth_max;   // 0xFFFFFF * iterations / 600
	if (color > 16581375)
		color = (color * -1) + 16581375;
	my_mlx_pixel_put(fr, c_re, c_im, color);
}

void	linear(t_fr *fr, double c_re, double c_im, int i)
{
	if (fr->color_shift == 0)
		my_mlx_pixel_put(fr, c_re, c_im, RGB_RED + 100 * i);
	else if (fr->color_shift == 1)
		my_mlx_pixel_put(fr, c_re, c_im, RGB_ORANGE + 100 * i);
	else if (fr->color_shift == 2)
		my_mlx_pixel_put(fr, c_re, c_im, RGB_YELLOW + 100 * i);
	else if (fr->color_shift == 3)
		my_mlx_pixel_put(fr, c_re, c_im, RGB_LIME + 100 * i);
	else if (fr->color_shift == 4)
		my_mlx_pixel_put(fr, c_re, c_im, RGB_GREEN + 100 * i);
	else if (fr->color_shift == 5)
		my_mlx_pixel_put(fr, c_re, c_im, RGB_BLUE + 100 * i);
	else if (fr->color_shift == 6)
		my_mlx_pixel_put(fr, c_re, c_im, RGB_PURPLE + 100 * i);
	else if (fr->color_shift == 7)
		my_mlx_pixel_put(fr, c_re, c_im, RGB_SIENA + 100 * i);
	else if (fr->color_shift == 8)
		my_mlx_pixel_put(fr, c_re, c_im, RGB_MAGENTA + 100 * i);
	else if (fr->color_shift == 9)
		my_mlx_pixel_put(fr, c_re, c_im, RGB_LINEN + 100 * i);
}