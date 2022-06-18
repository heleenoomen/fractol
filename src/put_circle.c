/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:03:09 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/18 19:16:05 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    circle_pos_rad(t_circle *circle, int center_x, int center_y, int radius)
{
    circle->center_y = center_y;
    circle->center_x = center_x;
    circle->radius = radius;
}

void    circle_appearance(t_circle *circle, int linethickness, int definition, int colour)
{
    circle->fat = linethickness;
    circle->definition = definition;
    circle->colour = colour;
}

void    circle_fill(t_circle *circle, bool fill)
{
    circle->fill = fill;
}


void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->img_addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void    put_circle(t_img *img, t_circle *circle)
{
    float x_coord;
    float y_coord;
    float border;

    border = circle->radius + circle->fat;
    while (circle->radius < border)
	{
		y_coord = circle->center_y - circle->radius;
		while (y_coord <= (circle->center_y + circle->radius))
		{
			x_coord = circle->center_x - circle->radius;
			while (x_coord <= (circle->center_x + circle->radius))
			{
				if ((powf(x_coord - circle->center_x, 2) + powf(y_coord - circle->center_y, 2)) >= (powf(circle->radius, 2) - circle->definition)
				    &&	(powf(x_coord - circle->center_x, 2) + powf(y_coord - circle->center_y, 2)) <= (powf(circle->radius, 2)) + circle->definition)
                    my_mlx_pixel_put(img, (int) x_coord, (int) y_coord, circle->colour);//printf("x = %f, y = %f\n", x_coord, y_coord);
                else if (circle->fill == 1 
                    && (powf(x_coord - circle->center_x, 2) + powf(y_coord - circle->center_y, 2)) <= (powf(circle->radius, 2)) + circle->definition)
                    my_mlx_pixel_put(img, (int) x_coord, (int) y_coord, circle->colour);//printf("y = %f\n", y_coord);//
				x_coord++;
			}
			y_coord++;
		}
		circle->radius++;
	}
}

void    make_circles(t_img *img, t_circle *circle)
{
    circle_pos_rad(circle, 800, 800, 50);
    circle_appearance(circle, 5, 60, 0xA0EEFF00);
    circle_fill(circle, 0);
    put_circle(img, circle);
    circle_pos_rad(circle, 400, 400, 100);
    circle_appearance(circle, 3, 100, 0x0000FF00);
    circle_fill(circle, 0);
    put_circle(img, circle);
    circle_pos_rad(circle, 1200, 500, 80);
    circle_appearance(circle, 3, 80, 0x00EEAA00);
    circle_fill(circle, 0);
    put_circle(img, circle);
    circle_pos_rad(circle, 1600, 100, 90);
    circle_appearance(circle, 2, 90, 0x00BB00CC);
    circle_fill(circle, 0);
    put_circle(img, circle);
}
