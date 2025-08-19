NAME = minishell

SRCS =	main.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	make -C ./libft && make bonus -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L ./libft -lft -lreadline -I.brew/opt/readline/include -L/opt/vagrant/embedded/lib -lreadline

clean:
	cd libft && make fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
