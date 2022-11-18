/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:43:19 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/17 20:57:32 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	split_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
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
