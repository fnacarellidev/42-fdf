/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:43:19 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/23 20:35:21 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	set_values(t_pos **pos, t_str *str, char *argv, t_map map)
{
	int	fd;
	int	col;
	int	row;

	row = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(1);
	while (1)
	{
		col = 0;
		str->gnl_ret = get_next_line(fd);
		if (str->gnl_ret == NULL)
			break ;
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
		free_matrix((void **)str->split_ret);
		row++;
	}
	close(fd);
}

void	multiply_matrix(t_pos **pos, t_map map)
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
			pos[row][col].x *= val / 1;
			pos[row][col].y *= val / 1;
			pos[row][col].z *= val / 2;
			col++;
		}
		row++;
	}
}

void	free_matrix(void **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
