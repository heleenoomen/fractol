/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:00:26 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/20 15:03:36 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_init(t_fr *fr)
{
	fr->mlx = mlx_init();
	if (fr->mlx == NULL)
	{
		exit(EXIT_FAILURE);
	}
}

void	init_window(t_fr *fr)
{
	fr->win = mlx_new_window(fr->mlx, fr->win_width, fr->win_height, "fractol");
	if (fr->win == NULL)
	{
		free(fr->mlx);
		exit(EXIT_FAILURE);
	}
}

void	init_img(t_fr *fr)
{
	fr->img = mlx_new_image(fr->mlx, fr->win_width, fr->win_height);
	fr->img_addr = mlx_get_data_addr(fr->img, &(fr->bits_per_pixel), &(fr->line_length), &(fr->endian));
}


void	init(t_fr *fr)
{
	fr->win_width = 500;
	fr->win_height = 500;
	fr->depth_min = 0;
	fr->depth_max = 600;
	my_mlx_init(fr);
	init_window(fr);
	init_img(fr);
}
