# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 18:36:24 by fnacarel          #+#    #+#              #
#    Updated: 2022/11/16 20:19:04 by fnacarel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fdf
LIBFDF = libfdf.a

SRCS = bresenham.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
LIBFT_PATH = ./libs/libft
GNL_PATH = ./libs/get_next_line
MLX_PATH = ./libs/mlx
INCLUDES = -I $(LIBFT_PATH) -I $(MLX_PATH) -I $(GNL_PATH)
PATH_LIBS = -L$(LIBFT_PATH) -L$(MLX_PATH) -L$(GNL_PATH)
LIBS = -lgnl -lft -lmlx -lmlx_Linux -lX11 -lXext -Imlx -lXext 
FLAGS = -Wall -Wextra -Werror -g3

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIBFT_PATH) --no-print-directory
	@make -C $(GNL_PATH) --no-print-directory
	@make -C $(MLX_PATH) --no-print-directory
	@ar rcs $(LIBFDF) $(OBJS)
	@cc $(FLAGS) $(OBJS) -o $(NAME) main.c $(PATH_LIBS) $(LIBS)

$(OBJS) :
	@cc -c -o $(OBJS) $(SRCS)

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
