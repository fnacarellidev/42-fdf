/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:35:27 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/24 09:02:45 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	apply_to_each_point(t_win *win, int x_move, int y_move);

void	ft_move_left(t_win *win)
{
	init_image(win);
	apply_to_each_point(win, -8, 0);
	connect_both_axis(win->pos_ptr, win, *(win->map_ptr));
	put_img_to_window(win);
}

void	ft_move_down(t_win *win)
{
	init_image(win);
	apply_to_each_point(win, 0, 8);
	connect_both_axis(win->pos_ptr, win, *(win->map_ptr));
	put_img_to_window(win);
}

void	ft_move_up(t_win *win)
{
	init_image(win);
	apply_to_each_point(win, 0, -8);
	connect_both_axis(win->pos_ptr, win, *(win->map_ptr));
	put_img_to_window(win);
}

void	ft_move_right(t_win *win)
{
	init_image(win);
	apply_to_each_point(win, 8, 0);
	connect_both_axis(win->pos_ptr, win, *(win->map_ptr));
	put_img_to_window(win);
}

static void	apply_to_each_point(t_win *win, int x_move, int y_move)
{
	int	row;
	int	col;

	row = 0;
	while (row < win->map_ptr->rows)
	{
		col = 0;
		while (col < win->map_ptr->columns)
		{
			win->pos_ptr[row][col].x += x_move;
			win->pos_ptr[row][col].y += y_move;
			col++;
		}
		row++;
	}
}
