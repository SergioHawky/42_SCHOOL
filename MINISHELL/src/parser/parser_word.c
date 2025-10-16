#include "../../include/minishell.h"

/*
 * parse_word:
 *  - preenche cmd->command (se ainda não existir)
 *  - recolhe argumentos consecutivos do token stream (TOKEN_WORD ou TOKEN_STRING)
 *  - cria cmd->args com argv[0] = command e argv[n] = tokens..., argv[n+1] = NULL
 *
 * Note: assume que *tk aponta para um token válido.
 */
void parse_word(t_cmd *cmd, t_token **tk)
{
    int argc = 0;
    t_token *temp;

    if (!cmd || !tk || !*tk)
        return;

    /* se não existe comando, o primeiro token define o comando */
    if (!cmd->command)
    {
        cmd->command = ft_strdup((*tk)->value ? (*tk)->value : "");
        (*tk) = (*tk)->next;
    }

    /* conta quantos argumentos consecutivos (WORD or STRING) existem */
    temp = *tk;
    while (temp && (temp->type == WORD || temp->type == STRING))
    {
        argc++;
        temp = temp->next;
    }

    /* aloca array para args: 1 (command) + argc + 1 (NULL) */
    cmd->args = malloc(sizeof(char *) * (argc + 2));
    if (!cmd->args)
        return; /* sem memória: deixa cmd em estado consistente */

    /* argv[0] = command */
    cmd->args[0] = ft_strdup(cmd->command ? cmd->command : "");

    /* copia argumentos dos tokens */
    int i = 1;
    while (*tk && ((*tk)->type == WORD || (*tk)->type == STRING))
    {
        cmd->args[i++] = ft_strdup((*tk)->value ? (*tk)->value : "");
        *tk = (*tk)->next;
    }
    cmd->args[i] = NULL;
}
