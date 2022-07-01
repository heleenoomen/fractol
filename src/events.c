#include "fractol_def.h"

int	keyboard(int keycode, t_fr *fr)
{
	if (keycode == KC_ESC || keycode == KC_Q)
	{
		mlx_destroy_window(fr->window.mlx, fr->window.win);
		free(fr->window.mlx);
		exit(0);
	}
	//else if (keycode == KC_X)
		//add_depth(fr);
	//else if (keycode == KC_Z)
		//remove_depth(fr);
	//else if (keycode == KC_SPACEBAR)
		//reset_my_fractal(fr);
	// else if (keycode == KC_N)
	// 	switch_color(fr, NATURAL);
	// else if (keycode == KC_P)
	// 	switch_color(fr, PINK);
	// else if (keycode == KC_G)
	// 	switch_color(fr, GREEN);
	// else if (keycode == KC_R)
	// 	switch_color(fr, RAINBOW)
	return (0);
}

int	mouse(int button, int x, int y, t_fr *fr)
{
	if (button == SCROLL_UP)
		zoom(x, y, fr, ZOOM);
	else if (button == SCROLL_DOWN)
		zoom(x, y, fr, 1 / ZOOM);
// 	//else if (button == RIGHT_CLICK)
// 		//print_coords(x, y, fr);
	return (0);
}

int	red_button(t_fr *fr)
{
	mlx_destroy_window(fr->window.mlx, fr->window.win);
	exit(0);
}