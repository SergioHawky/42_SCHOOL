#include "../include/philosophers.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

long	ft_atol(const char *str)
{
    long    result;
    int     i;

    result = 0;
    i = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        if (result > (LONG_MAX - (str[i] - '0')) / 10)
            free_and_exit_with_message(NULL, "Error: number too big\n");
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result);
}

long get_current_time(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void free_and_exit_with_message(t_engine *engine, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (engine)
	{
		free(engine->forks);
		free(engine->philos);
	}
	exit(1);
}