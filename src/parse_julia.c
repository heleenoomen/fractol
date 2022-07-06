/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:37:38 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/06 12:38:06 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_julias_parms(t_fr *fr, char *p1, char *p2)
{
	if (!ft_strisfloat(p1) || !ft_strisfloat(p2))
		usage_exit(USAGE_JULIA);
	fr->j_re = ft_atof(p1);
	fr->j_im = ft_atof(p2);
}

void	parse_julia(t_fr *fr, int argc, char **argv)
{
	if (fr->coloring == NULL && argc > 2)
	{
		if (argc == 3)
			usage_exit(USAGE_JULIA);
		if (argc == 5)
			usage_exit(NULL);
		get_julias_parms(fr, argv[2], argv[3]);
		fr->coloring = &bernstein;
		return ;
	}
	else if (argc > 3)
	{
		if (argc == 4)
			usage_exit(USAGE_JULIA);
		get_julias_parms(fr, argv[3], argv[4]);
		return ;
	}
	fr->j_re = J_RE_DEFAULT;
	fr->j_im = J_IM_DEFAULT;
}
