#include "fractol.h"

int	close_fractol(int keycode, t_fr *fr)
{
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(fr->mlx, fr->win);
		free(fr->mlx);
		exit(0);
	}
	return (0);
}

int	mouse_event(int button, int x, int y, t_fr *fr)
{
	if (button == 1 && fr->win == NULL)
	{
		free(fr->mlx);
		exit(0);
	}
	// if (button == 5)
	// 	zoom(x, y, fr, 1.03);
	// else if (button == 4)
	// 	zoom(x, y, fr, 0.97);
	return (x + y);
}

int	red_button(t_fr *fr)
{
	mlx_destroy_window(fr->mlx, fr->win);
	exit(0);
}