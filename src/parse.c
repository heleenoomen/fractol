#include "fractol.h"

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
	if (s[1] == '\0')
	{
		if (s[0] == 'B' || s[0] == 'b')
			fr->coloring = &bernstein;
		else if (s[0] == 'R' || s[0] == 'r')
			fr->coloring = &rainbow;
		else if (s[0] == 'P' || s[0] == 'p')
			fr->coloring= &psychedelic;
		else
			usage_exit(USAGE_NAME);
	}
	else if (ft_strncmp_uplo(s, "be", 3) == 0
		|| ft_strncmp_uplo(s, BE, ft_strlen(BE) + 1) == 0)
		fr->coloring = &bernstein;
	else if (ft_strncmp_uplo(s, "ra", 3) == 0
		|| ft_strncmp_uplo(s, RA, ft_strlen(RA) + 1) == 0)
		fr->coloring = &rainbow;
	else if (ft_strncmp_uplo(s, "ps", 3) == 0
		|| ft_strncmp_uplo(s, PS, ft_strlen(PS) + 1) == 0)
		fr->coloring = &psychedelic;
	else if (fr->calc_fractal == &calc_julia)
		fr->coloring = NULL;
	else
		usage_exit(USAGE_COLOR);
}

void	parse_julia(t_fr *fr, int argc, char **argv)
{
	if (fr->coloring == NULL && argc > 2)
	{
		if (argc == 3)
			usage_exit(USAGE_JULIA);
		if (argc == 5)
			usage_exit(NULL);
		fr->j_re = ft_atof(argv[2]);
		fr->j_im = ft_atof(argv[3]);
		fr->coloring = &bernstein;
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
	if (argc > 3 && fr->calc_fractal != &calc_julia)
		usage_exit(NULL);
	if (argc > 2)
		parse_color(fr, argv[2]);
	else
		fr->coloring = &bernstein;
	if (fr->calc_fractal == &calc_julia)
		parse_julia(fr, argc, argv);
}

