/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:24:40 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/20 00:28:54 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// This function duplicates a string and returns the duplicate

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	i;

	p = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!p)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}