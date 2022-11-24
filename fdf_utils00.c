/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:43:19 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/24 08:20:51 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static char	**read_entire_archive(int fd, int rows);
static void	put_values_into_matrix(t_pos *pos, int row, int col, char **str);
int			ft_atoi_hex(const char *str);

void	set_values(t_pos **pos, int fd, t_map map)
{
	int		col;
	int		row;
	char	**split_ret;
	char	**archive;

	row = 0;
	archive = read_entire_archive(fd, map.rows);
	while (row < map.rows)
	{
		col = 0;
		split_ret = ft_split(archive[row], ' ');
		pos[row] = malloc(sizeof(t_pos) * map.columns);
		while (col < map.columns)
		{
			put_values_into_matrix(&pos[row][col], row, col, split_ret);
			col++;
		}
		free_matrix((void **)split_ret);
		row++;
	}
	free_matrix((void **)archive);
	close(fd);
}

static void	put_values_into_matrix(t_pos *pos, int row, int col, char **str)
{
	char	*str_comma;

	str_comma = ft_strchr(str[col], ',');
	pos->x = col;
	pos->y = row;
	pos->z = ft_atoi(str[col]);
	if (str_comma)
	{
		str_comma++;
		pos->color = ft_hex_str_toi(str_comma);
	}
	else
		pos->color = COLOR;
}

static char	**read_entire_archive(int fd, int rows)
{
	int		i;
	char	*gnl_ret;
	char	**entire_archive;

	i = 0;
	entire_archive = ft_calloc(sizeof(char *), rows + 1);
	while (1)
	{
		gnl_ret = get_next_line(fd);
		if (gnl_ret == NULL)
			break ;
		entire_archive[i] = ft_strdup(gnl_ret);
		free(gnl_ret);
		i++;
	}
	return (entire_archive);
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
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
