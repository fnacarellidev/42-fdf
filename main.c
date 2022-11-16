#include "./libs/mlx/mlx.h"
#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	if (vars->mlx)
		free(vars->mlx);
	exit(0);
}

int	ft_keyhook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_close(vars);
	return (0);
}

int main(void)
{
	t_vars		vars;
	t_data		img;
	t_pos		*pos0;
	t_pos		*pos1;

	pos0 = malloc(sizeof(t_pos));
	pos1 = malloc(sizeof(t_pos));
	pos0->x = 0;
	pos0->y = 0;
	pos1->x = 500;
	pos1->y = 500;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, HEIGHT, WIDTH, "fdf");
	img.img = mlx_new_image(vars.mlx, HEIGHT, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_plot_line(pos0, pos1, &img);
	mlx_key_hook(vars.win, ft_keyhook, &vars);
	mlx_hook(vars.win, 17, 1L<<0, &ft_close, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_destroy_image(vars.mlx, img.img);
	mlx_loop(vars.mlx);
}
