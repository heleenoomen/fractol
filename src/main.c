#include "fractol_def.h"
#include <stdio.h>

void	make_image(t_fr *fr)
{
	double	x;
	double	y;
	int		(*calc_iterations)(t_fr *fr, double x, double y);
	void	(*coloring)(t_fr *fr, double x, double y, int i);

	calc_iterations = fr->calc_fractal;
	coloring = fr->coloring;
	y = 0;
	while (y <= WINSIZE)
	{
		x = 0;
		while (x <= WINSIZE)
		{
			coloring(fr, x, y, calc_iterations(fr, x, y));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fr->window.mlx, fr->window.win, fr->window.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fr	fr;
	
	parse_fr(&(fr), argc, argv);
	init(&fr);
	make_image(&fr);
	mlx_hook(fr.window.win, 2, 0, keyboard, &fr);
	mlx_hook(fr.window.win, 17, 0, red_button, &fr);
	mlx_mouse_hook(fr.window.win, mouse, &fr); 
	mlx_loop(fr.window.mlx);
	return (0);
}
