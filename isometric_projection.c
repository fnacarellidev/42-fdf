/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:48:28 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/22 21:51:11 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static int	solve_for_x_axis(t_pos pos);
static int	solve_for_z_axis(t_pos pos);

void	transform_positions(t_pos **pos, t_map map)
{
	int	row;
	int	col;
	int	val;

	row = 0;
	val = HEIGHT / sqrt(pow(map.columns, 2) + pow(map.rows, 2));
	while (row < map.rows)
	{
		col = 0;
		while (col < map.columns)
		{
			pos[row][col].x = solve_for_z_axis(pos[row][col]);
			pos[row][col].y = solve_for_x_axis(pos[row][col]);
			pos[row][col].y += HEIGHT / 2 - (map.rows / 2 * val);
			pos[row][col].x += WIDTH / 2 - (map.columns / 5 * val);
			col++;
		}
		row++;
	}
}

static int	solve_for_z_axis(t_pos pos)
{
	int		ret;
	double	cos_alpha;
	double	sin_theta;
	double	sin_alpha;
	double	cos_theta;

	cos_theta = cos(M_PI / 4);
	sin_theta = sin(M_PI / 4);
	cos_alpha = cos(asin(tan(M_PI / 6)));
	sin_alpha = sin(asin(tan(M_PI / 6)));
	ret = (int)(cos_alpha * sin_theta * pos.x) - (sin_alpha * pos.y)
		- (cos_alpha * cos_theta * pos.z);
	return (ret);
}

static int	solve_for_x_axis(t_pos pos)
{
	int		res;
	double	sin_alpha;
	double	sin_theta;
	double	cos_alpha;
	double	cos_theta;

	sin_alpha = sin(asin(tan(M_PI / 6)));
	sin_theta = sin(M_PI / 4);
	cos_alpha = cos(asin(tan(M_PI / 6)));
	cos_theta = cos(M_PI / 4);
	res = (int)(sin_alpha * sin_theta * pos.x) + (cos_theta * pos.y)
		- (sin_alpha * cos_theta * pos.z);
	return (res);
}
