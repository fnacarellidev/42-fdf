/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_axis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:51:15 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/23 20:26:39 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	connect_vertical_axis(t_pos **pos, t_data *img, t_map map);
static void	connect_horizontal_axis(t_pos **pos, t_data *img, t_map map);

void	connect_both_axis(t_pos **pos, t_data *img, t_map map)
{
	connect_vertical_axis(pos, img, map);
	connect_horizontal_axis(pos, img, map);
}

static void	connect_vertical_axis(t_pos **pos, t_data *img, t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.columns)
	{
		j = 0;
		while (j < map.rows - 1)
		{
			ft_plot_line(&pos[j][i], &pos[j + 1][i], img);
			j++;
		}
		i++;
	}
}

static void	connect_horizontal_axis(t_pos **pos, t_data *img, t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.rows)
	{
		j = 0;
		while (j < map.columns - 1)
		{
			ft_plot_line(&pos[i][j], &pos[i][j + 1], img);
			j++;
		}
		i++;
	}
}
