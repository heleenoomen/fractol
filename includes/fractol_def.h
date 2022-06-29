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

/*
// constants
*/
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

/*
// structs
*/
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
	t_mlx	mlx;
}			t_fr;


/*
// parse.c
*/
void	parse_fr(t_p *parms, int argc, char **argv);

#endif