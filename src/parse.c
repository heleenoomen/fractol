/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:07:44 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/06 12:38:20 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (ft_strncmp_uplo(s, "M", 2) == 0
		|| ft_strncmp_uplo(s, M, ft_strlen(M) + 1) == 0)
		fr->calc_fractal = &calc_mandelbrot;
	else if (ft_strncmp_uplo(s, "J", 2) == 0
		|| ft_strncmp_uplo(s, J, ft_strlen(J) + 1) == 0)
		fr->calc_fractal = &calc_julia;
	else if (ft_strncmp_uplo(s, "N", 2) == 0
		|| ft_strncmp_uplo(s, N, ft_strlen(N) + 1) == 0)
		fr->calc_fractal = &calc_newton;
	else
		usage_exit(USAGE_NAME);
}

void	parse_color(t_fr *fr, char *s)
{
	if (ft_strncmp_uplo(s, "b", 2) == 0
		|| ft_strncmp_uplo(s, "be", 3) == 0
		|| ft_strncmp_uplo(s, BE, ft_strlen(BE) + 1) == 0)
		fr->coloring = &bernstein;
	else if (ft_strncmp_uplo(s, "r", 2) == 0
		|| ft_strncmp_uplo(s, "ra", 3) == 0
		|| ft_strncmp_uplo(s, RA, ft_strlen(RA) + 1) == 0)
		fr->coloring = &rainbow;
	else if (ft_strncmp_uplo(s, "p", 2) == 0
		|| ft_strncmp_uplo(s, "ps", 3) == 0
		|| ft_strncmp_uplo(s, PS, ft_strlen(PS) + 1) == 0)
		fr->coloring = &psychedelic;
	else if (fr->calc_fractal == &calc_julia)
		fr->coloring = NULL;
	else
		usage_exit(USAGE_COLOR);
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
