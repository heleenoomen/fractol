#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include "fr_userinfo.h"
# include "keys.h"
# include "colors.h"

/*
// fractal names
*/
# define M "Mandelbrot" 
# define J "Julia"
# define N "Newton"

/*
// default parameters for Julia
*/
# define J_RE_DEFAULT -0.79
# define J_IM_DEFAULT 0.15

/*
// color names
*/
# define BE "bernstein"
# define RA "rainbow"
# define PS "psychedelic"
# define LI "linear"

/*
// codes for coloring algorithms
*/
# define NATURAL 1
# define PINK 2
# define GREEN 3
# define RAINBOW 4
# define DEFAULT_COLORS 5

/*
// zoom modus
*/
# define ZOOM_INIT -1
# define ZOOM_IN 1
# define ZOOM_OUT 0
# define ZOOM 0.75

/*
// window size
*/
# define WINSIZE 500

/*
// precision for newton root approximation
*/
# define TOLERANCE 0.000001

/*
// window and image parameters
*/
typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_win;

/*
// zoom parameters
*/
typedef struct s_zoom
{
	double	re_min;
	double	re_max;
	double	im_min;
	double	im_max;
	double	scope;
	int		depth_max;
	double	depth_max_sqrt;
}			t_zoom;

/*
// fractol parameters
*/
typedef struct s_fr
{
	int		(*calc_fractal)(struct s_fr *fr, double x, double y);
	void	(*coloring)(struct s_fr *fr, double x, double y, int i);
	double	j_re;
	double	j_im;
	int		color_shift;
	bool	set_is_black;
	t_win	window;
	t_zoom	zoom;
}			t_fr;

/*
// struct for complex numbers, needed for Newton fractal
*/
typedef struct s_cplx
{
	double	re;
	double	im;
}			t_cplx;

/*
// make.c
*/
void	make_image(t_fr *fr);

/*
// parse.c
*/
void	parse_fr(t_fr *fr, int argc, char **argv);

/*
// init.c
*/
void	init(t_fr *fr);

/*
// fractals.c
*/
void	conv_to_complex_plain_coord(t_fr *fr, double *x, double *y);
int		calc_mandelbrot(t_fr *fr, double x, double y);
int		calc_julia(t_fr *fr, double x, double y);
int		calc_newton(t_fr *fr, double x, double y);

/*
// newtons_utils.c
*/
t_cplx	cplx_mul(t_cplx x, t_cplx y);
t_cplx	cplx_div(t_cplx x, t_cplx y);
t_cplx	cplx_sub(t_cplx x, t_cplx y);
bool	near_equal_cplx(t_cplx x, t_cplx y, double tolerance);
t_cplx	create_complex(double re, double im);

/*
// color.c
*/
void	my_mlx_pixel_put(t_fr *fr, int x, int y, int color);
void	shift_color(int depth, int shift, int *i);
void	bernstein(t_fr *fr, double c_re, double c_im, int i);
void	rainbow(t_fr *fr, double c_re, double c_im, int i);
void	psychedelic(t_fr *fr, double c_re, double c_im, int i);
void	linear(t_fr *fr, double c_re, double c_im, int i);

/*
// hsv2rgb.c
*/
int	hsv2rgb(double h, double s, double v);
int	spectrum(double i_normalized);

/*
// events.c
*/
int		keyboard(int keycode, t_fr *fr);
int		mouse(int button, int x, int y, t_fr *fr);
int		red_button(t_fr *fr);

/*
// event_handlers.c
*/
void	change_julias_parms(t_fr *fr, int keycode);
void	switch_to_julia(t_fr *fr, double x, double y);
void	switch_fractal(t_fr *fr, int keycode);

/*
// print_info.c
*/

void	print_fractal_info(t_fr *fr);
void	print_current_range(t_fr *fr);
void	print_coordinates(t_fr *fr, double x, double y);
void	print_julias_parms(t_fr *fr);
void	print_info(t_fr *fr, int keycode);

/*
// view.c
*/
void	move_view(t_fr *fr, int keycode);
void	zoom(int x, int y, t_fr *fr, double zoom);
void	reset_zoom(t_fr *fr);
void	add_depth(t_fr *fr);
void	remove_depth(t_fr *fr);

#endif