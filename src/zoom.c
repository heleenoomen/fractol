#include "fractol.h"

int	zoom(int x, int y, t_fr *fr, double factor)
{
	double	re_pos;
	double	im_pos;
	

	printf("factor = %f\n", factor);
	re_pos = fr->re_min + (((double) x / 500) * fr->scope);
	im_pos = fr->im_max - (((double) y / 500) * fr->scope);
	if (factor > 1 && fr->zoom < 1)
		fr->zoom = 1;
	else if (factor < 1 && fr->zoom > 1)
		fr->zoom = 1;
	if ((factor > 1 && fr->scope < 10) || (factor < 1 && fr->scope > 0.0000000000001))
		fr->zoom = factor * fr->zoom;
	else
	{
		printf("zoom max is reached!");
		fr->zoom = 1;
	}	
	fr->scope = fr->zoom * fr->scope;
	fr->re_min = re_pos - (fr->scope / 2);
	fr->re_max = re_pos + (fr->scope / 2);
	fr->im_min = im_pos - (fr->scope / 2);
	fr->im_max = im_pos + (fr->scope / 2);
	printf("factor = %.20f\n", factor);
	printf("scope = %.20f\n", fr->scope);
	printf("---------------------------\n");
	make_image(fr);
	return (0);
}

//void	translate(int x, int y, t_fr *fr, double factor)

int	add_depth(t_fr *fr)
{
	fr->depth_min = fr->depth_max;
	fr->depth_max += 10;
	printf("depth = %i\n", fr->depth_max);
	make_image(fr);
	return (0);
}

void	remove_depth(t_fr *fr)
{
	fr->depth_max -= 10;
	printf("depth = %i\n", fr->depth_max);
	make_image(fr);
	if (fr->depth_max < 0)
	{
		printf("Mimimum depth is reached\n");
		fr->depth_max = 0;
	}
}


void	shift_julia(t_fr *fr, int keycode)
{
	if (keycode == 65363)
		fr->j_re += 0.01;
	else if (keycode == 65361)
		fr->j_re -= 0.01;
	else if (keycode == 65362)
		fr->j_im += 0.01;
	else
		fr->j_im -= 0.01;
	make_image(fr);
}

void	switch_to_rainbow(t_fr *fr)
{
	fr->color = 'i';
	make_image(fr);
}

void	re_init(t_fr *fr)
{
	fr->depth_max = 600;
	fr->depth_min = 0;
	fr->im_min = -2;
	fr->im_max = 2;
	fr->re_min = -2;
	fr->re_max = 2;
	fr->scope = 4;
	fr->zoom = 1;
}

int	reset_my_fractal(t_fr *fr)
{
	printf("reset fractal\n");
	re_init(fr);
	make_image(fr);
	return (0);
}

void	switch_to_bernstein(t_fr *fr)
{
	fr->color = 'b';
	fr->color_shift = 0;
	make_image(fr);
}

void	switch_to_pink(t_fr *fr)
{
	fr->color = 'p';
	fr->color_shift = 0;
	make_image(fr);
}

void	print_coords(int x, int y, t_fr *fr)
{
	double	re_coord;
	double	im_coord;

	re_coord = fr->re_min + (x * (fr->scope / 500));
	im_coord = fr->im_max - (y * (fr->scope / 500));
	printf("x = %f\n", re_coord);
	printf("y = %f\n", im_coord);
}