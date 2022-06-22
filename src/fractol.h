/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:24:31 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/22 16:45:21 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H


# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include <ctype.h>
# include <stdio.h>

typedef struct s_fr
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	void	*img;
	void	*img_addr;
	double	zoom;
	double	min_coord;
	double	max_coord;
	double	scope;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		depth_min;
	int		depth_max;
	int		depth_max_practice;
}			t_fr;

# define RE 0
# define IM 1

void	init(t_fr *fr);
void	make_image(t_fr *fr);
void	my_mlx_pixel_put(t_fr *fr, int x, int y, int color);
void	my_mlx_init(t_fr *fr);
int		close_fractol(int keycode, t_fr *fr);
int		mouse_event(int button, int x, int y, t_fr *fr);
int		red_button(t_fr *fr);

#endif