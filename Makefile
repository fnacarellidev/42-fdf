# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 18:36:24 by fnacarel          #+#    #+#              #
#    Updated: 2022/12/01 19:13:33 by fnacarel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fdf
LIBFDF = libfdf.a
SRCS = bresenham.c fdf_utils00.c window_keyhook.c fdf_set_map.c connect_axis.c \
	   isometric_projection.c input_validation.c \
	   drawing_first_steps.c move_map.c zoom.c
SRCPATH = $(addprefix src/, $(SRCS))
OBJS = $(patsubst %.c, %.o, $(SRCS))
LIBFT_PATH = ./libs/libft
GNL_PATH = ./libs/get_next_line
MLX_PATH = ./libs/mlx
INCLUDES = -I $(LIBFT_PATH) -I $(MLX_PATH) -I $(GNL_PATH)
PATH_LIBS = -L$(LIBFT_PATH) -L$(MLX_PATH) -L$(GNL_PATH)
LIBS = -lgnl -lft -lmlx -lmlx_Linux -lX11 -lXext -Imlx -lXext -lm
FLAGS = -Wall -Wextra -Werror -g3

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIBFT_PATH) --no-print-directory
	@make -C $(GNL_PATH) --no-print-directory
	@make -C $(MLX_PATH) --no-print-directory
	@ar rcs $(LIBFDF) $(OBJS)
	@cc $(FLAGS) $(OBJS) -o $(NAME) src/main.c $(PATH_LIBS) $(LIBS)
	@rm $(OBJS) $(LIBFDF)

$(OBJS) :
	@cc $(FLAGS) -I ./include -c $(SRCPATH)

clean :
	@rm -f $(OBJS) $(LIBFDF)
	@make clean -C $(LIBFT_PATH) --no-print-directory
	@make clean -C $(GNL_PATH) --no-print-directory
	@make clean -C $(MLX_PATH) --no-print-directory

fclean : clean
	@rm -f $(NAME) $(LIBFDF)
	@make fclean -C $(LIBFT_PATH) --no-print-directory
	@make fclean -C $(GNL_PATH) --no-print-directory
	@make fclean -C $(MLX_PATH) --no-print-directory

re : fclean all

.PHONY : all clean fclean re
