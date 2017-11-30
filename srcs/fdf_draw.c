/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:03:56 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 01:49:27 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_on_screen_segment(t_env *e)
{
	if (e->x1 < 0 && e->x2 < 0)
		return (0);
	if (e->x1 > WIN_WIDTH && e->x2 > WIN_WIDTH)
		return (0);
	if (e->y1 < 0 && e->y2 < 0)
		return (0);
	if (e->y1 > WIN_HEIGHT && e->y2 > WIN_HEIGHT)
		return (0);
	return (1);
}

int		draw_segment_img(t_env *e, int *data)
{
	if (is_on_screen_segment(e))
		draw_segment_tierce(e, data);
	return (0);
}

void	draw_vertical_segment(int ind_x, int ind_y, t_env *e, int *data)
{
	double z;

	z = e->parser->tab[ind_y + 1][ind_x];
	e->z2 = z;
	e->x2 = e->x_margin + ((cos(e->omega) * (ind_x -
			(e->parser->length - 1) / 2))
			- (sin(e->omega) * (ind_y + 1 - (e->parser->height - 1) / 2)))
		* e->scale;
	e->y2 = e->y_margin - (((-sin(e->omega) * sin(e->alpha) *
					(ind_x - (e->parser->length - 1) / 2)) -
				(cos(e->omega) * sin(e->alpha) *
				(ind_y + 1 - (e->parser->height - 1) / 2)) +
				(cos(e->alpha) *
				(z * e->depth_adder - (e->parser->depth + 1) / 2))) * e->scale);
	draw_segment_img(e, data);
}

void	draw_horizontal_segment(int ind_x, int ind_y, t_env *e, int *data)
{
	double z;

	z = e->parser->tab[ind_y][ind_x + 1];
	e->z2 = z;
	e->x2 = e->x_margin + ((cos(e->omega) * (ind_x + 1 -
			(e->parser->length - 1) / 2))
			- (sin(e->omega) * (ind_y - (e->parser->height - 1) / 2)))
			* e->scale;
	e->y2 = e->y_margin - (((-sin(e->omega) * sin(e->alpha) *
				(ind_x + 1 - (e->parser->length - 1) / 2)) - (cos(e->omega)
				* sin(e->alpha) * (ind_y - (e->parser->height - 1) / 2)) +
				(cos(e->alpha) *
				(z * e->depth_adder - (e->parser->depth + 1) / 2))) * e->scale);
	draw_segment_img(e, data);
}

void	draw_lines_axo_img(int ind_x, int ind_y, t_env *e, int *data)
{
	double x;
	double y;
	double z;

	x = ind_x;
	y = ind_y;
	z = e->parser->tab[ind_y][ind_x];
	e->z1 = z;
	e->x1 = e->x_margin + ((cos(e->omega) * (x - (e->parser->length - 1) / 2))
			- (sin(e->omega) * (y - (e->parser->height - 1) / 2))) * e->scale;
	e->y1 = e->y_margin - (((-sin(e->omega) * sin(e->alpha) *
				(x - (e->parser->length - 1) / 2)) - (cos(e->omega) *
				sin(e->alpha) * (y - (e->parser->height - 1) / 2)) +
				(cos(e->alpha) *
				(z * e->depth_adder - (e->parser->depth + 1) / 2))) * e->scale);
	if (ind_y < e->parser->height - 1)
		draw_vertical_segment(ind_x, ind_y, e, data);
	if (ind_x < e->parser->length - 1)
		draw_horizontal_segment(ind_x, ind_y, e, data);
}
