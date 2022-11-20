/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initwindow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:55:26 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/19 18:19:24 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

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

void	init_window_and_hooks(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fdf");
	mlx_key_hook(vars->win, &ft_keyhook, vars);
	mlx_hook(vars->win, 17, 1L<<0, &ft_close, vars);
	mlx_loop(vars->mlx);
}

void	init_image(t_data *img, t_vars *vars)
{
	img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, 
			&img->line_length, &img->endian);
}
