#include "../mlx/mlx.h"
#include <stdio.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int key, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	key = 7;
	return (0);
}

int	main(void)
{
	t_vars	vars;
	int		i;

	i = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "practice minilibx");
	mlx_mouse_hook(vars.win, close, &vars);
	mlx_loop(vars.mlx);
}