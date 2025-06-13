# Executáveis
NAME = server
CLIENT = client

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Headers (adicione se necessário)
HEADERS = 

# Fontes
SRC_SERVER = server.c libft/ft_atoi.c libft/ft_print_format1.c libft/ft_print_format2.c libft/ft_printf.c
SRC_CLIENT = client.c libft/ft_atoi.c libft/ft_print_format1.c libft/ft_print_format2.c libft/ft_printf.c

# Objetos
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

# Regra padrão
all: $(NAME) $(CLIENT)

# Regras de build
$(NAME): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^

# Bônus
SRC_SERVER_BONUS = server_bonus.c utils.c
SRC_CLIENT_BONUS = client_bonus.c utils.c

OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

bonus: server_bonus client_bonus

server_bonus: $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

client_bonus: $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

# Limpeza
clean:
	rm -f *.o libft/*.o

fclean: clean
	rm -f $(NAME) $(CLIENT) client_bonus server_bonus

re: fclean all

.PHONY: all bonus clean fclean re
