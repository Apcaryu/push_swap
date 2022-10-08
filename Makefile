CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c swap.c utils.c
OBJS = $(SRCS:.c=.o)
NAME = push_sawp
T_SRCS = test.c test_instruction_set.c $(SRCS)
T_OBJS = $(T_SRCS:.c=.o)
T_NAME = t_push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

%.o : %.c
	$(CC) -c $^

clean :
	rm -f $(OBJS)
	rm -f $(T_OBJS)

fclean : clean
	rm -f $(NAME)
	rm -f $(T_NAME)

re : fclean all

debug : $(T_OBJS)
	make -C libft
	$(CC) -D IS_TEST=1 $(T_OBJS) libft/libft.a -o $(T_NAME)