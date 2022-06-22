#include "fractol.h"

int	close_fractol(int keycode, t_fr *fr)
{
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(fr->mlx, fr->win);
		free(fr->mlx);
		exit(0);
	}
	else if (keycode == 7)  // x for add depth
		add_depth(fr);
	else if (keycode == 6)
		remove_depth(fr);
	else if (keycode == 15)  // r for reset
		reset_my_fractal(fr);
	else if (keycode == 35)
		switch_to_pink(fr);
	else if (keycode == 11)
		switch_to_bernstein(fr);
	return (0);
}

int	mouse_event(int button, int x, int y, t_fr *fr)
{
	if (button == 5)
		zoom(x, y, fr, 1.25); // scroll up
	else if (button == 4)
		zoom(x, y, fr, 0.75); // scroll down
	else if (button == 2)
		print_coords(x, y, fr);
	return (x + y);
}

int	red_button(t_fr *fr)
{
	mlx_destroy_window(fr->mlx, fr->win);
	exit(0);
}