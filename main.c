/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:05:51 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/24 00:21:16 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	int			fd;
	t_data		img;
	t_vars		vars;
	t_str		*str;
	t_map		*map;
	t_pos		**pos;

	fd = open(argv[1], O_RDONLY);
	validate_input(argc, argv[1]);
	str = malloc(sizeof(t_str));
	map = malloc(sizeof(t_map));
	set_rows_and_columns(argv[1], map);
	pos = ft_calloc(sizeof(t_pos), map->rows);
	set_values(pos, str, fd, *map);
	init_window(&vars);
	init_image(&img, &vars);
	multiply_matrix(pos, *map);
	transform_positions(pos, *map);
	connect_both_axis(pos, &img, *map);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_destroy_image(vars.mlx, img.img);
	free_matrix((void **)pos);
	free(map);
	free(str);
	init_loop_and_hooks(&vars);
}
