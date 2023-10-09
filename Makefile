NAME = libft.a
CC = gcc
CFLAGS = 

SRCS_B = 

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

bonus: $(NAME) $(OBJS_B)
	$(AR) rcs $(NAME) $(OBJS_B)

clean: 
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re