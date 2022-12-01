/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:13:55 by fnacarel          #+#    #+#             */
/*   Updated: 2022/12/01 18:58:49 by fnacarel         ###   ########.fr       */
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
# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"
# include "../libs/get_next_line/get_next_line.h"

# define WIDTH 1920
# define HEIGHT 1080
# define COLOR 0Xffffff
# define ESC_KEYCODE 65307
# define H_KEYCODE 104
# define J_KEYCODE 106
# define K_KEYCODE 107
# define L_KEYCODE 108
# define PLUS_KEYCODE 61
# define MINUS_KEYCODE 45

typedef struct s_map
{
	int		rows;
	int		columns;
}				t_map;

typedef struct s_pos
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_pos;

typedef struct s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			endian;
	int			line_length;
	int			bits_per_pixel;
	t_pos		**pos_ptr;
	t_map		*map_ptr;
}				t_win;

void	validate_input(int argc, char *argv);
void	multiply_matrix(t_pos **pos, t_map map);
void	ft_plot_line(t_pos *pos0, t_pos *pos1, t_win *img);
void	set_rows_and_columns(char *argv, t_map *map);
void	set_values(t_pos **pos, int fd, t_map map);
void	init_window(t_win *win);
void	init_image(t_win *img);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
void	connect_both_axis(t_pos **pos, t_win *img, t_map map);
void	init_loop_and_hooks(t_win *vars);
void	transform_positions(t_pos **pos, t_map map);
void	free_matrix(void **matrix);
void	initialize_stuff(char *argv);
void	ft_move_img(int keycode, t_win *win);
void	put_img_to_window(t_win *win);
void	zoom_in(t_win *win);
void	zoom_out(t_win *win);
int		count_lines(char *argv);
int		ft_close(t_win *vars);
int		ft_keyhook(int keycode, t_win *vars);

#endif
