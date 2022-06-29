/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:59:47 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/19 17:24:16 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_printint(t_io *io, t_mod *mods)
{
	int	nbr;

	nbr = va_arg(io->ap, int);
	if (nbr == -2147483648)
	{
		mods->putminus = 1;
		ft_printnbr(io, mods, 2147483648);
		return ;
	}
	if (nbr < 0)
	{
		mods->putminus = 1;
		nbr = nbr * -1;
	}
	ft_printnbr(io, mods, (unsigned long int) nbr);
}
