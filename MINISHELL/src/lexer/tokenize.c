#include "../../include/minishell.h"

t_token	*tokenize(const char *input)
{
	int			i = 0;
	int			status = DEFAULT;
	t_token		*tokens = NULL;

	while (input[i])
	{
		status = set_status(status, input, i);
		i = skip_spaces(input, i);
		if (input[i] == '\0')
			break ;
		if (status == DEFAULT && input[i] == '|')
			add_token(&tokens, "|", TOKEN_PIPE), i++;
		else if (status == DEFAULT && is_redirect(input[i]))
			i = handle_redirects(&tokens, input, i);
		else if (input[i] == '\'' || input[i] == '"')
			i = extract_quoted(&tokens, input, i);
		else
			i = extract_word(&tokens, input, i);
	}
	add_token(&tokens, "END", TOKEN_END);
	return (tokens);
}
