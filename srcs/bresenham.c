/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:37:33 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/24 17:38:33 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_data_x(int x, int y, t_env *e, int *data)
{
	int indice;

	indice = x + WIN_WIDTH * y;
	if (indice > 0 && indice < (WIN_WIDTH * WIN_HEIGHT) &&
	x < WIN_WIDTH && y < WIN_HEIGHT && x > 0 && y > 0)
	{
		if (e->style == VAPORWAVE)
			data[x + y * WIN_WIDTH] = get_vapor_printed_x(x, e);
		else
			data[x + y * WIN_WIDTH] = get_standard_color_x(x, e);
	}
}

void	print_data_y(int x, int y, t_env *e, int *data)
{
	int indice;

	indice = x + WIN_WIDTH * y;
	if (indice > 0 && indice < (WIN_WIDTH * WIN_HEIGHT) &&
	x < WIN_WIDTH && y < WIN_HEIGHT && x > 0 && y > 0)
	{
		if (e->style == VAPORWAVE)
			data[x + y * WIN_WIDTH] = get_vapor_printed_y(y, e);
		else
			data[x + y * WIN_WIDTH] = get_standard_color_y(y, e);
	}
}

void	process_bresenham_top(int x, int y, t_env *e, int *data)
{
	int i;

	i = 0;
	print_data_x(x, y, e, data);
	e->er = 2 * e->dy - e->dx;
	e->inc1 = 2 * (e->dy - e->dx);
	e->inc2 = 2 * e->dy;
	while (i < e->dx)
	{
		if (e->er >= 0)
		{
			y += e->incy;
			e->er += e->inc1;
		}
		else
			e->er += e->inc2;
		x += e->incx;
		print_data_x(x, y, e, data);
		i++;
	}
}

void	process_bresenham_bottom(int x, int y, t_env *e, int *data)
{
	int i;

	i = 0;
	print_data_y(x, y, e, data);
	e->er = 2 * e->dx - e->dy;
	e->inc1 = 2 * (e->dx - e->dy);
	e->inc2 = 2 * e->dx;
	while (i < e->dy)
	{
		if (e->er >= 0)
		{
			x += e->incx;
			e->er += e->inc1;
		}
		else
			e->er += e->inc2;
		y += e->incy;
		print_data_y(x, y, e, data);
		i++;
	}
}

int		draw_segment_tierce(t_env *e, int *data)
{
	int x;
	int y;

	e->dx = e->x2 - e->x1;
	e->dy = e->y2 - e->y1;
	if (e->dx < 0)
		e->dx = -e->dx;
	if (e->dy < 0)
		e->dy = -e->dy;
	e->incx = 1;
	if (e->x2 < e->x1)
		e->incx = -1;
	e->incy = 1;
	if (e->y2 < e->y1)
		e->incy = -1;
	x = e->x1;
	y = e->y1;
	if (e->dx > e->dy)
		process_bresenham_top(x, y, e, data);
	else
		process_bresenham_bottom(x, y, e, data);
	return (0);
}
