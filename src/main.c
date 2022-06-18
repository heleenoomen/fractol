#include "../mlx/mlx.h"
#include "stdio.h"
#include "math.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// int	main(void)
// {
// 	int	t;
// 	int	r;
// 	int	g;
// 	int	b;
// 	int	trgb;

// 	t = 180;
// 	r = 255;
// 	g = 0;
// 	b = 0;

// 	trgb = create_trgb(t, r, g, b);
// 	printf("%x\n", trgb);

// }

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	//int		x;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	i = 20;
	while (i < 40)
	{
		my_mlx_pixel_put(&img, 20, i, 0x00FF0000);
		my_mlx_pixel_put(&img, 60, i, 0x00EE0000);
		i++;
	}	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
