/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_oblique.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:54:54 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 01:49:57 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		min_x_oblique(t_env *e)
{
	int	i;
	int	j;
	int min;
	int	proj_x;

	min = 100000;
	i = 0;
	while (i < e->parser->height)
	{
		j = 0;
		while (j < e->parser->length)
		{
			proj_x = ((j + (((double)1 / (double)2) *
							(double)(e->parser->tab[i][j] * e->depth_adder)) *
							cos(e->alpha_ob)));
			if (min > proj_x)
				min = proj_x;
			j++;
		}
		i++;
	}
	return (min);
}

int		max_x_oblique(t_env *e)
{
	int	i;
	int	j;
	int max;
	int	proj_x;

	max = -100000;
	i = 0;
	while (i < e->parser->height)
	{
		j = 0;
		while (j < e->parser->length)
		{
			proj_x = ((j + (((double)1 / (double)2) *
							(double)e->parser->tab[i][j] * e->depth_adder) *
							cos(e->alpha_ob)));
			if (max < proj_x)
				max = proj_x;
			j++;
		}
		i++;
	}
	return (max);
}

int		min_y_oblique(t_env *e)
{
	int	i;
	int	j;
	int min;
	int	proj_y;

	min = 100000;
	i = 0;
	while (i < e->parser->height)
	{
		j = 0;
		while (j < e->parser->length)
		{
			proj_y = ((i + (((double)1 / (double)2) *
	(double)e->parser->tab[i][j] * e->depth_adder) * sin(e->alpha_ob)));
			if (min > proj_y)
				min = proj_y;
			j++;
		}
		i++;
	}
	return (min);
}

int		max_y_oblique(t_env *e)
{
	int	i;
	int	j;
	int max;
	int	proj_y;

	max = -100000;
	i = 0;
	while (i < e->parser->height)
	{
		j = 0;
		while (j < e->parser->length)
		{
			proj_y = ((i + (((double)1 / (double)2) *
	(double)e->parser->tab[i][j] * e->depth_adder) * sin(e->alpha_ob)));
			if (max < proj_y)
				max = proj_y;
			j++;
		}
		i++;
	}
	return (max);
}
