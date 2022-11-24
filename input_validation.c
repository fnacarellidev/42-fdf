/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:03:46 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/24 00:22:48 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	test_if_file_is_readable(char *argv);

void		validate_input(int argc, char *argv)
{
	char	*str;

	if (argc != 2)
	{
		ft_printf("Expected 1 parameter (excluding program name).");
		exit(1);
	}
	test_if_file_is_readable(argv);
	str = ft_strrchr(argv, '.');
	if (ft_strlen(str) != 4 || !(ft_strncmp(str, ".fdf", 4) == 0))
	{
		ft_printf("File must be of .fdf extension.\n");
		exit(1);
	}
	else if (ft_strlen(argv) == 4)
	{
		ft_printf("File can't be named only .fdf\n");
		exit(1);
	}
}

static void	test_if_file_is_readable(char *argv)
{
	int		fd;
	char	buf[1];

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Failed to open file, try again.\n");
		close(fd);
		exit(1);
	}
	else if (!read(fd, buf, 1))
	{
		ft_printf("File should not be empty.\n");
		close(fd);
		exit(1);
	}
	close(fd);
}
