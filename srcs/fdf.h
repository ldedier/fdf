/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:22:38 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 16:04:55 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "../libft/libft.h"
# define WIN_WIDTH 1200
# define WIN_HEIGHT 1000
# define PROJ_AXO 1
# define PROJ_OBLIQUE 2
# define TETA M_PI / 64
# define STANDARD 0
# define VAPORWAVE 1

typedef struct	s_parser
{
	int			**tab;
	double		length;
	double		height;
	int			max_value;
	int			min_value;
	double		depth;
}				t_parser;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			z1;
	int			z2;
	int			proj;
	int			style;
	int			fill;
	double		teta;
	double		omega;
	double		alpha;
	double		alpha_ob;
	int			x_margin;
	int			y_margin;
	double		scale;
	double		depth_adder;
	int			width;
	int			height;
	void		*img;
	int			menu_width;
	int			size_line;
	int			endian;
	int			bbp;
	int			image_width;
	int			image_height;
	int			image_x;
	int			image_y;
	int			tab_t[3];
	int			tab_m[3];
	int			tab_b[3];
	void		*img_figure;
	void		*img_interface;
	int			*data;
	int			has_grab;
	int			*val_grabbed;
	int			has_grabbed_figure;
	int			x_figure_grab;
	int			y_figure_grab;
	int			has_grab_alt_fig;
	int			dx;
	int			dy;
	int			er;
	int			incx;
	int			incy;
	int			inc1;
	int			inc2;
	t_parser	*parser;
}				t_env;

t_parser		*new_parser(char *filename, int *error);
void			affich_parser(t_parser *parser);
int				get_color(int r, int g, int b);
int				get_standard_color_x(int x, t_env *e);
int				get_standard_color_y(int y, t_env *e);
int				get_vapor_printed_x(int x, t_env *e);
int				get_vapor_printed_y(int y, t_env *e);
int				abs(int a);
int				draw_segment_tierce(t_env *e, int *data);
double			max_x_axo(t_env *e);
double			max_y_axo(t_env *e);
double			min_x_axo(t_env *e);
double			min_y_axo(t_env *e);
void			paint_interface_img(t_env *e);
int				mouse_event_funct(int key, int x, int y, t_env *e);
int				funct_mouse_released(int key, int x, int y, t_env *e);
void			grab_figure(int key, int x, int y, t_env *e);
void			mouse_event_colors(int x, int y, t_env *e);
int				funct_motion(int x, int y, t_env *e);
int				min_x_oblique(t_env *e);
int				max_x_oblique(t_env *e);
int				min_y_oblique(t_env *e);
int				max_y_oblique(t_env *e);
void			draw_lines_oblique_img(int ind_x, int ind_y,
				t_env *e, int *data);
void			print_xpm(t_env *e, char *xpm, int x, int y);
void			add_square_data(t_env *e, int x, int y, int color);
int				is_on_screen_segment(t_env *e);
int				draw_segment_img(t_env *e, int *data);
void			draw_lines_axo_img(int ind_x, int ind_y, t_env *e, int *data);
void			key_pressed_axo(int keycode, t_env *e);
void			key_pressed_oblique(int keycode, t_env *e);
int				funct_key_pressed(int keycode, t_env *e);
int				key_hook(int keycode, t_env *e);
void			repaint(t_env *e);
void			paint_figure_img(t_env *e);
void			init_params(t_env *e);
void			init_env(t_env *e);
int				min(int a, int b);
int				max(int a, int b);
int				abs(int a);
void			affich_parser(t_parser *parser);
void			put_preview(t_env *e);
void			add_square_data_no_border(t_env *e, int x, int y, int color);
int				*ft_sub_tab(t_parser *res, char **split);
int				nb_words(char *line);

#endif
