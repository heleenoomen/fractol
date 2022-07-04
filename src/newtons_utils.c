#include "fractol.h"

t_cplx	cplx_mul(t_cplx x, t_cplx y)
{
	t_cplx	m;

	m.re = x.re * y.re - x.im * y.im;
	m.im = x.re * y.im + x.im * y.re;
	return (m);
}

/*
// divide x by y, from: https://www.cuemath.com/numbers/division-of-complex-numbers/
*/
t_cplx	cplx_div(t_cplx x, t_cplx y)
{
	t_cplx	m;

	m.re = ((x.re * y.re) + (x.im * y.im)) / ((y.re * y.re) + (y.im * y.im));
	m.im = ((x.im * y.re) - (x.re * y.im)) / ((y.re * y.re) + (y.im * y.im));
	return (m);
}

/*
// subtract y from x
*/
t_cplx	cplx_sub(t_cplx x, t_cplx y)
{
	t_cplx r;

	r.re = x.re - y.re;
	r.im = x.im - y.im;
	return (r);
}

/*
// find nearest root for newton
*/
bool	near_equal_cplx(t_cplx x, t_cplx y, double tolerance)
{
	if (pow(x.re - y.re, 2) < tolerance
		&& pow(x.im - y.im, 2) < tolerance)
		return (1);
	return (0);
}
/*
// multiply real number by complex number
*/
t_cplx	create_complex(double re, double im)
{
	t_cplx cplx_nbr;

	cplx_nbr.re = re;
	cplx_nbr.im = im;

	return(cplx_nbr);
}