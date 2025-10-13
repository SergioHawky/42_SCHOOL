#include "../../include/minishell.h"

int	handle_redirects(t_token **tokens, const char *input, int i)
{
	if (input[i] == '>' && input[i + 1] == '>')
		return (add_token(tokens, ">>", TOKEN_APPEND), i + 2);
	if (input[i] == '>')
		return (add_token(tokens, ">", TOKEN_REDIRECT_OUT), i + 1);
	if (input[i] == '<' && input[i + 1] == '<')
		return (add_token(tokens, "<<", TOKEN_HEREDOC), i + 2);
	if (input[i] == '<')
		return (add_token(tokens, "<", TOKEN_REDIRECT_IN), i + 1);
	return (i + 1);
}
