/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors_height.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:26:48 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 01:48:01 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(int r, int g, int b)
{
	int color;

	color = 0;
	g = g << 8;
	r = r << 16;
	color = r | g | b;
	return (color);
}

int		get_color_height_inf(double current_height, int average, t_env *e)
{
	int red;
	int green;
	int blue;

	red = e->tab_b[0] + ((double)(((double)current_height /
					(double)average)) * (e->tab_m[0] - e->tab_b[0]));
	green = e->tab_b[1] + ((double)(((double)current_height
					/ (double)average)) * (e->tab_m[1]
				- e->tab_b[1]));
	blue = e->tab_b[2] + ((double)(((double)current_height
					/ (double)average)) * (e->tab_m[2]
				- e->tab_b[2]));
	return (get_color(red, green, blue));
}

int		get_color_height_sup(double current_height, int average, t_env *e)
{
	int red;
	int blue;
	int green;

	red = e->tab_m[0] + ((double)(((double)(current_height - average)
					/ (double)(e->parser->max_value - average))) *
			(e->tab_t[0] - e->tab_m[0]));
	green = e->tab_m[1] + ((double)(((double)(current_height -
						average) / (double)(e->parser->max_value -
							average))) * (e->tab_t[1] -
						e->tab_m[1]));
	blue = e->tab_m[2] + ((double)(((double)(current_height
						- average) / (double)(e->parser->max_value
							- average))) * (e->tab_t[2] -
						e->tab_m[2]));
	return (get_color(red, green, blue));
}

int		get_standard_color_x(int x, t_env *e)
{
	double	current_height;
	int		average;

	average = (e->parser->max_value + e->parser->min_value) / 2;
	current_height = e->z1 + (double)(((double)(1 - (double)(abs(x - e->x2) /
						(double)abs(e->x2 - e->x1))) * (e->z2 - e->z1)));
	if (current_height < average)
		return (get_color_height_inf(current_height, average, e));
	else
		return (get_color_height_sup(current_height, average, e));
}

int		get_standard_color_y(int y, t_env *e)
{
	double	current_height;
	int		average;

	average = (e->parser->max_value + e->parser->min_value) / 2;
	current_height = e->z1 + (double)((double)1 - (double)(abs(y - e->y2) /
				(double)abs(e->y2 - e->y1))) * ((e->z2 - e->z1));
	if (current_height < average)
		return (get_color_height_inf(current_height, average, e));
	else
		return (get_color_height_sup(current_height, average, e));
}
