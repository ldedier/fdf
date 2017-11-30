/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_oblique.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:54:54 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 00:32:42 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_ver_ob(int ind_x, int ind_y, t_env *e, int *data)
{
	double z;

	z = e->parser->tab[ind_y + 1][ind_x];
	e->x2 = e->x_margin + (((ind_x + (((double)1 / (double)2) *
	(double)z * e->depth_adder) * cos(e->alpha_ob))) * e->scale);
	e->y2 = e->y_margin + (((ind_y + 1 + (((double)1 / (double)2) *
	(double)z * e->depth_adder) * sin(e->alpha_ob))) * e->scale);
	e->z2 = z;
	draw_segment_img(e, data);
}

void	draw_hor_ob(int ind_x, int ind_y, t_env *e, int *data)
{
	double z;

	z = e->parser->tab[ind_y][ind_x + 1];
	e->x2 = e->x_margin + (((ind_x + 1 + (((double)1 / (double)2) *
	(double)z * e->depth_adder) * cos(e->alpha_ob))) * e->scale);
	e->y2 = e->y_margin + (((ind_y + (((double)1 / (double)2) *
	(double)z * e->depth_adder) * sin(e->alpha_ob))) * e->scale);
	e->z2 = z;
	draw_segment_img(e, data);
}

void	draw_lines_oblique_img(int ind_x, int ind_y, t_env *e, int *data)
{
	double x;
	double y;
	double z;

	x = ind_x;
	y = ind_y;
	z = e->parser->tab[ind_y][ind_x];
	e->x1 = e->x_margin + (((x + (((double)1 / (double)2) *
	(double)z * e->depth_adder) * cos(e->alpha_ob))) * e->scale);
	e->y1 = e->y_margin + (((y + (((double)1 / (double)2) *
	(double)z * e->depth_adder) * sin(e->alpha_ob))) * e->scale);
	e->z1 = z;
	if (ind_y < e->parser->height - 1)
		draw_ver_ob(ind_x, ind_y, e, data);
	if (ind_x < e->parser->length - 1)
		draw_hor_ob(ind_x, ind_y, e, data);
}
