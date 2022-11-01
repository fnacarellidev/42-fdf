# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 18:36:24 by fnacarel          #+#    #+#              #
#    Updated: 2022/11/01 19:59:29 by fnacarel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fdf

SRCS = main.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
LIBFT_PATH = ./libs/libft
FT_PRINTF_PATH = ./libs/ft_printf
MLX_PATH = ./libs/mlx
INCLUDES = -I $(LIBFT_PATH) -I $(FT_PRINTF_PATH) -I $(MLX_PATH)
PATH_LIBS = -L$(LIBFT_PATH) -L$(FT_PRINTF_PATH) -L$(MLX_PATH)
LIBS = -lft -lftprintf -lmlx -lmlx_Linux -lX11 -lXext -Imlx -lXext 
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIBFT_PATH) --no-print-directory
	@make -C $(FT_PRINTF_PATH) --no-print-directory
	@make -C $(MLX_PATH) --no-print-directory
	@cc $(FLAGS) $(OBJS) -o $(NAME) $(PATH_LIBS) $(LIBS)

$(OBJS) :
	@cc -c -o $(OBJS) $(SRCS)

clean :
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_PATH) --no-print-directory
	@make clean -C $(FT_PRINTF_PATH) --no-print-directory
	@make clean -C $(MLX_PATH) --no-print-directory

fclean : clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH) --no-print-directory
	@make fclean -C $(FT_PRINTF_PATH) --no-print-directory
	@make fclean -C $(MLX_PATH) --no-print-directory

re : fclean all

.PHONY : all clean fclean re
