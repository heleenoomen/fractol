#include "fractol_def.h"
#include <stdio.h>

void	make_image(t_fr *fr)
{
	double	x;
	double	y;
	int		(*calc_fractal)(t_fr *fr, double x, double y);
	void	(*coloring)(t_fr *fr, double x, double y, int i);

	if (fr->parms.fractal == 'M')
		calc_fractal = &calc_mandelbrot;
	else if (fr->parms.fractal == 'J')
		calc_fractal = &calc_julia;
	else
		calc_fractal = &calc_newton;
	if (fr->parms.fractal == 'N')
		coloring = &color_newton;
	else
		coloring = &color_pixel;
	y = 0;
	while (y <= WINSIZE)
	{
		x = 0;
		while (x <= WINSIZE)
		{
			coloring(fr, x, y, calc_fractal(fr, x, y));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fr->window.mlx, fr->window.win, fr->window.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fr	fr;
	
	parse_fr(&(fr.parms), argc, argv);
	init(&(fr.window), &(fr.zoom));
	if (fr.parms.fractal == 'N')
		fr.zoom.depth_max_sqrt = sqrt((double) fr.zoom.depth_max);
	make_image(&fr);
	mlx_hook(fr.window.win, 2, 0, keyboard, &fr);
	mlx_hook(fr.window.win, 17, 0, red_button, &fr);
	mlx_mouse_hook(fr.window.win, mouse, &fr); 
	mlx_loop(fr.window.mlx);
	return (0);
}
