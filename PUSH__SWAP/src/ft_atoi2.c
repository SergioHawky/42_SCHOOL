/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 00:33:14 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 10:02:25 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_tmp(char **tmp)
{
	int	i;

	if (!tmp)
		return ;
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

static void	free_and_exit(t_stacks *s, char **tmp)
{
	free_tmp(tmp);
	free_and_exit_with_message(s, "Error number");
	exit(1);
}

int	ft_atoi2(const char *n, t_stacks *s, char **tmp)
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
    	if (!(n[i] >= '0' && n[i] <= '9'))
        	free_and_exit(s, tmp);
    	if (sign == 1 && res > (2147483647 - (n[i] - '0')) / 10)
        	free_and_exit(s, tmp);
    	if (sign == -1 && res > (2147483648 - (n[i] - '0')) / 10)
        	free_and_exit(s, tmp);
			res = res * 10 + (n[i++] - '0');
	}
	return ((int)(res * sign));
}
