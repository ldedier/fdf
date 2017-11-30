/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_param_axo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:39:53 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 01:20:22 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		min_x_axo(t_env *e)
{
	int		i;
	int		j;
	double	min;
	double	proj_x;

	min = 100000;
	i = 0;
	while (i < e->parser->height)
	{
		j = 0;
		while (j < e->parser->length)
		{
			proj_x = (cos(e->omega) * (j - (e->parser->length - 1) / 2)) -
			(sin(e->omega) * (i - (e->parser->height - 1) / 2));
			if (min > proj_x)
				min = proj_x;
			j++;
		}
		i++;
	}
	return (min);
}

double		max_x_axo(t_env *e)
{
	int		i;
	int		j;
	int		max;
	double	proj_x;

	max = -100000;
	i = 0;
	while (i < e->parser->height)
	{
		j = 0;
		while (j < e->parser->length)
		{
			proj_x = (cos(e->omega) * (j - (e->parser->length - 1) / 2)) -
			(sin(e->omega) * (i - (e->parser->height - 1) / 2));
			if (max < proj_x)
				max = proj_x;
			j++;
		}
		i++;
	}
	return (max);
}

double		min_y_axo(t_env *e)
{
	int		i;
	int		j;
	double	min;
	double	proj_y;

	min = 100000;
	i = 0;
	while (i < e->parser->height)
	{
		j = 0;
		while (j < e->parser->length)
		{
			proj_y = -((-sin(e->omega) * sin(e->alpha) *
					(j - (e->parser->length - 1) / 2))
					- (cos(e->omega) * sin(e->alpha) *
					(i - (e->parser->height - 1) / 2))
					+ (cos(e->alpha) * (e->parser->tab[i][j] * e->depth_adder -
					(e->parser->depth + 1) / 2)));
			if (min > proj_y)
				min = proj_y;
			j++;
		}
		i++;
	}
	return (min);
}

double		max_y_axo(t_env *e)
{
	int		i;
	int		j;
	double	max;
	double	proj_y;

	max = -100000;
	i = 0;
	while (i < e->parser->height)
	{
		j = 0;
		while (j < e->parser->length)
		{
			proj_y = -((-sin(e->omega) * sin(e->alpha) *
			(j - (e->parser->length - 1) / 2)) - (cos(e->omega) *
			sin(e->alpha) * (i - (e->parser->height - 1) / 2)) +
			(cos(e->alpha) * (e->parser->tab[i][j] * e->depth_adder -
			(e->parser->depth + 1) / 2)));
			if (max < proj_y)
				max = proj_y;
			j++;
		}
		i++;
	}
	return (max);
}
