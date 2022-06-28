#include "fractol.h"

void	my_mlx_pixel_put(t_fr *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->img_addr + (y * fr->line_length + x * (fr->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void	color_shift(int depth, int shift, int *i)
{
	if (*i < depth - shift)
		*i = *i + shift;
	else
		*i = (*i - depth) + shift;
}

// double	smooth(t_fr *fr, double re, double im, int i)
// {
// 	double	i_;
// 	double	zn;
// 	zouble	nu;

// 	zn = log(re * re + im * im);
// 	nu = log(zn / log(2)) / log(2);
// 	i_ = i
// }

void	bernstein(t_fr *fr, double c_re, double c_im, int i)
{
	double	i_;
	int	r;
	int	g;
	int	b;
	
	i_ = (double) i / (double) fr->depth_max;
	r = round (9 * (1 - i_) * pow(i_, 3) * 255);
	g = round (15 * pow((1 - i_), 2) * pow(i_, 2) * 255);
	b = round (8.5 * pow((1 - i_), 3) * i_ * 255);
	my_mlx_pixel_put(fr, c_re, c_im, (r << 16 | g << 8 | b));
}

void	pink(t_fr *fr, double c_re, double c_im, int i)
{
	my_mlx_pixel_put(fr, c_re, c_im, i * 2050);
	//my_mlx_pixel_put(fr, c_re, c_im, (0x00FF0000 + (100 * i)));
}

void	rainbow(t_fr *fr, double c_re, double c_im, int i)
{
	double	i_;
	double	r;
	double	g;
	double	b;

	if (i == fr->depth_max)
	{
		my_mlx_pixel_put(fr, c_re, c_im, 0);
		return ;
	}
	i_ = (double) i * 360 / (double) fr->depth_max;
	hsv2rgb(&r, &g, &b, i_, 0.85, 0.85);
	my_mlx_pixel_put(fr, c_re, c_im, (((int) round(r * 255)) << 16 | ((int) round(g * 255)) << 8 | ((int) round(b * 255))));
}
void	shift_color(t_fr *fr)
{
	printf("shift color + 50");
	fr->color_shift += 50;
	make_image(fr);
}

void	shift_color_back(t_fr *fr)
{
	printf("shift color - 50");
	fr->color_shift -= 50;
	make_image(fr);
}

// void	linear(t_fr *fr, double i)
// {
// 	double	index;

// 	index = i / fr->depth_max;
// }

// void	logarithmic(t_fr *fr, double re, double im, int i)
// {
// 	double	zn;
// 	double	nu;
// 	double	i_;

// 	zn = log((re * re) + (im * im)) / 2.0f;
// 	nu = log(zn / log(2)) / log(2);
// 	i_ = (double) i + 1 - nu;
// 	if (i_ < 0)
// 		i_ = 0;
// }
