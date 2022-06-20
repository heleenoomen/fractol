#include "../mlx/mlx.h"
#include "stdio.h"
#include "math.h"
#include "fractol.h"

typedef struct	s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_fr *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->img_addr + (y * fr->line_length + x * (fr->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	t_data	q;
	int		i;
	t_fr	fr;

	fr.win_width = 500;
	fr.win_height = 500;
	fr.mlx = mlx_init();
	fr.win = mlx_new_window(fr.mlx, fr.win_width, fr.win_height, "Hello world!");
	fr.img = mlx_new_image(fr.mlx, 500, 500);
	fr.img_addr = mlx_get_data_addr(fr.img, &fr.bits_per_pixel, &fr.line_length, &fr.endian);
	i = 20;
	while (i < 40)
	{
		my_mlx_pixel_put(&fr, 20, i, 0x00FF0000);
		my_mlx_pixel_put(&fr, 60, i, 0x00EE0000);
		i++;
	}	
	mlx_put_image_to_window(fr.mlx, fr.win, fr.img, 0, 0);
	mlx_loop(fr.mlx);
}
