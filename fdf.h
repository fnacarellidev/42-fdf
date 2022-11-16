/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:13:55 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/16 19:55:31 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "./libs/libft/libft.h"
# include "./libs/mlx/mlx.h"
# include "./libs/get_next_line/get_next_line.h"

# define WIDTH 1080
# define ON_DESTROY_KEYCODE -424072400
# define HEIGHT 1920
# define COLOR 0X2FFF00

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_plot_line_high(t_pos *pos0, t_pos *pos1, t_data *data);
void	ft_plot_line_low(t_pos *pos0, t_pos *pos1, t_data *data);
void	ft_plot_line(t_pos *pos0, t_pos *pos1, t_data *data);

#endif
