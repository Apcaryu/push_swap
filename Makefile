CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c swap.c utils.c
OBJS = $(SRCS:.c=.o)
NAME = push_sawp

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft/
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) -c $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

debug : $(OBJS)
	make -C libft/
	$(CC) $(OBJS) -o $(NAME)