/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 13:47:04 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 14:42:44 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)
# define BUTTONPRESSMASK (1L<<2)
# define BUTTONRELEASEMASK (1L<<3)
# define BUTTONMOTIONMASK (1L<<13)
# define KEYPRESS 2
# define KERYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6

void			*mlx_init();
void			*mlx_new_window(void *mlx_ptr, int size_x,
				int size_y, char *title);
int				mlx_clear_window(void *mlx_ptr, void *win_ptr);
int				mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x,
				int y, int color);
void			*mlx_new_image(void *mlx_ptr, int width, int height);
char			*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
		int *size_line, int *endian);
int				mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
				void *img_ptr,
		int x, int y);
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);
int				mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(),
				void *param);
int				mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_expose_hook (void *win_ptr, int (*funct_ptr)(),
				void *param);
int				mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(),
				void *param);
int				mlx_loop (void *mlx_ptr);
int				mlx_string_put(void *mlx_ptr, void *win_ptr, int x,
		int y, int color, char *string);
void			*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
		int *width, int *height);
void			*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
		int *width, int *height);
int				mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int				mlx_destroy_image(void *mlx_ptr, void *img_ptr);
int				mlx_hook(void *win_ptr, int x_event, int x_mask,
		int (*funct)(), void *param);
int				mlx_do_key_autorepeatoff(void *mlx_ptr);
int				mlx_do_key_autorepeaton(void *mlx_ptr);
int				mlx_do_sync(void *mlx_ptr);
#endif
