NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g 
LIBFT_DIR = libft
LIBFT = ./libft/libft.a
RM = rm -rf
SRCS = utils.c move.c sort.c main.c
SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/,$(SRCS))
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)
	@echo "Done!"
	@echo "To test the program, run 'make test' or 'make test size=10'"
	@echo "Example: ./push_swap 1 2 3 4 5 6 7 8 9 10"

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft

# Compilação dos .o um a um
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:	
	@$(RM) $(OBJ)
	@make -s -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean test re

# Teste (sem mudanças aqui)
OS = $(shell uname)
size ?= 10

ifeq ($(OS),Linux)
CHECKER = valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)
else
CHECKER = ./push_swap $(ARG) | ./checker_Mac $(ARG)
endif

test:
	@$(eval ARG = $(shell seq -1000 1000 | shuf -n $(size)))
	@echo "Checker result: "
	$(CHECKER)
	@echo "Instructions count: "
	@./push_swap $(ARG) | wc -l
