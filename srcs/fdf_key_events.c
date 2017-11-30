/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:08:09 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 15:31:05 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_pressed_axo(int keycode, t_env *e)
{
	if (keycode == 123)
		e->omega = e->omega + M_PI / 64;
	if (keycode == 124)
		e->omega = e->omega - M_PI / 64;
	if (keycode == 125)
		e->alpha = e->alpha + M_PI / 64;
	if (keycode == 126)
		e->alpha = e->alpha - M_PI / 64;
}

void	funct_key_pressed_top(int keycode, t_env *e)
{
	if (keycode == 89)
		e->y_margin += 10;
	if (keycode == 91)
		e->y_margin -= 10;
	if (keycode == 86)
		e->x_margin -= 10;
	if (keycode == 87)
		e->y_margin += 10;
	if (keycode == 88)
		e->x_margin += 10;
	if (keycode == 85)
	{
		e->depth_adder = 1;
		init_params(e);
	}
}

void	funct_key_pressed_bottom(int keycode, t_env *e)
{
	if (keycode == 78)
	{
		if (e->scale > 0.5)
			e->scale -= 0.5;
	}
	if (keycode == 69)
		e->scale += 0.5;
	if (keycode == 83)
		e->depth_adder -= 0.1;
	if (keycode == 84)
		e->depth_adder += 0.1;
}

int		funct_key_pressed(int keycode, t_env *e)
{
	if (keycode >= 85)
		funct_key_pressed_top(keycode, e);
	else
		funct_key_pressed_bottom(keycode, e);
	if (e->proj == PROJ_AXO)
		key_pressed_axo(keycode, e);
	if (e->proj == PROJ_OBLIQUE)
	{
		if (keycode == 123)
			e->alpha_ob = e->alpha_ob + M_PI / 32;
		if (keycode == 124)
			e->alpha_ob = e->alpha_ob - M_PI / 32;
	}
	repaint(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 31 && e->proj != PROJ_OBLIQUE)
	{
		e->proj = PROJ_OBLIQUE;
		init_params(e);
		repaint(e);
	}
	if (keycode == 34 && e->proj != PROJ_AXO)
	{
		e->proj = PROJ_AXO;
		init_params(e);
		repaint(e);
	}
	return (0);
}
