#include "../../../include/minishell.h"

bool	has_syntax_error(t_token *list)
{
	t_token	*tmp = list;

	while (tmp)
	{
		if (tmp->type == TOKEN_PIPE && tmp->next && tmp->next->type == TOKEN_PIPE)
		{
			errmsg("syntax error near unexpected token", "|", true);
			return (true);
		}
		if (tmp->type >= TOKEN_REDIRECT_IN
			&& tmp->next && tmp->next->type >= TOKEN_REDIRECT_IN)
		{
			errmsg("syntax error near unexpected token", tmp->next->value, true);
			return (true);
		}
		tmp = tmp->next;
	}
	return (false);
}
