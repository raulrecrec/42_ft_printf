NAME	= ft_printf.a
TEST    = test_program

RM		= rm -f

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SRCS	=					\
		ft_printf.c 		\
		ft_format.c			\
		ft_numlen.c			\
		ft_putlnbr.c		\
		ft_putlstr.c		\
		ft_putlchar.c		\

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

$(TEST): all main.c
	$(CC) $(CFLAGS) main.c -o $(TEST) $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean all fclean re