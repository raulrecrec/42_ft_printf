NAME	= ft_printf.a
TEST    = test_program

RM		= rm -f

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SRCS	=					\
		ft_printf.c 		\
		ft_format.c			\
		ft_putchar.c		\

OBJS	= $(SRCS:.c=.o)

LIBFT		= ../42_Libft/libft.a
LIBFT_INC	= -I../42_Libft

all:	$(LIBFT) $(NAME)

$(LIBFT):
		$(MAKE) -C ../42_Libft

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

$(TEST): all main.c
	$(CC) $(CFLAGS) $(LIBFT_INC) main.c -o $(TEST) $(NAME) $(LIBFT)

%.o: %.c
		$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

clean:
		$(RM) $(OBJS)
		$(MAKE) -C ../42_Libft clean

fclean: clean
		$(RM) $(NAME)
		$(MAKE) -C ../42_Libft fclean

re: fclean all

.PHONY: clean all fclean re

