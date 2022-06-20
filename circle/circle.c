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

# define X 0
# define Y 1

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	float	m[2];
	float	r;
	float	c[2];

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	m[X] = 800;
	m[Y] = 800;
	r = 50;
	while (r < 55)
	{
		m[X] = 800;
		m[Y] = 800;
		c[Y] = m[Y] - r;
		while (c[Y] <= (m[Y] + r))
		{
			c[X] = m[X] - r;
			while (c[X] <= (m[X] + r))
			{
			// printf("c[X]^2 + c[Y]^2 = %i\n", (int) (powf(c[X] - m[X], 2) + powf(c[Y] - m[Y], 2)));
			// printf("r^2 = %i\n", (int) (powf(r, 2)));
				if (//(powf(c[X] - m[X], 2) + powf(c[Y] - m[Y], 2)) >= (powf(r, 2) - 60)
					(powf(c[X] - m[X], 2) + powf(c[Y] - m[Y], 2)) <= (powf(r, 2)) + 60)
			 		my_mlx_pixel_put(&img, c[X], c[Y], 0xA0EEFF00);
				c[X]++;
			}
			c[Y]++;
		}
		r++;
	}
	r = 100;
	while (r < 103)
	{
		m[X] = 400;
		m[Y] = 400;
		c[Y] = m[Y] - r;
		while (c[Y] <= (m[Y] + r))
		{
			c[X] = m[X] - r;
			while (c[X] <= (m[X] + r))
			{
			// printf("c[X]^2 + c[Y]^2 = %i\n", (int) (powf(c[X] - m[X], 2) + powf(c[Y] - m[Y], 2)));
			// printf("r^2 = %i\n", (int) (powf(r, 2)));
				if ((powf(c[X] - m[X], 2) + powf(c[Y] - m[Y], 2)) >= (powf(r, 2) - 100)
					&& (powf(c[X] - m[X], 2) + powf(c[Y] - m[Y], 2)) <= (powf(r, 2) + 100))
			 		my_mlx_pixel_put(&img, c[X], c[Y], 0x0000FF00);
				c[X]++;
			}
			c[Y]++;
		}
		r++;
	}
	r = 80;
	while (r < 83)
	{
		m[X] = 1200;
		m[Y] = 500;
		c[Y] = m[Y] - r;
		while (c[Y] <= (m[Y] + r))
		{
			c[X] = m[X] - r;
			while (c[X] <= (m[X] + r))
			{
			// printf("c[X]^2 + c[Y]^2 = %i\n", (int) (powf(c[X] - m[X], 2) + powf(c[Y] - m[Y], 2)));
			// printf("r^2 = %i\n", (int) (powf(r, 2)));
				if ((powf(c[X] - m[X], 2) + powf(c[Y] - m[Y], 2)) >= (powf(r, 2) - 80)
					&& (powf(c[X] - m[X], 2) + powf(c[Y] - m[Y], 2)) <= (powf(r, 2) + 80))
			 		my_mlx_pixel_put(&img, c[X], c[Y], 0x00EEAA00);
				c[X]++;
			}
			c[Y]++;
		}
		r++;
	}
	r = 90;
	while (r < 92)
	{
		m[X] = 1600;
		m[Y] = 100;
		c[Y] = m[Y] - r;
		while (c[Y] <= (m[Y] + r))
		{
			c[X] = m[X] - r;
			while (c[X] <= (m[X] + r))
			{
			// printf("c[X]^2 + c[Y]^2 = %i\n", (int) (powf(c[X] - m[X], 2) + powf(c[Y] - m[Y], 2)));
			// printf("r^2 = %i\n", (int) (powf(r, 2)));
				if ((powf(c[X] - m[X], 2) + powf(c[Y] - m[Y], 2)) >= (powf(r, 2) - 90)
					&& (powf(c[X] - m[X], 2) + powf(c[Y] - m[Y], 2)) <= (powf(r, 2) + 90))
			 		my_mlx_pixel_put(&img, c[X], c[Y], 0x00BB00CC);
				c[X]++;
			}
			c[Y]++;
		}
		r++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx); 
}
