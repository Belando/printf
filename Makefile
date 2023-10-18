NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = ft_printf.c ft_parser1.c ft_parser2.c ft_utils.c
LIB = ar rcs
OBJ = $(SRC:.c=.o)
all:        $(NAME)
$(NAME):    $(OBJ)
	$(CC) -c $(CFLAGS) $(SRC)
	$(LIB) $(NAME) $(OBJ)
clean:      
	$(RM) *.o
fclean:      clean
	$(RM) $(NAME)
re:         fclean all
.PHONY:     all clean fclean re 