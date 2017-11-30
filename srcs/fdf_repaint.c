/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_repaint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:11:19 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 01:58:08 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iter_drawing(t_env *e, int *data)
{
	int i;
	int j;

	i = 0;
	while (i < e->parser->height)
	{
		j = 0;
		while (j < e->parser->length)
		{
			if (e->proj == PROJ_AXO)
				draw_lines_axo_img(j, i, e, data);
			if (e->proj == PROJ_OBLIQUE)
				draw_lines_oblique_img(j, i, e, data);
			j++;
		}
		i++;
	}
}

void	process_paint_figure_img(t_env *e)
{
	int		*data;

	if (e->img_figure == NULL)
	{
		ft_putendl_fd("mlx malloc error.", 2);
		exit(1);
	}
	data = (int *)mlx_get_data_addr(e->img_figure, &(e->bbp),
	&(e->size_line), &(e->endian));
	e->image_width = WIN_WIDTH;
	e->image_height = WIN_HEIGHT;
	iter_drawing(e, data);
	mlx_put_image_to_window(e->mlx, e->win, e->img_figure, 0, 0);
	mlx_destroy_image(e->mlx, e->img_figure);
}

void	paint_figure_img(t_env *e)
{
	if (e->style == VAPORWAVE)
		e->img_figure = mlx_xpm_file_to_image(e->mlx,
		"./resources/vapo_cool.xpm",
		&(e->width), &(e->height));
	else
		e->img_figure = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	process_paint_figure_img(e);
}

void	repaint(t_env *e)
{
	paint_figure_img(e);
	paint_interface_img(e);
}
