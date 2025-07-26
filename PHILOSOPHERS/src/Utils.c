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
    int     sign;
    int     i;

    result = 0;
    sign = 1;
    i = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        if (result > (LONG_MAX - (str[i] - '0')) / 10)
            free_and_exit_with_message(NULL, "Error: number too big\n");
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}