NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux

# Bibliotecas necessárias
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
INCLUDES = -I$(MLX_DIR)

# Arquivos do projeto
SRCS = main.c image.c map.c movement.c spawn.c animation.c free.c update.c player_border.c exit.c HUD.c error.c Libft/ft_strdup.c Libft/ft_strlen.c Libft/ft_itoa.c

OBJS = $(SRCS:.c=.o)

# Regra principal (compilação do programa)
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
