# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 15:21:59 by tkitahar          #+#    #+#              #
#    Updated: 2024/09/26 16:11:25 by tkitahar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fractol

LIBFT	:= libft/libft.a
MLX		:= mlx/libmlx_Linux.a

SRC_DIR	:= src
OBJ_DIR	:= obj

CC		:= cc
CLAG	:= -Wall -Wextra -Werror
INC 	:= -I inc -I ibft/includes -I mlx
MLXFLAG	:= -Llibft -Lmlx -lmlx -lft -Imlx -lXext -lX11 -lm -Ofast
RM		:= rm -rf

SRC		:= src/render.c src/main.c src/math_utils.c src/init.c src/my_mlx.c src/events.c
OBJ		:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(OBJ) $(CFLAG) $(INC) $(MLXFLAG) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAG) -c -o $@ $<

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx

clean:
	make -C libft clean
	make -C mlx clean
	$(RM) $(OBJ_DIR)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
