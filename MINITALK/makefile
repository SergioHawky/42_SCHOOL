SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_SERVER = server.c \
			 libft/ft_atoi.c \
			 libft/ft_print_format1.c \
			 libft/ft_print_format2.c \
			 libft/ft_printf.c

SRC_CLIENT = client.c \
			 libft/ft_atoi.c \
			 libft/ft_print_format1.c \
			 libft/ft_print_format2.c \
			 libft/ft_printf.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	@echo "Linkando $@..."
	@$(CC) $(CFLAGS) -o $@ $^

$(CLIENT): $(OBJ_CLIENT)
	@echo "Linkando $@..."
	@$(CC) $(CFLAGS) -o $@ $^

clean:
	@echo "Removendo arquivos .o ..."
	@rm -f *.o libft/*.o

fclean: clean
	@echo "Removendo executáveis ..."
	@rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
