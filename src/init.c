/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:00:26 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/06 12:56:29 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	win->img_addr = mlx_get_data_addr(win->img,
			&(win->bits_per_pixel), &(win->line_length), &(win->endian));
}

void	init_view(t_view *view)
{
	view->depth_max = 100;
	view->re_min = -2;
	view->im_max = 2;
	view->scope = 4;
}

void	init(t_fr *fr)
{
	my_mlx_init(&(fr->window));
	init_window(&(fr->window));
	init_img(&(fr->window));
	init_view(&(fr->view));
	if (fr->calc_fractal == &calc_newton)
		fr->view.depth_max_sqrt = sqrt((double) fr->view.depth_max);
	fr->color_shift = 0;
}
