/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:49:43 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/23 22:18:39 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	set_columns(char *argv, t_map *map);
static void	set_rows(char *argv, t_map *map);
static int	get_number_of_columns(char **str);

void	set_rows_and_columns(char *argv, t_map *map)
{
	set_rows(argv, map);
	set_columns(argv, map);
}

static void	set_columns(char *argv, t_map *map)
{
	int		i;
	int		fd;
	char	*str;
	char	**split;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(1);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if (i == 0)
		{
			split = ft_split(str, ' ');
			map->columns = get_number_of_columns(split);
			free_matrix((void **)split);
		}
		free(str);
		i++;
	}
	close(fd);
}

static void	set_rows(char *argv, t_map *map)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(1);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free(str);
		i++;
	}
	map->rows = i;
	close(fd);
}

static int	get_number_of_columns(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}
