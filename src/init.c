/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:00:26 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/01 12:41:37 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_def.h"

void	my_mlx_init(t_win *win)
{
	win->mlx = mlx_init();
	if (win->mlx == NULL)
	{
		perror("mlx_init");
		exit(EXIT_FAILURE);
	}
}

void	init_window(t_win *win)
{
	win->win = mlx_new_window(win->mlx, WINSIZE, WINSIZE, "fractol");
	if (win->win == NULL)
	{
		free(win->mlx);
		perror("mlx_new_window");
		exit(EXIT_FAILURE);
	}
}

void	init_img(t_win *win)
{
	win->img = mlx_new_image(win->mlx, WINSIZE, WINSIZE);
	win->img_addr = mlx_get_data_addr(win->img, &(win->bits_per_pixel), &(win->line_length), &(win->endian));
}

void	init_zoom(t_zoom *zoom)
{
	zoom->depth_max = 600;
	zoom->re_min = -2;
	zoom->im_max = 2;
	zoom->scope = 4;
}

void	init(t_win *window, t_zoom *zoom)
{
	my_mlx_init(window);
	init_window(window);
	init_img(window);
	init_zoom(zoom);
}
