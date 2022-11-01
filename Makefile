NAME = fdf
FLAGS = -Wall -Wextra -Werror
LIBFDF = fdflib.a
SRCS = ft_printf.c ft_printf_utils.c ft_strlen.c 
OBJS = $(patsubst %.c, %.o, $(SRCS))

all : $(NAME)

$(NAME) : $(OBJS)
	cc $(FLAGS) $(NAME)

$(OBJS) : $(SRCS)
	cc $(FLAGS) -C $(SRCS)

.PHONY : all clean fclean re
