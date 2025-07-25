#include "../include/philosophers.h"

void	free_and_exit_with_message(char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
    exit(1);
}