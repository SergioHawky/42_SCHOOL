#include "../../include/minishell.h"

void parse_redirect(t_cmd *cmd, t_token **tk)
{
    if (!(*tk)->next)
        return;
    char *filename = (*tk)->next->value;

    if ((*tk)->type == INPUT)
    {
         if (cmd->io.fd_in > 0)
            close(cmd->io.fd_in);
        free(cmd->io.infile);
        cmd->io.infile = ft_strdup(filename);
        cmd->io.fd_in = open(filename, O_RDONLY);
    }
    else if ((*tk)->type == TRUNC)
    {
         if (cmd->io.fd_out > 0)
            close(cmd->io.fd_out);
        free(cmd->io.outfile);
        cmd->io.outfile = ft_strdup(filename);
        cmd->io.fd_out = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    }
    else if ((*tk)->type == APPEND)
    {
        if (cmd->io.fd_out > 0)
            close(cmd->io.fd_out);
        free(cmd->io.outfile);
        cmd->io.outfile = ft_strdup(filename);
        cmd->io.fd_out = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
        cmd->io.append = true;
    }
    // HEREDOC será tratado mais tarde

    *tk = (*tk)->next->next;
}
