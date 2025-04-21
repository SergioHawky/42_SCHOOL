NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux

# Bibliotecas necessárias
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
INCLUDES = -I$(MLX_DIR)

# Diretórios
SRC_DIR = source
LIBFT_DIR = Libft

# Arquivos do projeto
SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/image.c \
	$(SRC_DIR)/map.c \
	$(SRC_DIR)/movement.c \
	$(SRC_DIR)/spawn.c \
	$(SRC_DIR)/animation.c \
	$(SRC_DIR)/free.c \
	$(SRC_DIR)/update.c \
	$(SRC_DIR)/player_border.c \
	$(SRC_DIR)/exit.c \
	$(SRC_DIR)/HUD.c \
	$(SRC_DIR)/error.c \
	$(SRC_DIR)/gravity.c \
	$(SRC_DIR)/enemy/enemies.c \
	$(LIBFT_DIR)/ft_strdup.c \
	$(LIBFT_DIR)/ft_strlen.c \
	$(LIBFT_DIR)/ft_itoa.c

OBJS = $(SRCS:.c=.o)

# Regra principal
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR) # Compila a MiniLibX
	$(CC) $(CFLAGS) $(OBJS) $(MLX_DIR)/libmlx.a $(MLX_FLAGS) $(INCLUDES) -o $(NAME)

# Compila arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Limpa arquivos compilados
clean:
	rm -f $(OBJS)

# Limpa tudo, incluindo o binário final
fclean: clean
	rm -f $(NAME)

# Recompila tudo do zero
re: fclean all
