#include "fractol.h"

void	make_image(t_fr *fr)
{
	double	re;
	double	im;

	im = 0;
	while (im <= fr->win_height)
	{
		re = 0;
		while (re <= fr->win_width)
		{
			calc_fractal(fr, re, im);
			re++;
		}
		im++;
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}


int main(void)
{
	t_fr	fr;

	init(&fr);
	make_image(&fr);
	mlx_hook(fr.win, 17, 0, red_button, &fr);
	mlx_key_hook(fr.win, keyboard, &fr);
	mlx_mouse_hook(fr.win, mouse_event, &fr);
	mlx_loop(fr.mlx);
	return (0);
}
