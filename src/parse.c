#include "fractol_def.h"

void	usage_exit(char *message)
{
	if (message == NULL)
		ft_printf("%s\n", USAGE);
	else
		ft_printf("%s\n", message);
	exit (1);
}

void	parse_fractal(t_fr *fr, char *s)
{
	if (s[1] == '\0')
	{
		if (s[0] == 'M' || s[0] == 'm')
			fr->calc_fractal = &calc_mandelbrot;
		else if (s[0] == 'J' || s[0] == 'j')
			fr->calc_fractal = &calc_julia;
		else if (s[0] == 'N' || s[0] == 'n')
			fr->calc_fractal = &calc_newton;
		else
			usage_exit(USAGE_NAME);
	}
	else if (ft_strncmp_uplo(s, M, ft_strlen(M) + 1) == 0)
		fr->calc_fractal = &calc_mandelbrot;
	else if (ft_strncmp_uplo(s, J, ft_strlen(J) + 1) == 0)
		fr->calc_fractal = &calc_julia;
	else if (ft_strncmp_uplo(s, N, ft_strlen(N) + 1) == 0)
		fr->calc_fractal = &calc_newton;
	else
		usage_exit(USAGE_NAME);
}

void	parse_color(t_fr *fr, char *s)
{
	if (ft_strncmp_uplo(s, NA, ft_strlen(NA) + 1) == 0)
		fr->color = &natural;
	else if (ft_strncmp_uplo(s, PI, ft_strlen(PI) + 1) == 0)
		fr->color = &pink;
	else if (ft_strncmp_uplo(s, GR, ft_strlen(GR) + 1) == 0)
		fr->color = &psychedelic;
	else if (ft_strncmp_uplo(s, RA, ft_strlen(RA) + 1) == 0)
		fr->color = &rainbow;
	else if (fr->calc_fractal == &calc_julia)
		fr->color = NULL;
	else
		usage_exit(USAGE_COLOR);
}

void	parse_julia(t_fr *fr, int argc, char **argv)
{
	if (fr->color == NULL && argc > 2)
	{
		if (argc == 3)
			usage_exit(USAGE_JULIA);
		if (argc == 5)
			usage_exit(NULL);
		fr->j_re = ft_atof(argv[2]);
		fr->j_im = ft_atof(argv[3]);
		fr->color = &natural;
	}
	else if (argc > 3)
	{
		if (argc == 4)
			usage_exit(USAGE_JULIA);
		fr->j_re = ft_atof(argv[3]);
		fr->j_im = ft_atof(argv[4]);
	}
	else
	{
		fr->j_re = J_RE_DEFAULT;
		fr->j_im = J_IM_DEFAULT;
	}
	if (fr->j_re > 2 || fr->j_im > 2)
		ft_printf("%s\n", WARNING_JULIA);
}

void	parse_fr(t_fr *fr, int argc, char **argv)
{
	if (argc == 1 || argc > 5)
		usage_exit(NULL);
	parse_fractal(fr, argv[1]);
	if (fr->calc_fractal == &calc_newton)
		fr->coloring = &color_newton;
	else
		fr->coloring = &color_pixel;
	if (argc > 3 && fr->calc_fractal != &calc_julia)
		usage_exit(NULL);
	if (argc > 2)
		parse_color(fr, argv[2]);
	else
		fr->color = &natural;
	if (fr->calc_fractal == &calc_julia)
		parse_julia(fr, argc, argv);
	ft_printf("parse_fr, address of calc_fractal = %p\n", fr->calc_fractal);
}

