NAME = libft.a

GREEN = \033[0;32m
RESET = \033[0m
YELLOW = \033[0;33m

CFLAGS = -Wall -Wextra -Werror -g
CFILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		 ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memmove.c \
		 ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		 ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		 ft_strnstr.c ft_calloc.c ft_strdup.c ft_atoi.c ft_putchar_fd.c \
		 ft_putstr_fd.c ft_putendl_fd.c ft_substr.c ft_strjoin.c ft_striteri.c \
		 ft_strmapi.c ft_itoa.c ft_putnbr_fd.c  ft_strtrim.c ft_split.c \
		 ft_putstr.c ft_putchar.c ft_putnbr_base.c ft_strtohex.c ft_printf.c \
		 ft_printf_utils.c

OBJS = $(patsubst %.c, %.o, $(CFILES))

BONUS_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJ = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o \
			ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o


all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJS) : $(CFILES)
	@echo "$(YELLOW)Creating Libft library...$(RESET)"
	@cc $(CFLAGS) -I ./ -c $(CFILES)
	@echo "$(GREEN)Libft library created!$(RESET)"

$(BONUS_OBJ) :
	@cc $(CFLAGS) -I ./ -c $(BONUS_FILES)
	@ar rcs $(NAME) $(BONUS_OBJ)

bonus : $(BONUS_OBJ)

clean :
	@rm -f $(OBJS) $(BONUS_OBJ)
	@echo "$(GREEN)Libft objects removed successfully !$(RESET)"

fclean : 
	@rm -f $(NAME)
	@rm -f $(OBJS) $(BONUS_OBJ)
	@echo "$(GREEN)Everything related to Libft removed successfully !$(RESET)"

re : fclean all

.PHONY : all clean fclean re
