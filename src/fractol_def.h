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


# define USAGE "\n\tUsage: ./fractol <fractal name> <optional parameters>\n\n\
\tspecify at least one parameter:\n\
\t fractal name: <Mandelbrot/Julia/Newton/M/J/N>\n\n\
\tthe following optional parameters may be used:\n\
\t  color: <natural/pink/green/rainbow>\n\
\t  for Julia only: <real axis coordinate> <imaginary axis coordinate>\n"

# define USAGE_NAME "\n\tPlease provide valid fractal name: Mandelbrot/Julia/Newton/M/J/N\n"

# define USAGE_COLOR "\n\tPlease provide valid color parameter: natural/pink/green/rainbow\n\
\tIf no color parameter is provided, 'natural' coloring algorithm will be used\n"

# define USAGE_JULIA "\n\tJulia fractal: use either two or zero coordinate parameters:\n\n\
\t ./fractol Julia <color> <real_coordinate> <imaginary_coordinate>\n\
\t ./fractol Julia <real_coordinate> <imaginary_coordinate>\n\
\t ./fractol Julia\n\n\
\tif no coordinates are provided, default coordinates {-0.79, 0.15} will be used\n"

# define WARNING_JULIA "\n\tWarning: specified coordinates are outside {2, 2} - input will yield empty fractal\n"

# define J_RE_DEFAULT (double) -0.79
# define J_IM_DEFAULT (double) 0.15

# define NATURAL 1
# define PINK 2
# define GREEN 3
# define RAINBOW 4
# define DEFAULT_COLORS 5

# define NAT_LEN 8
# define PIN_LEN 5
# define GREEN_LEN 6
# define RAINB_LEN 8

# define MAN_LEN 11
# define JU_LEN 6
# define NWT_LEN 7

typedef struct s_p
{
	char	fractal;
	short	color;
	double	j_re;
	double	j_im;
}			t_p;


typedef struct s_fr
{
	t_p		parms;
}			t_fr;


//toto.c
void	parse_fr(t_p *parms, int argc, char **argv);

#endif