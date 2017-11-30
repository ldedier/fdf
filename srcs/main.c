/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:21:57 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 13:50:36 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_errors(int error)
{
	if (error == -1)
		ft_putendl_fd("File cannot be found or opened.", 2);
	if (error == 0 || error == 1)
		ft_putendl_fd("An error occured.", 2);
	if (error == 2)
		ft_putendl_fd("Invalid text file.", 2);
}

int		treat_errors(int argc, char **argv, t_parser **parser)
{
	int error;

	error = 0;
	if (argc != 2)
	{
		ft_putendl("This program takes one single argument.");
		return (0);
	}
	*parser = new_parser(argv[1], &error);
	if (*parser == NULL)
	{
		put_errors(error);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_env		e;
	t_parser	*parser;

	parser = NULL;
	if (treat_errors(argc, argv, &parser) == 0)
		return (0);
	else
	{
		e.parser = parser;
		init_env(&e);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, argv[1]);
		mlx_key_hook(e.win, key_hook, &e);
		mlx_mouse_hook(e.win, mouse_event_funct, &e);
		mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, &funct_key_pressed, &e);
		mlx_hook(e.win, MOTIONNOTIFY, BUTTONMOTIONMASK, &funct_motion, &e);
		mlx_hook(e.win, BUTTONRELEASE, BUTTONRELEASEMASK,
		&funct_mouse_released, &e);
		init_params(&e);
		repaint(&e);
		mlx_loop(e.mlx);
	}
	return (0);
}
