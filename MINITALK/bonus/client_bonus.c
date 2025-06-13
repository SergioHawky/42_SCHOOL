
#include "minitalk_bonus.h"

volatile sig_atomic_t	g_ack = 0;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

void	send_char(pid_t pid, char c)
{
	for (int i = 0; i < 8; i++)
	{
		g_ack = 0;
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack)
			usleep(10);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr("Usage: ./client_bonus <PID> <message>\n");
		return (1);
	}
	signal(SIGUSR1, ack_handler);
	pid_t pid = ft_atoi(argv[1]);
	for (int i = 0; argv[2][i]; i++)
		send_char(pid, argv[2][i]);
	return (0);
}
