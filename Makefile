# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldedier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 18:20:16 by ldedier           #+#    #+#              #
#    Updated: 2017/11/26 16:23:53 by ldedier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
CC      = gcc
CFLAGS   = -Wall -Wextra -Werror

SRCDIR   = srcs
OBJDIR   = srcs
BINDIR   = .

OK_COLOR = \x1b[32;01m

SOURCES  =	$(SRCDIR)/bresenham.c $(SRCDIR)/fdf_colors_height.c\
			$(SRCDIR)/fdf_colors.c $(SRCDIR)/fdf_draw.c\
			$(SRCDIR)/fdf_init.c $(SRCDIR)/fdf_key_events.c\
			$(SRCDIR)/fdf_motion_events.c $(SRCDIR)/fdf_mouse_events.c\
			$(SRCDIR)/fdf_oblique.c $(SRCDIR)/fdf_oblique_param.c\
		   	$(SRCDIR)/fdf_paint_interface.c $(SRCDIR)/fdf_paint_utils.c\
		   	$(SRCDIR)/fdf_param_axo.c $(SRCDIR)/fdf_reader.c\
			$(SRCDIR)/fdf_reader_utils.c $(SRCDIR)/fdf_repaint.c\
			$(SRCDIR)/fdf_utils.c $(SRCDIR)/main.c\

INCLUDES = $(SRCDIR)/mlx.h $(SRCDIR)/fdf.h

OBJECTS  = $(SOURCES:%.c=%.o)
rm = rm -f

all: $(BINDIR)/$(NAME)

macbook:
	make all
	
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES)
	$(CC) -c $< -o $@ $(CFLAGS) 

$(BINDIR)/$(NAME): $(OBJECTS)
	@make -C libft
	@$(CC) -o $@ $^ $(CFLAGS) -L libft -lft -L minilibx_macos -lmlx -framework OpenGL -framework Appkit
	@echo "$(OK_COLOR)$(NAME) linked with success !"
clean:
	@make clean -C libft
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C libft
	@rm -f $(BINDIR)/$(NAME)

re: fclean all

.PHONY: all clean fclean re
