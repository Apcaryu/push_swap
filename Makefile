CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c swap.c utils.c init.c checker_args.c push.c rotate.c \
		better_sequence.c all_in_b.c all_in_a.c final_rotate.c \
		numbers_moves.c
OBJS = $(SRCS:.c=.o)
NAME = push_sawp
T_SRCS = test.c test_instruction_set.c $(SRCS)
T_OBJS = $(T_SRCS:.c=.o)
T_NAME = t_push_swap

all : $(NAME) thanks

$(NAME) : $(OBJS)
	make -C libft bonus
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
	make -C libft clean

%.o : %.c
	$(CC) -c $^

clean :
	rm -f $(OBJS)
	rm -f $(T_OBJS)

fclean : clean
	rm -f $(NAME)
	rm -f $(T_NAME)
	make -C libft fclean

re : fclean all

debug : $(T_NAME) thanks

$(T_NAME) : fclean $(T_OBJS)
	make -C libft
	$(CC) -D IS_TEST=1 $(T_OBJS) libft/libft.a -o $(T_NAME)

thanks :
	@echo "\033[40m\033[37m\e[1mThanks to:\033[0m"
	@echo "\033[36mpgros aka Perrine"
	@echo "\033[36mmaitre de l'evasion sleleu aka Sebastien\033[0m"