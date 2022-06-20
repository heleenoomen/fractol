/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:24:31 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/20 13:31:25 by hoomen           ###   ########.fr       */
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
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		depth_min;
	int		depth_max;
}			t_fr;

# define RE 0
# define IM 1

void	init(t_fr *fr);
void	make_image(t_fr *fr);

#endif