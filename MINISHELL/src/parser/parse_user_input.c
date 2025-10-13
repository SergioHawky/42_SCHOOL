#include "../../include/minishell.h"

bool	parse_user_input(t_data *data)
{
	if (!data->user_input || ft_strcmp(data->user_input, "") == 0)
		return (false);

	add_history(data->user_input);
	data->token = tokenize(data->user_input);
	if (!data->token)
		return (false);
	if (has_syntax_error(data->token))
	{
		free_tokens(data->token);
		return (false);
	}
	return (true);
}
