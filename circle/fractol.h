/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:24:31 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/20 13:26:04 by hoomen           ###   ########.fr       */
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

typedef struct	s_win
{
	void	*mlx;
	void	*win;
}				t_win;

typedef struct	s_img
{
	void	*img;
	void	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_circle
{
	float	center_y;
	float	center_x;
	float	radius;
	int		fat;
	int		definition;
	bool	fill;
	int		colour;
}			t_circle;

void    make_circles(t_img *img, t_circle *circle);

#endif
