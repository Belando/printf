NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs
RM = rm -f
LIBFT = -C libft
SRC = ft_printf.c ft_parser1.c ft_parser2.c
OBJ = $(SRC:.c=.o)
all:        $(NAME)
$(NAME):    libft $(OBJ)
	cp ./libft/libft.a $(NAME)
	$(LIB) $(NAME) $(OBJ)
clean:      fclean_libft
	$(RM) *.o
fclean:     fclean_libft clean
	$(RM) $(NAME)
libft:
	make $(LIBFT)
clean_libft:
	make clean $(LIBFT)
fclean_libft:
	make fclean $(LIBFT)
re:         fclean all
.PHONY:     all clean fclean re libft