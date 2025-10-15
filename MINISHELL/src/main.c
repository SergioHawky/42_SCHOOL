#include "../include/minishell.h"

static void	print_tokens(t_token *list)
{
	t_token	*tmp = list;

	printf("\n🔹 Tokens:\n");
	while (tmp)
	{
		printf("  [%d] \"%s\"\n", tmp->type, tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	data.env = envp;
	data.token = NULL;

	while (1)
	{
		data.user_input = readline("minishell> ");
		if (!data.user_input)
			break ;
		if (ft_strcmp(data.user_input, "exit") == 0)
		{
			free(data.user_input);
			break ;
		}
		if (parse_user_input(&data))
			print_tokens(data.token);
		if (data.token)
		{
			free_tokens(data.token);
			data.token = NULL;
		}
		free(data.user_input);
		data.token = NULL;
	}
	printf("👋 Exiting minishell.\n");
	return (0);
}
