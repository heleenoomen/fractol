# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 12:38:38 by hoomen            #+#    #+#              #
#    Updated: 2022/07/05 20:55:04 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH	= src
INCFLAGS = -I libft -I ftprintf -I mlx -I include

CC		= cc
FLAGS	= -Wall -Werror -Wextra

NAME	= fractol
HEADER	= include/fractol.h include/fr_userinfo.h include/keys.h
SRC		= main.c parse.c init.c fractals.c newtons_utils.c color.c hsv2rgb.c events.c view.c change_image.c print_info.c
LIBS	= libft/libft.a ftprintf/libftprintf.a
OBJ		= $(addprefix obj/,$(notdir $(SRC:.c=.o)))

$(NAME) : $(OBJ) | $(LIBS)
	$(CC) $(FLAGS) -o $@ $^ -Llibft -lft -Lftprintf -lftprintf -lm -Lmlx -lmlx -framework OpenGL -framework AppKit 

obj/%.o : %.c $(LIBS) $(HEADER) | obj
	$(CC) $(FLAGS) $(INCFLAGS) -c $< -o $@

obj :
	mkdir obj

$(LIBS) :
	-(cd libft && make)
	-(cd ftprintf && make && make clean)
	-(cd libft && make clean)

all : $(NAME)

clean :
	rm -rf obj
	
fclean : clean
	rm -f $(NAME)
	-(cd libft && make fclean)
	-(cd ftprintf && make fclean)

re : clean all

libs : fclean all

test :
	-(cd ftprintf && make)
	-(cp ftprintf/libftprintf.a .)
	$(CC) test.c -L. -lftprintf
	./a.out

.PHONY : all clean fclean re

