/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:49:43 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/21 21:38:21 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	get_number_of_columns(char **str)
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

void	set_columns(char *argv, t_map *map)
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
			free_split(split);
		}
		free(str);
		i++;
	}
	close(fd);
}

void	set_rows(char *argv, t_map *map)
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

void	set_rows_and_columns(char *argv, t_map *map)
{
	set_rows(argv, map);
	set_columns(argv, map);
}

int	validate_input(char *argv)
{
	char	*str;

	str = ft_strrchr(argv, '.');
	if (ft_strlen(str) != 4)
	{
		ft_printf("File must be of .fdf extension.\n");
		exit(1);
	}
	else if (ft_strlen(argv) == 4)
	{
		ft_printf("File can't be named only .fdf\n");
		exit(1);
	}
	if (!(ft_strncmp(str, ".fdf", 4) == 0))
	{
		ft_printf("File must be of .fdf extension.\n");
		exit(1);
	}
	return (1);
}

