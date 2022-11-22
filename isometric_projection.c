/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:48:28 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/21 20:53:52 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static int	solve_for_x_axis(t_pos pos);
static int	solve_for_y_axis(t_pos pos);

void	transform_positions(t_pos **pos, t_map map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map.rows)
	{
		col = 0;
		while (col < map.columns)
		{
			pos[row][col].x = solve_for_x_axis(pos[row][col]);
			pos[row][col].y = solve_for_y_axis(pos[row][col]);
			col++;
		}
		row++;
	}
}

static int	solve_for_x_axis(t_pos pos)
{
	int		ret;
	double	cos_theta;
	double	sin_theta;

	cos_theta = cos(THETA);
	sin_theta = sin(THETA);
	ret = (int)(cos_theta * pos.x) + (-sin_theta * pos.z);
	return (abs(ret));
}

static int	solve_for_y_axis(t_pos pos)
{
	int		res;
	double	sin_alpha;
	double	sin_theta;
	double	cos_alpha;
	double	cos_theta;

	sin_alpha = sin(asin(tan(ALPHA)));
	sin_theta = sin(THETA);
	cos_alpha = cos(asin(tan(ALPHA)));
	cos_theta = cos(THETA);
	res = (int)(sin_alpha * sin_theta * pos.x) + (cos_alpha * pos.y)
		+ (sin_alpha * cos_theta * pos.z);
	return (abs(res));
}
