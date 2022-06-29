#include "fractol_def.h"

void	usage_exit(char *message)
{
	if (message == NULL)
		ft_printf("%s\n", USAGE);
	else
		ft_printf("%s\n", message);
	exit (1);
}

void	parse_fractal(t_p *parms, char *s)
{
	if (s[1] == '\0')
	{
		if (s[0] == 'M' || s[0] == 'm')
			parms->fractal = 'M';
		else if (s[0] == 'J' || s[0] == 'j')
			parms->fractal = 'J';
		else if (s[0] == 'N' || s[0] == 'n')
			parms->fractal = 'N';
		else
			usage_exit(USAGE_NAME);
	}
	else if (ft_strncmp_uplo(s, M, ft_strlen(M) + 1) == 0)
		parms->fractal = 'M';
	else if (ft_strncmp_uplo(s, J, ft_strlen(J) + 1) == 0)
		parms->fractal = 'J';
	else if (ft_strncmp_uplo(s, N, ft_strlen(N) + 1) == 0)
		parms->fractal = 'N';
	else
		usage_exit(USAGE_NAME);
}

void	parse_color(t_p *parms, char *s)
{
	if (ft_strncmp_uplo(s, NA, ft_strlen(NA) + 1) == 0)
		parms->color = NATURAL;
	else if (ft_strncmp_uplo(s, PI, ft_strlen(PI) + 1) == 0)
		parms->color = PINK;
	else if (ft_strncmp_uplo(s, GR, ft_strlen(GR) + 1) == 0)
		parms->color = GREEN;
	else if (ft_strncmp_uplo(s, RA, ft_strlen(RA) + 1) == 0)
		parms->color = RAINBOW;
	else if (parms->fractal == 'J')
		parms->color = DEFAULT_COLORS;
	else
		usage_exit(USAGE_COLOR);
}

void	parse_julia(t_p *parms, int argc, char **argv)
{
	if (parms->color == DEFAULT_COLORS && argc > 2)
	{
		if (argc == 3)
			usage_exit(USAGE_JULIA);
		if (argc == 5)
			usage_exit(NULL);
		parms->j_re = ft_atof(argv[2]);
		parms->j_im = ft_atof(argv[3]);
	}
	else if (argc > 3)
	{
		if (argc == 4)
			usage_exit(USAGE_JULIA);
		parms->j_re = ft_atof(argv[3]);
		parms->j_im = ft_atof(argv[4]);
	}
	else
	{
		parms->j_re = J_RE_DEFAULT;
		parms->j_im = J_IM_DEFAULT;
	}
	if (parms->j_re > 2 || parms->j_im > 2)
		ft_printf("%s\n", WARNING_JULIA);
}

void	parse_fr(t_p *parms, int argc, char **argv)
{
	if (argc == 1 || argc > 5)
		usage_exit(NULL);
	parse_fractal(parms, argv[1]);
	if (argc > 3 && parms->fractal != 'J')
		usage_exit(NULL);
	if (argc > 2)
		parse_color(parms, argv[2]);
	else
		parms->color = DEFAULT_COLORS;
	if (parms->fractal == 'J')
		parse_julia(parms, argc, argv);
}

