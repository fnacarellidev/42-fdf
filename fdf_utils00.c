/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:43:19 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/21 17:18:40 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	set_values(t_pos **pos, t_str *str, char *file, t_vars *vars, t_map map)
{
	int	col;
	int	row;
	int	fd;

	row = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_close(vars);
	while (1)
	{
		col = 0;
		str->gnl_ret = get_next_line(fd);
		if (str->gnl_ret == NULL)
			break ; // @TODO Not sure if this will work, have to worry about frees and stuff
		str->split_ret = ft_split(str->gnl_ret, ' ');
		pos[row] = malloc(sizeof(t_pos) * map.columns);
		while (col < map.columns)
		{
			pos[row][col].x = col;
			pos[row][col].y = row;
			pos[row][col].z = ft_atoi(str->split_ret[col]);
			col++;
		}
		free(str->gnl_ret);
		free_split(str->split_ret);
		row++;
	}
}

void	multiply_matrix(t_pos **pos, t_map map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map.rows)
	{
		col = 0;
		while (col < map.columns)
		{
			pos[row][col].x *= 10;
			pos[row][col].y *= 10;
			pos[row][col].z *= 10;
			col++;
		}
		row++;
	}
}

void	free_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}
