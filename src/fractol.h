#ifndef FRACTOL_H
# define FRACTOL_H


# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include <ctype.h>
# include <stdio.h>

typedef struct s_fr
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	void	*img;
	void	*img_addr;
	double	zoom;
	double	zoom_modus;
	double	re_min;
	double	re_max;
	double	im_min;
	double	im_max;
	double	j_im;
	double	j_re;
	double	scope;
	char	color;
	int		color_shift;
	bool	smooth;
	char	type;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		depth_min;
	int		depth_max;
	double	z_abs;
}			t_fr;

# define ZOOM_INIT -1
# define ZOOM_IN 0
# define ZOOM_OUT 1


//main.c
void	make_image(t_fr *fr);

//events.c
void	init(t_fr *fr);
int		red_button(t_fr *fr);
int		keyboard(int keycode, t_fr *fr);
int		mouse_event(int button, int x, int y, t_fr *fr);

//fractals.c
void	calc_fractal(t_fr *fr, double re, double im);

//color.c
void	color_shift(int depth, int shift, int *i);
void	pink(t_fr *fr, double c_re, double c_im, int i);
void	rainbow(t_fr *fr, double c_re, double c_im, int i);
void	bernstein(t_fr *fr, double c_re, double c_im, int i);
void	shift_color(t_fr *fr);
void	shift_color_back(t_fr *fr);
void	toggle_smooth(t_fr *fr);

//zoom.c
int		zoom(int x, int y, t_fr *fr, double factor);
int		add_depth(t_fr *fr);
void	remove_depth(t_fr *fr);
void	re_init(t_fr *fr);
int		reset_my_fractal(t_fr *fr);
void	switch_to_bernstein(t_fr *fr);
void	switch_to_pink(t_fr *fr);
void	switch_to_rainbow(t_fr *fr);
void	print_coords(int x, int y, t_fr *fr);
void	shift_julia(t_fr *fr, int keycode);

//hsv2rgb.c
void	hsv2rgb(double *r, double *g, double *b, double h, double s, double v);


//void	make_image(t_fr *fr);
//void	my_mlx_pixel_put(t_fr *fr, int x, int y, int color);
//void	my_mlx_init(t_fr *fr);
//int		close_fractol(int keycode, t_fr *fr);
//int		mouse_event(int button, int x, int y, t_fr *fr);
//int		red_button(t_fr *fr);
//int		zoom(int x, int y, t_fr *fr, double factor);
//int		add_depth(t_fr *fr);
//int		reset_my_fractal(t_fr *fr);
//void	remove_depth(t_fr *fr);
//void	print_coords(int x, int y, t_fr *fr);
//void	switch_to_bernstein(t_fr *fr);/
//void	switch_to_pink(t_fr *fr);

#endif