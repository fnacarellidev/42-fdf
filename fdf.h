/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:13:55 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/21 21:51:46 by fnacarel         ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 1080
# define COLOR 0X2FFF00
# define ESC_KEYCODE 65307
# define ALPHA M_PI / 6
# define THETA M_PI / 4

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_map
{
	int		rows;
	int		columns;
}				t_map;

typedef struct s_str
{
	char	*gnl_ret;
	char	**split_ret;
}				t_str;

typedef struct s_pos
{
	int		x;
	int		y;
	int		z;
}				t_pos;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
}				t_data;

void	multiply_matrix(t_pos **pos, t_map map);
void	ft_plot_line_high(t_pos *pos0, t_pos *pos1, t_data *img);
void	ft_plot_line_low(t_pos *pos0, t_pos *pos1, t_data *img);
void	ft_plot_line(t_pos *pos0, t_pos *pos1, t_data *img);
void	set_rows_and_columns(char *argv, t_map *map);
void	set_rows(char *argv, t_map *map);
void	set_columns(char *argv, t_map *map);
void	free_split(char **splitted);
void	set_values(t_pos **pos, t_str *str, char *file, t_vars *vars, t_map map);
void	init_window_and_hooks(t_vars *vars);
void	init_image(t_data *img, t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	connect_both_axis(t_pos **pos, t_data *img, t_map map);
void	init_loop_and_hooks(t_vars *vars);
void	transform_positions(t_pos **pos, t_map map);
int		count_lines(char *argv);
int		get_number_of_columns(char **str);
int		validate_input(char *argv);
int		ft_close(t_vars *vars);
int		ft_keyhook(int keycode, t_vars *vars);

#endif
