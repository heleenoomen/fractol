#include "fractol_def.h"

// void	usage_exit(char *message)
// {
// 	ft_printf("%s\n", USAGE);
// 	if (message != NULL)
// 		ft_printf("%s\n", message);
// 	exit (1);
// }

// void	parse_fractal(t_p *parms, char *s)
// {
// 	if (s[1] == '\0')
// 	{
// 		if (s[0] == 'M' || s[0] == 'm')
// 			parms->fractal = 'M';
// 		else if (s[0] == 'J' || s[0] == 'j')
// 			parms->fractal = 'J';
// 		else if (s[0] == 'N' || s[0] == 'n')
// 			parms->fractal = 'N';
// 	}
// 	else if (ft_strncmp_uplo(s, "Mandelbrot", MAN_LEN) == 0)
// 		parms->fractal = 'M';
// 	else if (ft_strncmp_uplo(s, "Julia", JU_LEN) == 0)
// 		parms->fractal = 'J';
// 	else if (ft_strncmp_uplo(s, "Newton", NWT_LEN) == 0)
// 		parms->fractal = 'N';
// 	else
// 		usage_exit("Please provide valid fractal name: Mandelbrot/Julia/Newton/M/J/N");
// }

// void	parse_color(t_p *parms, char *s)
// {
// 	if (s[1] != 0)
// 		parms->color = NATURAL;
// 	if (ft_strncmp_uplo(s, "natural", NAT_LEN) == 0)
// 		parms->color = NATURAL;
// 	else if (ft_strncmp_uplo(s, "pink", PIN_LEN) == 0)
// 		parms->color = PINK;
// 	else if (ft_strncmp_uplo(s, "green", GREEN_LEN == 0))
// 		parms->color = GREEN;
// 	else if (ft_strncmp_uplo(s, "rainbow", RAINB_LEN == 0))
// 		parms->color = RAINBOW;
// 	else
// 		usage_exit("Please provide valid color: natural/pink/green/rainbow\n\
// 		If no color is provided, 'natural' coloring algorithm will be used");

// }

// void	parse_julia(t_p *parms, int argc, char **argv)
// {
// 	if (parms->fractal != 'J')
// 		usage_exit("Coordinates can only be provided for Julia fractal");
// 	if (argc == 4)
// 		usage_exit("Please provide real and imaginary coordinates for Julia\
// 		if no coordinates are provided, default coordinates {-0.79, 0.15} will be used");
// 	parms->j_re = ft_atof(argv[4]);
// 	parms->j_im = ft_atof(argv[5]);
// 	if (parms->j_re > 2 || parms->j_im > 2)
// 		ft_printf("NB coordinates for Julia are outside {2, 2} - input will yield empty fractal");
// }

// void	parse(t_p *parms, int argc, char **argv)
// {
// 	if (argc == 1 || argc > 5)
// 		usage_exit(NULL);
// 	if (argc > 1)
// 		parse_fractal(parms, argv[1]);
// 	if (argc > 2)
// 		parse_color(parms, argv[2]);
// 	else
// 		parms->color = NATURAL;
// 	if (argc > 3 && argc < 6)
// 		parse_julia(parms, argc, argv);
// }

int	main(int argc, char **argv)
{
	t_fr	fr;
	
	parse_fr(&(fr.parms), argc, argv);
	return (0);
}
