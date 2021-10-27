# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 12:33:19 by rlinkov           #+#    #+#              #
#    Updated: 2020/11/26 17:46:55 by rlinkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC			=	gcc
RM			=	rm -rf
NAME		=	Cub3D
NAME_L		=	Cub3D_linux
CFLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-Iinclude/
LIBFT		=	-Llibft -lft
LIBFT_PATH 	=	./libft
MATH		=	-lm
MLX 		=	-Lmlx -lmlx -framework OpenGL -framework AppKit
MLX_LINUX	=	-Lmlx_linux -lmlx -I /usr/include -g -L /usr/lib -lX11 -lXext

MLX_PATH	=	./mlx
MLX_L_PATH	=	./mlx_linux

SRC_PATH	= 	./src/

GNL			= 	./gnl/get_next_line.c ./gnl/get_next_line_utils.c
GNL_L		= 	./gnl/get_next_line_l.c ./gnl/get_next_line_utils.c

PARSING		= 	parsing/check_args.c parsing/parsing_map.c\
				parsing/store_elem.c parsing/handle_map.c
				
ENGINE		=	engine/run_process.c engine/handle_event.c engine/move.c engine/camera.c\
				engine/raycasting.c engine/draw.c engine/texture.c engine/handle_sprites.c\
				engine/draw_sprite.c engine/bitmap.c

ENGINE_L	=	engine/run_process.c engine/handle_event_linux.c engine/move.c engine/camera.c\
				engine/raycasting.c engine/draw.c engine/texture_linux.c engine/handle_sprites.c\
				engine/draw_sprite.c engine/bitmap.c

UTILS		=	utils/init_cube.c utils/init_player.c utils/mlx_utils.c\

SRCS		=	$(GNL) $(PARSING) $(ENGINE) $(UTILS) cub3d.c
SRCS_L		=	$(GNL_L) $(PARSING) $(ENGINE_L) $(UTILS) cub3d.c

SRC			=	$(addprefix $(SRC_PATH), $(SRCS))
SRC_L		=	$(addprefix $(SRC_PATH), $(SRCS_L))

OBJECTS		=	$(SRC:.c=.o)
OBJECTS_L	=	$(SRC_L:.c=.o)

all: $(NAME)

%.o: %.c
	$(GCC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

$(NAME): $(OBJECTS)
	@${RM} Cub3D
	@make -C $(LIBFT_PATH)
	@make -C $(MLX_PATH)
	@cp mlx/libmlx.dylib ./
	$(GCC) $(CFLAGS) $(OBJECTS) $(INCLUDE) $(LIBFT) $(MLX) $(MATH) -o $(NAME)

linux: $(NAME_L)

$(NAME_L): $(OBJECTS_L)
	@${RM} Cub3D
	@make -C $(LIBFT_PATH)
	@make -C $(MLX_L_PATH)
	$(GCC) $(CFLAGS) $(OBJECTS_L) $(INCLUDE) $(LIBFT) $(MLX_LINUX) $(MATH) -o $(NAME)

clean:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(MLX_L_PATH)
	@${RM} $(OBJECTS) $(OBJECTS_L)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)
	$(RM) screenshot.bmp
	@$(RM) libmlx.dylib
	@$(RM) mlx/libmlx.dylib

re: fclean all

re_linux: fclean linux

start: re
	./Cub3D maps/info.cub

start_linux: re_linux
	./Cub3D maps/info.cub

start_linux_valgrind: re_linux
	valgrind --leak-check=full ./Cub3D maps/info.cub

.PHONY : libft all re re_linux start start_linux start_linux