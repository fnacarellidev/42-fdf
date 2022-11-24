/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:03:10 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/24 09:31:45 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	divide_for_each_coordinate(t_pos **pos, t_map map);
static void	multiply_for_each_coordinate(t_pos **pos, t_map map);

void	zoom_in(t_win *win)
{
	init_image(win);
	multiply_for_each_coordinate(win->pos_ptr, *(win->map_ptr));
	connect_both_axis(win->pos_ptr, win, *(win->map_ptr));
	put_img_to_window(win);
}

void	zoom_out(t_win *win)
{
	init_image(win);
	divide_for_each_coordinate(win->pos_ptr, *(win->map_ptr));
	connect_both_axis(win->pos_ptr, win, *(win->map_ptr));
	put_img_to_window(win);
}

static void	multiply_for_each_coordinate(t_pos **pos, t_map map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map.rows)
	{
		col = 0;
		while (col < map.columns)
		{
			pos[row][col].x *= 2;
			pos[row][col].y *= 2;
			col++;
		}
		row++;
	}
}

static void	divide_for_each_coordinate(t_pos **pos, t_map map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map.rows)
	{
		col = 0;
		while (col < map.columns)
		{
			pos[row][col].x /= 2;
			pos[row][col].y /= 2;
			col++;
		}
		row++;
	}
}
