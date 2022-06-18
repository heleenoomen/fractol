/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:00:26 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/18 19:16:55 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_win *win)
{
	win->mlx = mlx_init();
	if (win->mlx == NULL)
	{
		exit(EXIT_FAILURE);
	}
}

void	init_window(t_win *win)
{
	win->win = mlx_new_window(win->mlx, 1920, 1080, "fractol");
	if (win->mlx == NULL)
	{
		free(win->mlx);
		exit(EXIT_FAILURE);
	}
}

void	init_img(t_win *win, t_img *img)
{
	img->img = mlx_new_image(win->mlx, 1920, 1080);
	img->img_addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
}

int	main(void)
{
	t_win		win;
	t_img		img;
	t_circle	circle;

	init_mlx(&win);
	init_window(&win);
	init_img(&win, &img);
	make_circles(&img, &circle);
	mlx_put_image_to_window(win.mlx, win.win, img.img, 0, 0);
	mlx_loop(win.mlx);
}