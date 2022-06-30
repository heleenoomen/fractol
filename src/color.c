/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:50:05 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/30 13:52:44 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_def.h"

void	my_mlx_pixel_put(t_fr *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->window.img_addr + (y * fr->window.line_length + x * (fr->window.bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void	rainbow(t_fr *fr, double c_re, double c_im, int i)
{
	double i_;
	int		r;
	int		g;
	int		b;

	i_ = (double) (i + 1) / (double) (fr->zoom.depth_max);

	r = round (9 * (1 - i_) * pow(i_, 3) * -255 * log(i_));
	g = round (15 * pow((1 - i_), 2) * pow(i_, 2) * -255 * log(i_));
	b = round (8.5 * pow((1 - i_), 3) * i_ * -255 * log(i_));
	my_mlx_pixel_put(fr, c_re, c_im, (r << 16 | g << 8 | b));
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

void	pink(t_fr *fr, double c_re, double c_im, int i)
{
	my_mlx_pixel_put(fr, c_re, c_im, (0x00FF0000 + (100 * i)));
}

void	color_pixel(t_fr *fr, double c_re, double c_im, int i)
{
	if (fr->parms.color == NATURAL || fr->parms.color == DEFAULT_COLORS)
		natural(fr, c_re, c_im, i);
	else if (fr->parms.color  == PINK || fr->parms.color == GREEN)
		pink(fr, c_re, c_im, i);
	//else if (fr->parms.color  == GREEN)
		//green(fr, c_re, c_im, i);
	else if (fr->parms.color  == RAINBOW)
		rainbow(fr, c_re, c_im, i);
}

