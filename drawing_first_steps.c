/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_first_steps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:14:35 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/24 08:53:06 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	init_mlx(t_win *win);
void		put_img_to_window(t_win *win);
static void	save_meaningful_addresses(t_win *win, t_pos **pos, t_map *map);
static void	draw(t_win *win, t_pos **pos, t_map map);

void	initialize_stuff(char *argv)
{
	int			fd;
	t_win		win;
	t_map		*map;
	t_pos		**pos;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(1);
	map = malloc(sizeof(t_map));
	set_rows_and_columns(argv, map);
	pos = ft_calloc(sizeof(t_pos), map->rows);
	set_values(pos, fd, *map);
	save_meaningful_addresses(&win, pos, map);
	init_mlx(&win);
	draw(&win, pos, *map);
	put_img_to_window(&win);
	init_loop_and_hooks(&win);
}

static void	draw(t_win *win, t_pos **pos, t_map map)
{
	multiply_matrix(pos, map);
	transform_positions(pos, map);
	connect_both_axis(pos, win, map);
}

static void	save_meaningful_addresses(t_win *win, t_pos **pos, t_map *map)
{
	win->pos_ptr = pos;
	win->map_ptr = map;
}

void	put_img_to_window(t_win *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	mlx_destroy_image(win->mlx, win->img);
}

static void	init_mlx(t_win *win)
{
	init_window(win);
	init_image(win);
}
