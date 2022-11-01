NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	cc $(FLAGS) -c -I . $(SRCS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
