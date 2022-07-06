/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv2rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:06:11 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/06 13:02:45 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
// https://wisotop.de/rgb-nach-hsv.php
*/
int	hsv2rgb(double h, double s, double v)
{
	t_hsvrgb	c;

	if (s == 0)
		return (0);
	h /= 60;
	c.i = floor(h);
	c.f = h - c.i;
	c.p = (int) round((v * (1 - s)) * 255);
	c.q = (int) round((v * (1 - s * c.f)) * 255);
	c.t = (int) round(v * (1 - s * (1 - c.f)) * 255);
	c.v = round(v * 255);
	if (c.i == 0)
		return (c.v << 16 | c.t << 8 | c.p);
	else if (c.i == 1)
		return (c.q << 16 | c.v << 8 | c.p);
	else if (c.i == 2)
		return (c.p << 16 | c.v << 8 | c.t);
	else if (c.i == 3)
		return (c.p << 16 | c.q << 8 | c.v);
	else if (c.i == 4)
		return (c.t << 16 | c.p << 8 | c.v);
	return (c.v << 16 | c.p << 8 | c.q);
}
