/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:43:19 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/17 21:52:45 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	set_values(t_pos **pos, t_str *str, char *file, t_vars *vars, t_map map)
{
	int	i;
	int	j;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_close(vars);
	i = 0;
	while (1)
	{
		j = 0;
		strings->gnl = get_next_line(fd);
		if (strings->gnl == NULL)
			break ; // @TODO Not sure if this will work, have to worry about frees and stuff
		strings->split_ret = ft_split(strings->gnl, ' ');
		while (j < map.rows)
		{
			pos[i][j] = malloc(sizeof(t_pos));
			pos[i][j].x = i;
			pos[i][j].y = j;
			pos[i][j].z = ft_atoi(strings->split_ret[j]);
			j++;
		}
		i++;
	}
}

int	split_size(char **str)
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

int	count_lines(char *argv)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(1);
	while (get_next_line(fd))
		i++;
	close(fd);
	return (i);
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
