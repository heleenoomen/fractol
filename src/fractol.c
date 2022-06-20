/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:50:05 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/20 15:09:45 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

# define RE 0
# define IM 1

int main(void)
{
	t_fr	fr;

	init(&fr);
	make_image(&fr);
	mlx_put_image_to_window(fr.mlx, fr.win, fr.img, 0, 0);
	mlx_loop(fr.mlx);
}

// void	picture(t_fr *fr)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (y < fr->win_height)
// 	{
// 		x = 0;

// 		my_mlx_pixel_put(fr, 20, i, 0x00FF0000);
// 		my_mlx_pixel_put(fr, 60, i, 0x00EE0000);
// 		i++;
// 	}	
// }

// int	main(void)
// {
// 	t_fr	fr;

// 	fr.win_width = 500;
// 	fr.win_height = 500;
// 	init(&fr);
// 	picture(&fr);
// 	mlx_put_image_to_window(fr.mlx, fr.win, fr.img, 0, 0);
// 	mlx_loop(fr.mlx);
// }
