# ================================
#        MINISHELL MAKEFILE
# ================================

NAME        := minishell
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -Iinclude
RM          := rm -f
SRC_DIR     := src
OBJ_DIR     := obj

# ================================
#         SOURCE FILES
# ================================

SRC_FILES := \
	main.c \
	parser/parse_user_input.c \
	parser/parser_pipe.c \
	parser/parser_redirects.c \
	parser/parser_utils.c \
	parser/parser_word.c \
	parser/parser.c \
	lexer/tokenize.c \
	lexer/lexer_utils.c \
	lexer/lexer_words.c \
	lexer/lexer_redirects.c \
	lexer/lexer_quotes.c \
	lexer/tokens/tokens_list.c \
	lexer/tokens/tokens_check.c \
	utils/utils_string.c \
	utils/utils_error.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ================================
#          BUILD RULES
# ================================

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C Libft --no-print-directory
	@$(CC) $(CFLAGS) $(OBJ) -LLibft -lft -lreadline -o $(NAME)
	@echo "✅ Build complete: $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "🧹 Cleaned object files"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C Libft fclean
	@echo "🧹 Full clean done"

re: fclean all

.PHONY: all clean fclean re
