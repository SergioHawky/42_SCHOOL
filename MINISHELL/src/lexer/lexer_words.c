#include "../../include/minishell.h"

int	extract_word(t_token **tokens, const char *input, int start)
{
	int	i = start;

	while (input[i] && !ft_is_space(input[i])
		&& input[i] != '|' && input[i] != '<' && input[i] != '>')
		i++;
	add_token(tokens, ft_strndup(input + start, i - start), TOKEN_WORD);
	return (i);
}
