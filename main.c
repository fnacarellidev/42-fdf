#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int main(int argc, char **argv)
{
	t_vars		vars;
	t_data		img;
	t_str		*str;
	t_pos		**pos;
	t_map		*map;

	if (argc != 2)
		exit(0);
	validate_input(argv[1]);
	str = malloc(sizeof(t_str));
	map = malloc(sizeof(t_map));
	set_rows(argv[1], map);
	set_columns(argv[1], map);
	pos = malloc(sizeof(t_pos) * map->rows);
	set_values(pos, str, argv[1], &vars, *map);
	init_window_and_hooks(&vars);
	init_image(&img, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_destroy_image(vars.mlx, img.img);
	mlx_loop(vars.mlx);
}
