/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 00:33:06 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 00:33:06 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stacks;

void		rotate(int *array, int size, char *direction, char *list);
void		swap(char *str, int *array, int size);
void		push(char *str, t_stacks *s);
void		sort_three_elements(t_stacks *s);
void		sort_four_to_five_elements(t_stacks *s);
void		radix_sort(t_stacks *s);
void		parse_numbers(t_stacks *s);
void		create_index(t_stacks *s);
void		initialize_stacks(int argc, char **argv, t_stacks *s);
void		free_and_exit_with_message(t_stacks *s, char *msg);
void		exit_if_sorted_or_has_duplicate(t_stacks *s, int i);
int			is_array_sorted(t_stacks *s);
void		validate_arguments(int argc, char **argv);
int			ft_atoi2(const char *n, t_stacks *s, char **tmp);
void		free_tmp(char **tmp);

#endif