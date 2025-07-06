/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 02:48:57 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/06 05:22:02 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

void	ft_signal(int sig, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	bit;

	(void)ucontext;
	if (sig == SIGUSR1)
		c |= (0x80 >> bit);
	else if (sig == SIGUSR2)
		c &= ~(0x80 >> bit);
	++bit;
	if (bit == 8)
	{
		if (c == 0)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	if (pid < 1)
	{
		write(2, "Initialization failure\n", 24);
		return (1);
	}
	ft_printf("Server PID = %d\n", pid);
	sa.sa_sigaction = ft_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
