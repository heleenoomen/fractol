/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:58:03 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/04 20:29:21 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_change(t_fr *fr, int keycode)
{
	if (keycode == KC_B)
		fr->coloring = &bernstein;
	else if (keycode == KC_R)
		fr->coloring = &rainbow;
	else if (keycode == KC_P)
		fr->coloring = &psychedelic;
	make_image(fr);
}

void	color_shift(t_fr *fr, int keycode)
{
	if (keycode == KC_0 || keycode == KC_NP_0)
		fr->color_shift = 0;
	else if (keycode == KC_1 || keycode == KC_NP_1)
		fr->color_shift = 1;
	else if (keycode == KC_2 || keycode == KC_NP_2)
		fr->color_shift = 2;
	else if (keycode == KC_3 || keycode == KC_NP_3)
		fr->color_shift = 3;
	else if (keycode == KC_4 || keycode == KC_NP_4)
		fr->color_shift = 4;
	else if (keycode == KC_5 || keycode == KC_NP_5)
		fr->color_shift = 5;
	else if (keycode == KC_6 || keycode == KC_NP_6)
		fr->color_shift = 6;
	else if (keycode == KC_7 || keycode == KC_NP_7)
		fr->color_shift = 7;
	else if (keycode == KC_8 || keycode == KC_NP_8)
		fr->color_shift = 8;
	else if (keycode == KC_9 || keycode == KC_NP_9)
		fr->color_shift = 9;
	make_image(fr);
}

int	keyboard(int keycode, t_fr *fr)
{
	if (keycode == KC_ESC || keycode == KC_Q)
		red_button(fr);
	else if (keycode == KC_SPACEBAR)
		reset_zoom(fr);
	else if (keycode == KC_X)
		add_depth(fr);
	else if (keycode == KC_Z)
		remove_depth(fr);
	else if ((keycode >= KC_1 && keycode <= KC_0)
		|| (keycode >= KC_NP_0 && keycode <= KC_NP_9))
		color_shift(fr, keycode);
	else if (keycode == KC_B || keycode == KC_R || keycode == KC_P)
		color_change(fr, keycode);
	else if (keycode >= KC_ARROW_LEFT && keycode <= KC_ARROW_UP)
		move_view(fr, keycode);
	else if (keycode == KC_CURLY_BR_OPEN || keycode == KC_SEMI_COLON
		|| keycode == KC_QUOT_MARK || keycode == KC_FW_SLASH)
		change_julias_parms(fr, keycode);
	else if (keycode == KC_M || keycode == KC_N || keycode == KC_J)
		switch_fractal(fr, keycode);
	else
		print_info(fr, keycode);
	return (0);
}

int	mouse(int button, int x, int y, t_fr *fr)
{
	if (button == SCROLL_UP)
		zoom(x, y, fr, ZOOM);
	else if (button == SCROLL_DOWN)
		zoom(x, y, fr, 1 / ZOOM);
	else if (button == RIGHT_CLICK)
		switch_to_julia(fr, (double) x, (double) y);
	else if (button == LEFT_CLICK)
		print_coordinates(fr, (double) x, (double) y);
	return (0);
}

int	red_button(t_fr *fr)
{
	mlx_destroy_window(fr->window.mlx, fr->window.win);
	free(fr->window.mlx);
	exit(0);
}
