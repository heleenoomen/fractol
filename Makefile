# compiler variables
CC		=	gcc
FLAGS 	=	-Wall -Wextra -Werror
# file variables
NAME			= fractol
BONUSNAME		=	
# source files
MAIN			= main
UTILS			= init events fractals color zoom hsv2rgb
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
	$(CC) $(OBJ) $(UTILSOBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "fractol is compiled"

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	@rm -f *.o
	@rm -f */*.o

bonus:

fclean: clean
	rm -f $(NAME) $(BONUSNAME)

re: fclean all

.PHONY: all clean fclean re bonus