/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:39:36 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 16:02:18 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_vapor_printed_x(int x, t_env *e)
{
	int		green_value;
	double	current_height;

	current_height = e->z1 + (double)(((double)1 - (double)(abs(x - e->x2) /
						(double)abs(e->x2 - e->x1))) * (e->z2 - e->z1));
	green_value = (double)((double)current_height /
			(double)e->parser->max_value) * 255;
	return (get_color(255 - green_value, green_value, 255));
}

int		get_vapor_printed_y(int y, t_env *e)
{
	int		green_value;
	double	current_height;

	current_height = e->z1 + (double)((double)1 - (double)(abs(y - e->y2) /
				(double)abs(e->y2 - e->y1))) * ((e->z2 - e->z1));
	green_value = ((double)current_height /
			(double)e->parser->max_value) * 255;
	return (get_color(255 - green_value, green_value, 255));
}
