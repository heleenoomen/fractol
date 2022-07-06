/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtons_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:42:27 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/06 19:56:09 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
// for Newton fractal: manipulate iteration number for better coloring
*/
int	adjust_for_coloring(t_fr *fr, int i)
{
	double	j;

	j = sqrt(i);
	while ((i * j) > fr->depth_max)
	{
		i = (i - fr->view.depth_max_sqrt) / j;
		j = sqrt(i);
	}
	return ((int) round(i * j));
}

/*
// for Newton fractal: returns true if z is close enough to one of the three 
// solutions for x^3 - 1 = 0
*/
bool	approximates_root(t_cplx z)
{
	t_cplx	roots[3];
	int		i;

	roots[0] = create_complex(1, 0);
	roots[1] = create_complex(-0.5, sqrt(3) / 2);
	roots[2] = create_complex(-0.5, -1 * roots[1].im);
	i = 0;
	while (i < 3)
	{
		if (near_equal_cplx(z, roots[i], TOLERANCE))
			return (true);
		i++;
	}
	return (false);
}
