
#include "include/minitalk.h"

void ft_signal(int sig, siginfo_t *info, void *ucontext)
{
    static int bit = 0;
    static char c = 0;
    (void)info;
    (void)ucontext;

    if (sig == SIGUSR1)
        c |= (1 << bit);
    bit++;
    if (bit == 8)
    {
        if (c == '\0')
            write(1, "\n", 1);
        else
            write(1, &c, 1);
        bit = 0;
        c = 0;
    }
}


int main(void)
{
    pid_t pid;
    struct sigaction sa;

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
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        write(2, "Error: sigaction failed\n", 24);
        return (1);
    }
    while (1)
        pause();
}
