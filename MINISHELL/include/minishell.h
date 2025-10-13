#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <ctype.h>
# include <sys/wait.h>
# include "../Libft/libft.h"
# include "../ft_printf/ft_printf.h" 


/*=============================*/
/*         ENUMS               */
/*=============================*/

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_STRING,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_END
}	t_token_type;

typedef enum e_status
{
	DEFAULT,
	SQUOTE,
	DQUOTE
}	t_status;

/*=============================*/
/*         STRUCTS             */
/*=============================*/

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	t_status		status;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_data
{
	char		*user_input;
	t_token		*token;
	char		**env;
}	t_data;

/*=============================*/
/*         PROTOTYPES          */
/*=============================*/

/* lexer */
t_token	*tokenize(const char *input);
int		set_status(int status, const char *str, int i);
int		is_redirect(char c);
int		extract_word(t_token **tokens, const char *input, int start);
int		extract_quoted(t_token **tokens, const char *input, int start);
int		handle_redirects(t_token **tokens, const char *input, int i);
int		skip_spaces(const char *str, int i);

/* tokens */
void	add_token(t_token **tokens, const char *value, t_token_type type);
t_token	*new_token(const char *value, t_token_type type);
void	free_tokens(t_token *list);
bool	has_syntax_error(t_token *list);

/* parser */
bool	parse_user_input(t_data *data);

/* utils */
int		ft_is_space(char c);
int		ft_strcmp(const char *s1, const char *s2);
void	errmsg(const char *msg, const char *arg, bool newline);

#endif
