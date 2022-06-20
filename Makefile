# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:22:54 by hoomen            #+#    #+#              #
#    Updated: 2022/06/20 13:45:09 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compiler variables
CC		=	gcc
FLAGS 	=	-Wall -Wextra -Werror
# file variables
NAME			= fractol
BONUSNAME		=	
# source files
MAIN			= fractol
UTILS			= init color
LIBFT			=
FT_PRINTF		=
GNL				=
# add prefix and suffix to filenames
MAINSRC			=	$(addprefix src/, $(addsuffix .c, $(MAIN)))
UTILSSRC		=	$(addprefix src/, $(addsuffix .c, $(UTILS)))
BONUSSRC		=	
LIBFTSRC		=	$(addprefix libft/ft_,$(addsuffix .c, $(LIBFT)))
FT_PRINTFSRC	=	$(addprefix ft_printf/ft_, $(addsuffix .c, $(FT_PRINTF)))
GNLSRC			=	$(addprefix get_next_line/, $(addsuffix .c, $(GNL)))

# object files
OBJ				=	$(MAINSRC:.c=.o)
UTILSOBJS		=	$(UTILSSRC:.c=.o)
LIBFTOBJS		=	$(LIBFTSRC:.c=.o)
FT_PRINTFOBJS 	=	$(FT_PRINTFSRC:.c=.o)
GNLOBJS			=	$(GNLSRC:.c=.o)
BONUSOBJS		=	$(BONUSSRC:.c=.o)


all : $(NAME)

$(NAME): $(OBJ) $(UTILSOBJS)
	@$(CC) $(OBJ) $(UTILSOBJS) -lm -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "fractol is compiled"

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	@rm -f *.o
	@rm -f */*.o

bonus:

script: $(SCRIPTOBJ) $(FT_PRINTFOBJS) $(GNLOBJS) $(LIBFTOBJS)
	@$(CC) $(FLAGS) $(SCRIPTOBJ) $(FT_PRINTFOBJS) $(GNLOBJS) $(LIBFTOBJS)

fclean: clean
	rm -f $(NAME) $(BONUSNAME)

re: fclean all

.PHONY: all clean fclean re bonus
