#include "../../include/minishell.h"

int	extract_quoted(t_token **tokens, const char *input, int start)
{
	char	quote = input[start];
	int		i = start + 1;

	while (input[i] && input[i] != quote)
		i++;
	if (!input[i])
	{
		errmsg("minishell: unclosed quote", NULL, false);
		free_tokens(*tokens);
		return (-1);
	}
	add_token(tokens, ft_strndup(input + start + 1, i - start - 1), TOKEN_STRING);
	return (i + 1);
}
