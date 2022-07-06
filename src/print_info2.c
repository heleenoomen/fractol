/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:04:47 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/06 15:16:42 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_zoom(t_fr *fr)
{
	double	zoom;

	zoom = 4 / fr->view.scope;
	if (zoom > 10)
		ft_printf("\n\tZoom: %i\n", (int) round(zoom));
	else if (zoom > 5)
		ft_printf("\n\tZoom: %.1f\n", zoom);
	else if (zoom > 1)
		ft_printf("\n\tZoom: %.3f\n", zoom);
	else
		ft_printf("\n\tZoom: %f\n", zoom);
}

