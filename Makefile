# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 12:38:38 by hoomen            #+#    #+#              #
#    Updated: 2022/06/29 16:03:17 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH	= src
INCFLAGS = -I libft -I ftprintf -I mlx

CC		= cc
FLAGS	= -Wall -Werror -Wextra
NAME	= fractol
HEADER	= fractol_def.h
SRC		= main.c parse.c
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

.PHONY : all clean fclean re

