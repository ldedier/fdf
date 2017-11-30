/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_paint_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:58:26 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 01:51:16 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		mlx_put_pixel_to_image(t_env *e, int color)
{
	int		i;
	int		j;
	int		*data;

	data = (int *)mlx_get_data_addr(e->img, &(e->bbp),
	&(e->size_line), &(e->endian));
	i = 0;
	while (i < e->image_height)
	{
		j = 0;
		while (j < e->image_width)
		{
			data[j + i * e->image_width] = color;
			j++;
		}
		i++;
	}
}

void		print_xpm(t_env *e, char *xpm, int x, int y)
{
	e->img = mlx_xpm_file_to_image(e->mlx,
	xpm, &(e->width), &(e->height));
	if (e->img == NULL)
	{
		ft_putendl_fd("mlx malloc error.", 2);
		exit(1);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, x, y);
}

void		add_square_data(t_env *e, int x, int y, int color)
{
	int		i;
	int		j;

	i = y;
	while (i < y + e->image_height)
	{
		j = x;
		while (j < x + e->image_width)
		{
			if (j == x || j == x + e->image_width - 1 || i == y ||
			i == y + e->image_height - 1)
				e->data[j + i * e->menu_width] = 0x00000000;
			else
				e->data[j + i * e->menu_width] = color;
			j++;
		}
		i++;
	}
}

void		add_square_data_no_border(t_env *e, int x, int y, int color)
{
	int		i;
	int		j;

	i = y;
	while (i < y + e->image_height)
	{
		j = x;
		while (j < x + e->image_width)
		{
			e->data[j + i * e->menu_width] = color;
			j++;
		}
		i++;
	}
}

void		put_preview(t_env *e)
{
	e->image_width = 30;
	e->image_height = 30;
	add_square_data(e, 165, 510, get_color(e->tab_b[0],
				e->tab_b[1], e->tab_b[2]));
	add_square_data(e, 165, 410, get_color(e->tab_m[0],
				e->tab_m[1], e->tab_m[2]));
	add_square_data(e, 165, 310, get_color(e->tab_t[0],
				e->tab_t[1], e->tab_t[2]));
}
