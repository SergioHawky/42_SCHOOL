#include "include/minitalk.h"

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 0;
	while(i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i ++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		write(2, "Only 3 arguments please: ./client <PID> <MESSAGE>\n", 51);
		return (1);
	}
	pid_t pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i ++;
	}
	return (0);
}
