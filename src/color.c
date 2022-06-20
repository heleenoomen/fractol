/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:50:05 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/20 13:17:31 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

# define RE 0
# define IM 1

// double    *calc_z(double z[2], double c[2], int i, int depth)
// {
// 	double  z_re_new;
// 	double  z_im_new;

// 	if (i == depth)
// 		return (z);
// 	z_re_new = (z[RE] * z[RE]) - (z[IM] * z[IM]) + c[RE];
// 	z_im_new = (2 * z[RE] * z[IM]) + c[IM];
// 	z[RE] = z_re_new;
// 	z[IM] = z_im_new;
// 	i++;
// 	return (calc_z(z, c, i, depth));

// }

// int	calc_color(double z[2], double c[2], int i, int depth)
// {
// 	double  z_re_new;
// 	double  z_im_new;
	
// 	if (((z[RE] * z[RE]) + (z[IM] * z[IM])) > 4)
// 		return (i);
// 	if (i == depth)
// 		return (i);
// 	z_re_new = (z[RE] * z[RE]) - (z[IM] * z[IM]) + c[RE];
// 	z_im_new = (2 * z[RE] * z[IM]) + c[IM];
// 	z[RE] = z_re_new;
// 	z[IM] = z_im_new;
// 	i++;
// 	return (calc_color(z, c, i, depth));
// }


int	calc_max_iterations(t_fr *fr, double c_re, double c_im)
{
	int		i;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;

	i = fr->depth_min;
	z_re = 0;
	z_im = 0;
	while (i < fr->depth_max)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if ((z_re2 + z_im2) > 4)
			break ;
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

	return (r << 16 | g << 8 | b);
}

void	make_image(t_fr *fr)
{
	double	c[2];

	c[RE] = 0;
	c[IM] = 0;

	while (c[IM] <= fr->win_height)
	{
		while (c[RE] <= fr->win_width)
		{
			color_coord(fr, c[RE], c[IM]);
			c[RE]++;
		}
		c[IM]++;
	}
}

int main(void)
{
	double *z;
	double *c;
	int		color;

	z = malloc(sizeof(double) * 2);
	c = malloc(sizeof(double) * 2);
	z[RE] = 0;
	z[IM] = 0;
	c[RE] = -1.5;
	c[IM] = 1;
	color = calc_color(z, c, 0, 10);
	printf("%i\n", color);
	free(z);
	free(c);
}