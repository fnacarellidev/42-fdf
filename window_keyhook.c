/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_keyhook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:55:26 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/24 09:15:09 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	ft_close(t_win *win)
{
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->map_ptr);
	free_matrix((void **)win->pos_ptr);
	if (win->mlx)
		free(win->mlx);
	exit(0);
}

int	ft_keyhook(int keycode, t_win *win)
{
	if (keycode == ESC_KEYCODE)
		ft_close(win);
	else if (keycode == H_KEYCODE)
		ft_move_left(win);
	else if (keycode == J_KEYCODE)
		ft_move_down(win);
	else if (keycode == K_KEYCODE)
		ft_move_up(win);
	else if (keycode == L_KEYCODE)
		ft_move_right(win);
	else if (keycode == PLUS_KEYCODE)
		zoom_in(win);
	else if (keycode == MINUS_KEYCODE)
		zoom_out(win);

	return (0);
}

void	init_window(t_win *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "fdf");
}

void	init_loop_and_hooks(t_win *win)
{
	mlx_key_hook(win->win, &ft_keyhook, win);
	mlx_hook(win->win, 17, 1L << 0, &ft_close, win);
	mlx_loop(win->mlx);
}

void	init_image(t_win *win)
{
	win->img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	win->addr = mlx_get_data_addr(win->img, &win->bits_per_pixel,
			&win->line_length, &win->endian);
}
