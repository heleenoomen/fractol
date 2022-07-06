/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:04:47 by hoomen            #+#    #+#             */
/*   Updated: 2022/07/06 17:51:23 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_size_t(size_t nbr)
{
	char	c;

	if (nbr < 10)
	{
		c = nbr + '0';
		write(1, &c, 1);
		return ;
	}
	print_size_t(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}

void	print_zoom(t_fr *fr)
{
	double	zoom;

	zoom = 4 / fr->view.scope;
	ft_printf("\n\tZoom: ");
	if (zoom > 10)
		print_size_t((size_t) round(zoom));
	else
		ft_printf("%.4f", zoom);
	ft_printf("\n");
}
