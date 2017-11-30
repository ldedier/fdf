/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_motion_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:15:47 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 01:22:31 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		funct_mouse_released(int key, int x, int y, t_env *e)
{
	int i;

	i = x;
	i = y;
	if (key == 1)
	{
		e->has_grab = 0;
		e->has_grabbed_figure = 0;
	}
	else
		e->has_grab_alt_fig = 0;
	return (0);
}

void	funct_motion_top(int x, int y, t_env *e)
{
	if (e->has_grabbed_figure == 1)
	{
		if (e->proj == PROJ_AXO)
		{
			e->alpha = e->alpha + ((y - e->y_figure_grab) * (M_PI / 1024));
			e->y_figure_grab = y;
			e->omega = e->omega + ((x - e->x_figure_grab) * (M_PI / 1024));
			e->x_figure_grab = x;
		}
		if (e->proj == PROJ_OBLIQUE)
		{
			e->alpha_ob = e->alpha_ob +
				((x - e->x_figure_grab) * (M_PI / 512));
			e->x_figure_grab = x;
		}
		repaint(e);
	}
}

int		funct_motion(int x, int y, t_env *e)
{
	funct_motion_top(x, y, e);
	if (e->has_grab == 1)
	{
		if (x >= 160)
			x = 160;
		if (x < 10)
			x = 10;
		*(e->val_grabbed) = ((x - 10) * 255) / 150;
		repaint(e);
	}
	if (e->has_grab_alt_fig)
	{
		e->y_margin = e->y_margin + ((y - e->y_figure_grab));
		e->y_figure_grab = y;
		e->x_margin = e->x_margin + ((x - e->x_figure_grab));
		e->x_figure_grab = x;
		repaint(e);
	}
	return (0);
}
