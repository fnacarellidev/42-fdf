NAME = libgnl.a

GREEN = \033[0;32m
RESET = \033[0m
FLAGS = -Wall -Wextra -Werror -g
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "$(GREEN)GNL lib created$(RESET)"
	@ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	@cc $(FLAGS) -I ./ -c $(SRCS)

clean :
	@rm -f $(OBJS)
	@echo "$(GREEN)GNL Objects removed successfully!$(RESET)"

fclean :
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@echo "$(GREEN)Everything related to GNL was removed successfully!$(RESET)"

re : fclean all
