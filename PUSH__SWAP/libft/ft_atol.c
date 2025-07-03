#include "libft.h"

int	ft_atol(const char *n)
{
	int			i;
	long		sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r'))
		i++;
	if ((n[i] == '+' || n[i] == '-'))
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i])
	{
		if (res > 2147483647 || (res * sign) < -2147483648 || ft_strlen(n) > 11)
			write(2, "Error number\n", 13);
		if (!(n[i] >= '0' && n[i] <= '9'))
			write(2, "Error number\n", 13);
		res = res * 10 + (n[i++] - '0');
	}
	return ((int)(res * sign));
}
