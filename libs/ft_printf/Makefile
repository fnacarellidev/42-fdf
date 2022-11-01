NAME = libftprintf.a
GREEN = \033[0;32m
RESET = \033[0m
YELLOW = \033[0;33m

FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)Printf library created successfully!$(RESET)"

$(OBJS) : $(SRCS)
	@echo "$(YELLOW)Creating Printf library ...$(RESET)"
	@cc $(FLAGS) -c -I . $(SRCS)

clean :
	@rm -f $(OBJS)
	@echo "$(GREEN)Printf objects removed successfully!$(RESET)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(GREEN)Everything related to Printf removed successfully!$(RESET)"

re : fclean all

.PHONY : all clean fclean re
