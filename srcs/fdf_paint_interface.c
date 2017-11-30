/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_paint_interface.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:43:46 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 01:59:56 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_cursors(t_env *e)
{
	e->image_width = 5;
	e->image_height = 10;
	add_square_data(e, 10 + (double)((double)e->tab_t[0] /
	(double)250) * 145, 300, 0x00000000);
	add_square_data(e, 10 + (double)((double)e->tab_t[1] /
	(double)250) * 145, 320, 0x00000000);
	add_square_data(e, 10 + (double)((double)e->tab_t[2] /
	(double)250) * 145, 340, 0x00000000);
	add_square_data(e, 10 + (double)((double)e->tab_m[0] /
	(double)250) * 145, 400, 0x00000000);
	add_square_data(e, 10 + (double)((double)e->tab_m[1] /
	(double)250) * 145, 420, 0x00000000);
	add_square_data(e, 10 + (double)((double)e->tab_m[2] /
	(double)250) * 145, 440, 0x00000000);
	add_square_data(e, 10 + (double)((double)e->tab_b[0] /
	(double)250) * 145, 500, 0x00000000);
	add_square_data(e, 10 + (double)((double)e->tab_b[1] /
	(double)250) * 145, 520, 0x00000000);
	add_square_data(e, 10 + (double)((double)e->tab_b[2] /
	(double)250) * 145, 540, 0x00000000);
}

void	paint_interface_struct(t_env *e)
{
	if (e->proj == PROJ_AXO)
		add_square_data(e, 25, 85, 0x00aaaaaa);
	else
		add_square_data(e, 25, 85, 0x00ffffff);
	if (e->proj == PROJ_OBLIQUE)
		add_square_data(e, 25, 160, 0x00aaaaaa);
	else
		add_square_data(e, 25, 160, 0x00ffffff);
	if (e->style == STANDARD)
		add_square_data(e, 25, 650, 0x00aaaaaa);
	else
		add_square_data(e, 25, 650, 0x00ffffff);
	if (e->style == VAPORWAVE)
		add_square_data(e, 25, 725, 0x00aaaaaa);
	else
		add_square_data(e, 25, 725, 0x00ffffff);
}

void	paint_colors_interface(t_env *e)
{
	e->image_width = 150;
	e->image_height = 10;
	if (e->style != VAPORWAVE)
	{
		add_square_data(e, 10, 300, 0x00ff7777);
		add_square_data(e, 10, 320, 0x0077ff77);
		add_square_data(e, 10, 340, 0x007777ff);
		add_square_data(e, 10, 400, 0x00ff7777);
		add_square_data(e, 10, 420, 0x0077ff77);
		add_square_data(e, 10, 440, 0x007777ff);
		add_square_data(e, 10, 500, 0x00ff7777);
		add_square_data(e, 10, 520, 0x0077ff77);
		add_square_data(e, 10, 540, 0x007777ff);
		put_preview(e);
		put_cursors(e);
	}
	e->image_width = e->menu_width;
	e->image_height = 2;
}

void	paint_strings_interface(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 45, 100, 0x00000000, "axonometric");
	mlx_string_put(e->mlx, e->win, 65, 175, 0x00000000, "oblique");
	mlx_string_put(e->mlx, e->win, 60, 666, 0x00000000, "standard");
	mlx_string_put(e->mlx, e->win, 55, 740, 0x00000000, "vaporwave");
	mlx_string_put(e->mlx, e->win, 50, 40, 0x00000000, "projection:");
	mlx_string_put(e->mlx, e->win, 70, 600, 0x00000000, "style:");
	if (e->style != VAPORWAVE)
	{
		mlx_string_put(e->mlx, e->win, 70, 350, 0x00000000, "top");
		mlx_string_put(e->mlx, e->win, 60, 450, 0x00000000, "middle");
		mlx_string_put(e->mlx, e->win, 60, 550, 0x00000000, "bottom");
		mlx_string_put(e->mlx, e->win, 70, 250, 0x00000000, "color:");
	}
	else
		print_xpm(e, "./resources/vap.xpm", 7, 225);
	print_xpm(e, "./resources/icon.xpm", 50, 840);
}

void	paint_interface_img(t_env *e)
{
	int *data;

	e->img_interface = mlx_new_image(e->mlx, e->menu_width, WIN_HEIGHT);
	if (e->img_interface == NULL)
	{
		ft_putendl_fd("mlx malloc error", 2);
		exit(1);
	}
	data = (int *)mlx_get_data_addr(e->img_interface,
	&(e->bbp), &(e->size_line), &(e->endian));
	e->data = data;
	e->image_width = e->menu_width;
	e->image_height = WIN_HEIGHT;
	add_square_data_no_border(e, 0, 0, 0x55cccccc);
	e->image_height = 50;
	e->image_width = 150;
	add_square_data(e, 25, 85, 0x00aaaaaa);
	paint_interface_struct(e);
	paint_colors_interface(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_interface, 0, 0);
	mlx_destroy_image(e->mlx, e->img_interface);
	paint_strings_interface(e);
}
