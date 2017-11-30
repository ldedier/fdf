/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:14:09 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 15:03:57 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_axo(t_env *e)
{
	double x_scale;
	double y_scale;

	x_scale = 2 * (double)(((double)(WIN_WIDTH - e->menu_width) /
		((double)(max_x_axo(e) - min_x_axo(e)) * 3)));
	y_scale = 2 * (double)(((double)(WIN_HEIGHT) /
		((double)(max_y_axo(e) - min_y_axo(e)) * 3)));
	if (x_scale > y_scale)
		e->scale = y_scale;
	else
		e->scale = x_scale;
	e->x_margin = (double)((double)1 / (double)6) * (WIN_WIDTH -
				e->menu_width) - (min_x_axo(e) * e->scale) + e->menu_width;
	e->y_margin = (double)((double)1 / (double)6) * WIN_HEIGHT -
			min_y_axo(e) * y_scale;
}

void	init_oblique(t_env *e)
{
	double x_scale;
	double y_scale;

	x_scale = 2 * (double)(((double)(WIN_WIDTH - e->menu_width) /
		((double)(max_x_oblique(e) - min_x_oblique(e)) * 3)));
	y_scale = 2 * (double)(((double)(WIN_HEIGHT) /
		((double)(max_y_oblique(e) - min_y_oblique(e)) * 3)));
	if (x_scale > y_scale)
		e->scale = y_scale;
	else
		e->scale = x_scale;
	e->x_margin = (double)((double)1 / (double)6) * (WIN_WIDTH -
				e->menu_width) - (min_x_oblique(e) * e->scale) + e->menu_width;
	e->y_margin = (double)((double)1 / (double)6) * WIN_HEIGHT -
			min_y_oblique(e) * e->scale;
}

void	init_params(t_env *e)
{
	if (e->proj == PROJ_AXO)
		init_axo(e);
	if (e->proj == PROJ_OBLIQUE)
		init_oblique(e);
}

void	init_env(t_env *e)
{
	e->width = WIN_WIDTH;
	e->height = WIN_HEIGHT;
	e->menu_width = 200;
	e->proj = PROJ_AXO;
	e->alpha_ob = M_PI / 3;
	e->teta = M_PI / 32;
	e->depth_adder = 1;
	e->alpha = 15 * (M_PI / 32);
	e->bbp = 0;
	e->endian = 0;
	e->size_line = 0;
	e->omega = 7 * (M_PI / 32);
	e->tab_t[0] = 255;
	e->tab_t[1] = 255;
	e->tab_t[2] = 255;
	e->tab_m[0] = 96;
	e->tab_m[1] = 61;
	e->tab_m[2] = 0;
	e->tab_b[0] = 0;
	e->tab_b[1] = 255;
	e->tab_b[2] = 0;
	e->style = STANDARD;
	e->has_grab = 0;
	e->has_grabbed_figure = 0;
	e->has_grab_alt_fig = 0;
}
