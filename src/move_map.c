/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:35:27 by fnacarel          #+#    #+#             */
/*   Updated: 2022/12/01 18:57:31 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

static void	apply_to_each_point(t_win *win, int x_move, int y_move);

void	ft_move_img(int keycode, t_win *win)
{
	init_image(win);
	if (keycode == H_KEYCODE)
		apply_to_each_point(win, -8, 0);
	else if (keycode == J_KEYCODE)
		apply_to_each_point(win, 0, 8);
	else if (keycode == K_KEYCODE)
		apply_to_each_point(win, 0, -8);
	else if (keycode == L_KEYCODE)
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
