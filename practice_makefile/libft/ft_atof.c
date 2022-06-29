#include"libft.h"

double	calc_double(const char *s, int decimals, bool sign)
{
	char 	*ptr;
	double	nbr;
	int		i;

	ptr = (char *) s;
	nbr = 0;
	while (ft_isspace(*ptr))
		ptr++;
	if (*ptr == '+' || *ptr == '-')
		ptr++;
	while (ft_isdigit(*ptr))
	{
		nbr = (nbr * 10) + *ptr - '0';
		ptr++;
	}
	if (*ptr == '.')
		ptr++;
	i = 1;
	while (ft_isdigit(*ptr) && i <= decimals)
	{
		nbr = nbr + ((*ptr - '0') * (1 / ((double)10 * (double)(i))));
		i++;
		ptr++;
	}
	return (sign * nbr);
}

double	ft_atof(const char *s)
{
	char	*ptr;
	bool	sign;
	int		decimals;
	int		digits;

	ptr = (char *) s;
	decimals = 0;
	digits = 0;
	sign = 1;
	while (ft_isspace(*ptr))
		ptr++;
	if (*ptr == '+')
		ptr++;
	else if (*ptr == '-')
	{
		sign = 1;
		ptr++;
	}
	while (ft_isdigit(*ptr))
	{
		ptr++;
		digits++;
	}
	if (*ptr == '.')
		ptr++;
	while (ft_isdigit(*ptr))
	{
		ptr++;
		decimals++;
	}
	if (digits + decimals > 15)
		return (0);
	return (calc_double(s, decimals, sign));
}