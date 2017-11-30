/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:46:34 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 00:14:58 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	grab_tab(t_env *e, int tab[3], int indice, int val)
{
	e->has_grab = 1;
	tab[indice] = val;
	e->val_grabbed = &(tab[indice]);
}

void	mouse_event_colors(int x, int y, t_env *e)
{
	int val;

	val = ((x - 10) * 255) / 150;
	if (y >= 300 && y <= 310)
		grab_tab(e, e->tab_t, 0, val);
	if (y >= 320 && y <= 330)
		grab_tab(e, e->tab_t, 1, val);
	if (y >= 340 && y <= 350)
		grab_tab(e, e->tab_t, 2, val);
	if (y >= 400 && y <= 410)
		grab_tab(e, e->tab_m, 0, val);
	if (y >= 420 && y <= 430)
		grab_tab(e, e->tab_m, 1, val);
	if (y >= 440 && y <= 450)
		grab_tab(e, e->tab_m, 2, val);
	if (y >= 500 && y <= 510)
		grab_tab(e, e->tab_b, 0, val);
	if (y >= 520 && y <= 530)
		grab_tab(e, e->tab_b, 1, val);
	if (y >= 540 && y <= 550)
		grab_tab(e, e->tab_b, 2, val);
	repaint(e);
}

void	grab_figure(int key, int x, int y, t_env *e)
{
	if (key == 1)
	{
		e->has_grabbed_figure = 1;
		e->x_figure_grab = x;
		e->y_figure_grab = y;
	}
	if (key == 2)
	{
		e->has_grab_alt_fig = 1;
		e->x_figure_grab = x;
		e->y_figure_grab = y;
	}
}

int		mouse_event_funct_top(int key, int x, int y, t_env *e)
{
	if (x > 25 && x < 175 && y > 85 && y < 135)
	{
		e->proj = PROJ_AXO;
		init_params(e);
	}
	if (x > 25 && x < 175 && y > 160 && y < 210)
	{
		e->proj = PROJ_OBLIQUE;
		init_params(e);
	}
	if (x > 25 && x < 175 && y > 650 && y < 700)
		e->style = STANDARD;
	if (x > 25 && x < 175 && y > 725 && y < 775)
		e->style = VAPORWAVE;
	if (x > 25 && x < 175 && y > 640 && y < 690)
		e->fill = 1;
	if (x > 25 && x < 175 && y > 715 && y < 765)
		e->fill = 0;
	if (x >= 10 && x <= 160 && y > 280 && y < 560)
		mouse_event_colors(x, y, e);
	if (x > e->menu_width && x < WIN_WIDTH && y < WIN_HEIGHT && y > 0)
		grab_figure(key, x, y, e);
	return (0);
}

int		mouse_event_funct(int key, int x, int y, t_env *e)
{
	mouse_event_funct_top(key, x, y, e);
	if (key == 4)
	{
		if (e->scale > 0.5)
			e->scale -= 0.5;
	}
	if (key == 5)
		e->scale += 0.5;
	repaint(e);
	return (0);
}
