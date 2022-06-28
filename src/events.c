#include "fractol.h"

int	red_button(t_fr *fr)
{
	mlx_destroy_window(fr->mlx, fr->win);
	exit(0);
}

int	keyboard(int keycode, t_fr *fr)
{
	printf("keypress: %i\n", keycode);
	if (keycode == 113 || keycode == 65307)
	{
		mlx_destroy_window(fr->mlx, fr->win);
		exit(0);
	}
	else if (keycode == 120)  // x for add depth
		add_depth(fr);
	else if (keycode == 122)
		remove_depth(fr);
	else if (keycode == 114)  // r for reset
		reset_my_fractal(fr);
	else if (keycode == 112)
		switch_to_pink(fr);
	else if (keycode == 98)
		switch_to_bernstein(fr);
	else if (keycode == 105)
		switch_to_rainbow(fr);
	else if (keycode == 115) // s for color_shift
		shift_color(fr);
	else if (keycode == 97)
		shift_color_back(fr);
	else if (keycode >= 65361 && keycode <= 65364 )
		shift_julia(fr, keycode); // -> plus j_re
	return (0);
}

int	mouse_event(int button, int x, int y, t_fr *fr)
{
	if (button == 4)
		zoom(x, y, fr, 1.25); // scroll up
	else if (button == 5)
		zoom(x, y, fr, 0.75); // scroll down
	else if (button == 2)
		print_coords(x, y, fr);
	return (x + y);
}