#ifndef FRACTOL_DEF_H
# define FRACTOL_DEF_H

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
# define NA "natural"
# define PI "pink"
# define GR "green"
# define RA "rainbow"

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
// parameters given by the user
*/
typedef struct s_p
{
	char	fractal;
	short	color;
	double	j_re;
	double	j_im;
}			t_p;

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
}			t_zoom;

/*
// fractol parameters
*/
typedef struct s_fr
{
	t_p		parms;
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
void	parse_fr(t_p *parms, int argc, char **argv);

/*
// init.c
*/
void	init(t_win *window, t_zoom *zoom);

/*
// fractals.c
*/
int		calc_mandelbrot(t_fr *fr, double x, double y);
int		calc_julia(t_fr *fr, double x, double y);
int		calc_newton(t_fr *fr, double x, double y);

/*
// color.c
*/
void	color_pixel(t_fr *fr, double c_re, double c_im, int i);
void	my_mlx_pixel_put(t_fr *fr, int x, int y, int color);

/*
// events.c
*/
int		keyboard(int keycode, t_fr *fr);
int		mouse(int button, int x, int y, t_fr *fr);
int		red_button(t_fr *fr);

/*
// zoom.c
*/
void	zoom(int x, int y, t_fr *fr, double zoom);



// t_cplx	create_complex(double re, double im);
// t_cplx	cplx_conj(t_cplx z);
// double	cplx_mod(t_cplx z);
// t_cplx	cplx_scalar(t_cplx z, double a);
// t_cplx	cplx_inv(t_cplx z);
// t_cplx	cplx_add(t_cplx x, t_cplx y);
// t_cplx	cplx_sub(t_cplx x, t_cplx y);
// t_cplx	cplx_mul(t_cplx x, t_cplx y);
// t_cplx	cplx_pow(t_cplx x, int exp);
// t_cplx	cplx_div(t_cplx x, t_cplx y);

#endif