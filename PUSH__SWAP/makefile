NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c \
	  src/move.c \
	  src/sort.c \
	  src/utils.c \
	  src/validate_arguments.c \
	  src/ft_atoi2.c

LIBFT = libft/ft_isdigit.c \
		libft/ft_memmove.c \
		libft/ft_putendl_fd.c \
        libft/ft_split.c \
		libft/ft_strdup.c \
		libft/ft_strjoin.c \
        libft/ft_strlen.c \
		libft/ft_strncmp.c \
		libft/ft_count_words.c \
		libft/ft_strlcpy.c \

OBJS = $(SRC:.c=.o) $(LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f src/*.o libft/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
