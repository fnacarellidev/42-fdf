/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_input_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:49:43 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/20 00:03:53 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	number_of_columns(char **str)
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
			map->columns = number_of_columns(ft_split(str, ' '));
		i++;
	}
	get_next_line(fd);
	close(fd);
}

void	set_rows(char *argv, t_map *map)
{
	int		i;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(1);
	while (get_next_line(fd))
		i++;
	get_next_line(fd);
	map->rows = i;
	close(fd);
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

