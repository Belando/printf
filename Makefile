NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

clean: 
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re