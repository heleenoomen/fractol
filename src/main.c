#include "fractol_def.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_fr	fr;
	
	parse_fr(&(fr.parms), argc, argv);
	init(&(fr.window), &(fr.zoom));
	mlx_loop(fr.window.mlx);
	return (0);
}
