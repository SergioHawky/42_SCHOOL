/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:21:42 by seilkiv           #+#    #+#             */
/*   Updated: 2025/04/22 12:21:46 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	len(int n)
{
	size_t	counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		counter++;
	while (n != 0)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		len_numb;
	long	c;

	c = n;
	len_numb = len(n);
	p = (char *)malloc((len_numb + 1) * sizeof(char));
	if (!p)
		return (NULL);
	p[len_numb] = '\0';
	if (c == 0)
		p[0] = '0';
	if (c < 0)
	{
		p[0] = '-';
		c = -c;
	}
	while (c > 0)
	{
		p[--len_numb] = (c % 10) + '0';
		c /= 10;
	}
	return (p);
}
/*#include <stdio.h>
int	main(void)
{
	char *s = ft_itoa(-444444444);
	printf("%s\n", s);
}*/