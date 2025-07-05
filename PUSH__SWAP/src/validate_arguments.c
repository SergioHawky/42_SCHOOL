/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 00:42:02 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 01:36:40 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	validate_argument_string(const char *arg)
{
	int	j;

	j = 0;
	while (arg[j] != '\0')
	{
		if ((!(ft_isdigit(arg[j])) && arg[j] != ' '
				&& arg[j] != '-' && arg[j] != '+')
			|| (arg[j] == '-' && arg[j + 1] == '\0')
			|| (arg[j] == '+' && arg[j + 1] == '\0')
			|| (arg[j] == '-' && arg[j + 1] == ' ')
			|| (arg[j] == '+' && arg[j + 1] == ' ')
			|| (arg[j] == '-' && (arg[j + 1] == '-' || arg[j + 1] == '+'))
			|| (arg[j] == '+' && (arg[j + 1] == '-' || arg[j + 1] == '+')))
		{
			free_and_exit_with_message(NULL, "Error digit/+/-/' '\n");
		}
		j++;
	}
}

void	validate_arguments(int argc, char **argv)
{
	int	i;
	int	k;

	i = 0;
	while (++i < argc)
	{
		k = 0;
		while (argv[i][k] == ' ')
			k++;
		if (argv[i][0] == '\0' || argv[i][k] == '\0')
			free_and_exit_with_message(NULL, "Error\n");
		validate_argument_string(argv[i]);
	}
}
