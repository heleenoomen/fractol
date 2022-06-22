/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:32:54 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/22 16:44:54 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int x, int y, t_fr *fr, double factor)
{
	fr->scope = factor * fr->scope;
	fr->coord_min = x - (fr->scope / 2);
	fr->coord_max = 
}

void	add_depth(int keycode, t_fr *fr)
{
	if (keycode == 7)
	{
		fr->depth_min = fr->depth_max;
		fr->depth_max += 5;
	}
}