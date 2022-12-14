/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:14:19 by fnacarel          #+#    #+#             */
/*   Updated: 2022/12/01 18:56:58 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

static void	update_line_high(int *diff, int *x, int deltas[2], int xi);
static void	update_line_low(int *diff, int *y, int deltas[2], int yi);
static void	ft_plot_line_low(t_pos *pos0, t_pos *pos1, t_win *win);
static void	ft_plot_line_high(t_pos *pos0, t_pos *pos1, t_win *win);

void	ft_plot_line(t_pos *pos0, t_pos *pos1, t_win *win)
{
	if (abs(pos1->y - pos0->y) < abs(pos1->x - pos0->x))
	{
		if (pos0->x > pos1->x)
			ft_plot_line_low(pos1, pos0, win);
		else
			ft_plot_line_low(pos0, pos1, win);
	}
	else
	{
		if (pos0->y > pos1->y)
			ft_plot_line_high(pos1, pos0, win);
		else
			ft_plot_line_high(pos0, pos1, win);
	}
}

static void	ft_plot_line_high(t_pos *pos0, t_pos *pos1, t_win *win)
{
	int	deltas[2];
	int	diff;
	int	xi;
	int	x;
	int	i;

	i = pos0->y;
	xi = 1;
	deltas[0] = pos1->x - pos0->x;
	deltas[1] = pos1->y - pos0->y;
	if (deltas[0] < 0)
	{
		xi = -1;
		deltas[0] = deltas[0] * -1;
	}
	diff = (2 * deltas[0]) - deltas[1];
	x = pos0->x;
	while (i <= pos1->y)
	{
		my_mlx_pixel_put(win, x, i, pos1->color);
		update_line_high(&diff, &x, deltas, xi);
		i++;
	}
}

static void	ft_plot_line_low(t_pos *pos0, t_pos *pos1, t_win *win)
{
	int	deltas[2];
	int	diff;
	int	yi;
	int	y;
	int	i;

	i = pos0->x;
	yi = 1;
	deltas[0] = pos1->y - pos0->y;
	deltas[1] = pos1->x - pos0->x;
	if (deltas[0] < 0)
	{
		yi = -1;
		deltas[0] = deltas[0] * -1;
	}
	diff = (2 * deltas[0]) - deltas[1];
	y = pos0->y;
	while (i <= pos1->x)
	{
		my_mlx_pixel_put(win, i, y, pos1->color);
		update_line_low(&diff, &y, deltas, yi);
		i++;
	}
}

static void	update_line_low(int *diff, int *y, int deltas[2], int yi)
{
	if (*diff > 0)
	{
		*y = *y + yi;
		*diff = *diff + (2 * (deltas[0] - deltas[1]));
	}
	else
		*diff = *diff + 2 * deltas[0];
}

static void	update_line_high(int *diff, int *x, int deltas[2], int xi)
{
	if (*diff > 0)
	{
		*x = *x + xi;
		*diff = *diff + (2 * (deltas[0] - deltas[1]));
	}
	else
		*diff = *diff + 2 * deltas[0];
}
