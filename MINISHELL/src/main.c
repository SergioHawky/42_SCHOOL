#include "../include/minishell.h"

static void print_commands(t_cmd *cmd)
{
    int i = 1;

    printf("\n🔹 Commands parsed:\n");
    while (cmd)
    {
        printf("\nCMD #%d\n", i++);
        printf("  command: %s\n", cmd->command ? cmd->command : "(null)");
        if (cmd->args)
        {
            printf("  args: ");
            for (int j = 0; cmd->args[j]; j++)
                printf("[%s] ", cmd->args[j]);
            printf("\n");
        }
        if (cmd->io.infile)
            printf("  infile: %s\n", cmd->io.infile);
        if (cmd->io.outfile)
            printf("  outfile: %s%s\n", cmd->io.outfile, cmd->io.append ? " (append)" : "");
        if (cmd->pipe_output)
            printf("  pipes to next command\n");
        cmd = cmd->next;
    }
    printf("\n");
}

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
	t_cmd	*cmds;

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
		{
			print_tokens(data.token);
			cmds = parser(data.token);
			print_commands(cmds);
			free_commands(cmds);
		}

		if (data.token)
		{
			free_tokens(data.token);
			data.token = NULL;
		}
		free(data.user_input);
	}
	printf("Exiting minishell.\n");
	rl_clear_history(); 
	return (0);
}

