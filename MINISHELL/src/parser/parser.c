#include "../../include/minishell.h"

t_cmd *parser(t_token *tokens)
{
    t_cmd *head = NULL;
    t_cmd *current = NULL;
    t_token *tk = tokens;

    while (tk && tk->type != END)
    {
        if (!current)
        {
            current = calloc(1, sizeof(t_cmd));
            if (!current)
                return (NULL);
            if (!head)
                head = current;
        }

        if (tk->type == WORD)
            parse_word(current, &tk);
        else if (tk->type == PIPE)
            current = parse_pipe(current, &tk);
        else if (tk->type == INPUT || tk->type == TRUNC ||
                 tk->type == APPEND || tk->type == HEREDOC)
            parse_redirect(current, &tk);
        else
            tk = tk->next;
    }

    return (head);
}
