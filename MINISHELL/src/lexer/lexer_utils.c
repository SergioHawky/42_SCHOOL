#include "../../include/minishell.h"

int	is_redirect(char c)
{
	return (c == '<' || c == '>');
}

int	set_status(int status, const char *str, int i)
{
	if (str[i] == '\'' && status == DEFAULT)
		return (SQUOTE);
	else if (str[i] == '"' && status == DEFAULT)
		return (DQUOTE);
	else if (str[i] == '\'' && status == SQUOTE)
		return (DEFAULT);
	else if (str[i] == '"' && status == DQUOTE)
		return (DEFAULT);
	return (status);
}

int	skip_spaces(const char *str, int i)
{
	while (str[i] && ft_is_space(str[i]))
		i++;
	return (i);
}
