#include "fractol_def.h"
/*
// multiply complex number, inspired by fractol project -> libs -> libft -> math by cquillet
*/
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
// find nearest root for newton
*/
void	make_roots(t_cplx *roots1, t_cplx *roots2, t_cplx *roots3)
{
	roots1->re = 1;
	roots1->im = 0;
	roots2->re = -.5;
	roots2->im = sqrt(3) / 2;
	roots3->re = -.5;
	roots3->im = -1 * roots2->im;
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