# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 15:21:59 by tkitahar          #+#    #+#              #
#    Updated: 2024/09/24 15:24:00 by tkitahar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fractol

LIBFT	:= libft/libft.a
MLX		:= mlx/libmlx_Linux.a

SRC_DIR	:= src
OBJ_DIR	:= obj

CC		:= cc
CFLAG	:= -Wall -Wextra -Werror -I./inc/ -I./libft/includes/ -I./mlx/
MLXFLAG	:= -Lmlx -lmlx -lXext -lX11 -lm -O3
RM		:= rm -rf

SRC		:= src/render.c src/main.c src/utils.c src/init.c
OBJ		:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAG) $(MLXFLAG) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAG) -c -o $@ $<

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx
	cp $(MLX) .

clean:
	make -C libft clean
	make -C mlx clean
	$(RM) $(OBJ_DIR)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME) libmlx_Linux.a

re: fclean all

.PHONY: all clean fclean re
