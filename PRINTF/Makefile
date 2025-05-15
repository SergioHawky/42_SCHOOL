NAME = libftprint.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c \
	ft_format.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re