NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
INCLUDES = -I$(MLX_DIR)

SRC_DIR = source
LIBFT_DIR = Libft

SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/image.c \
	$(SRC_DIR)/image2.c \
	$(SRC_DIR)/map.c \
	$(SRC_DIR)/map2.c \
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

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR) # Compila a MiniLibX
	$(CC) $(CFLAGS) $(OBJS) $(MLX_DIR)/libmlx.a $(MLX_FLAGS) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

mlx:
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)

.PHONY: all clean fclean re