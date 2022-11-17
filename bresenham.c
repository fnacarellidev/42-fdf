/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:14:19 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/16 19:50:41 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	ft_plot_line_high(t_pos *pos0, t_pos *pos1, t_data *data)
{
	int	i;
	int	x;
	int	d;
	int	xi;
	int	diff_x;
	int	diff_y;

	i = pos0->y;
	xi = 1;
	diff_x = pos1->x - pos0->x;
	diff_y = pos1->y - pos0->y;
	if (diff_x < 0)
	{
		xi = -1;
		diff_x = diff_x * -1;
	}
	d = (2 * diff_x) - diff_y;
	x = pos0->x;
	while (i <= pos1->y)
	{
		my_mlx_pixel_put(data, x, i, COLOR);
		if (d > 0)
		{
			x = x + xi;
			d = d + (2 * (diff_x - diff_y));
		}
		else
			d = d + 2 * diff_x;
		i++;
	}
}

void	ft_plot_line_low(t_pos *pos0, t_pos *pos1, t_data *data)
{
	int	d;
	int	y;
	int	i;
	int	yi;
	int	diff_x;
	int	diff_y;

	i = pos0->x;
	yi = 1;
	diff_y = pos1->y - pos0->y;
	diff_x = pos1->x - pos0->x;
	if (diff_y < 0)
	{
		yi = -1;
		diff_y = diff_y * -1;
	}
	d = (2 * diff_y) - diff_x;
	y = pos0->y;
	while (i <= pos1->x)
	{
		my_mlx_pixel_put(data, i, y, COLOR);
		if (d > 0)
		{
			y = y + yi;
			d = d + (2 * (diff_y - diff_x));
		}
		else
			d = d + 2 * diff_y;
		i++;
	}

}

void	ft_plot_line(t_pos *pos0, t_pos *pos1, t_data *data)
{
	if (abs(pos1->y - pos0->y) < abs(pos1->x - pos0->x))
	{
		if (pos0->x > pos1->x)
			ft_plot_line_low(pos1, pos0, data);
		else
			ft_plot_line_low(pos0, pos1, data);
	}
	else
	{
		if (pos0->y > pos1->y)
			ft_plot_line_high(pos1, pos0, data);
		else
			ft_plot_line_high(pos0, pos1, data);
	}
}
