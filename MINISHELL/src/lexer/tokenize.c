#include "../../include/minishell.h"

t_token	*tokenize(const char *input)
{
	int			i = 0;
	int			status = DEFAULT;
	t_token		*tokens = NULL;
	int			next;

	while (input[i])
	{
		status = set_status(status, input, i);
		i = skip_spaces(input, i);
		if (input[i] == '\0')
			break ;
		if (status == DEFAULT && input[i] == '|')
			add_token(&tokens, "|", PIPE), i++;
		else if (status == DEFAULT && is_redirect(input[i]))
			i = handle_redirects(&tokens, input, i);
		else if (input[i] == '\'' || input[i] == '"')
		{
			next = extract_quoted(&tokens, input, i);
			if (next == -1)
    		{
        		free_tokens(tokens);
       			return (NULL);
    		}
    		i = next;
		}
		else
			i = extract_word(&tokens, input, i);
	}
	add_token(&tokens, "END", END);
	return (tokens);
}
