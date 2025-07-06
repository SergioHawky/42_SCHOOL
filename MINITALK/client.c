/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 02:49:01 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/06 05:25:48 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

volatile sig_atomic_t	g_ack = 0;

void	handle_ack(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
	else if (sig == SIGUSR2)
		write(1, "Message received!\n", 18);
}

void	send_char(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack = 0;
		if (c & (0x80 >> bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_ack == 0)
			usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	if (argc != 3)
	{
		write(2, "Error: wrong format\n", 20);
		write(2, "Try: ./client <PID> <MESSAGE>\n", 30);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 1 || kill(pid, 0) == -1)
	{
		write(2, "Invalid PID.\n", 13);
		return (1);
	}
	signal(SIGUSR1, handle_ack);
	signal(SIGUSR2, handle_ack);
	i = 0;
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
