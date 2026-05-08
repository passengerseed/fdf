# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/08 14:29:59 by lrouchon          #+#    #+#              #
#    Updated: 2026/05/08 17:56:55 by lrouchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

LFLAGS = -L -lmlx -lXext -lX11

NAME = fdf

SRC_PATH = src/
SRC = $(SRC_PATH)fdf.c \
	$(SRC_PATH)parser.c \
	$(SRC_PATH)draw_1.c \
	$(SRC_PATH)draw_2.c \
	$(SRC_PATH)init.c \
	$(SRC_PATH)events.c \
	$(SRC_PATH)map_utils.c

LIBS = libft/libft.a \
		minilibx-linux/libmlx_Linux.a

INCLUDES = $(SRC_PATH)fdf.h

OBJ = $(SRC:.c=.o)

all: libs $(NAME)

libs :
	make -C libft/

$(NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) $(LIBS) -o $(NAME) -lm

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
