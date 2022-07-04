#include"ft_printf.h"
#include<math.h>
#include<limits.h>
#include<stdio.h>


void	get_int_part_fract_part(double nbr, double *int_part, double *fract_part)
{
	if (nbr < 0)
	{
		*int_part = ceil(nbr);
		*fract_part = -1 * (nbr - *int_part);
	}
	else
	{
		*int_part = floor(nbr);
		*fract_part = nbr - *int_part;
	}
}

void	ft_printfloat(t_io *io, t_mod *mods)
{
	double	nbr;
	double	int_part;
	double	fract_part;

	nbr = va_arg(io->ap, double);
	//printf("%f\n", nbr);
	mods->base = 10;
	get_int_part_fract_part(nbr, &int_part, &fract_part);
	if (nbr < 0)
	{
		io->nprinted += write(1, "-", 1);
		int_part *= -1;
	}
	ft_putnbrpf(io, mods, (unsigned long) int_part);
	if (mods->precision > 0)
		io->nprinted += write(1, ".", 1);
	if (mods->precision == 0)
		mods->precision = 2;
	while (mods->precision)
	{
		fract_part *= 10;
		mods->precision--;
	}
	ft_putnbrpf(io, mods, (unsigned long) round(fract_part));
}