/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:50:05 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/20 13:02:08 by hoomen           ###   ########.fr       */
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