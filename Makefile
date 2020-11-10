# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndaniell <ndaniell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/27 15:07:29 by ndaniell          #+#    #+#              #
#    Updated: 2020/02/09 15:42:52 by ndaniell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRC		= main.c controls.c fractal.c init.c mandelbrot.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g

MINI		= ./minilibx_macos/
MINI_LIB	= $(addprefix $(MINI),libmlx.a)
MINI_INC	= -I ./minilibx_macos
MINI_LNK	= -L ./minilibx_macos -l mlx -lpthread -framework OpenGL -framework AppKit

# ft library
LIBFT		= ./libft/
LIBFT_LIB	= $(addprefix $(FT),libft.a)
LIBFT_INC	= -I ./libft
LIBFT_LNK	= -L ./libft -l ft

# directories
SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj $(LIBFT_LIB) $(MINI_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(FLAGS) -O2 $(MINI_INC) $(LIBFT_INC) -I $(INCDIR) -o $@ -c $<

$(LIBFT_LIB):
	make -C $(LIBFT)

$(MINI_LIB):
	make -C $(MINI)

$(NAME): $(OBJ)
	$(CC) -g $(OBJ) $(MINI_LNK) $(LIBFT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFT) clean
	make -C $(MINI) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re