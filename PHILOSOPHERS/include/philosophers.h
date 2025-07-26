#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>      //printf
#include <stdlib.h>     //malloc free
#include <unistd.h>     //write, usleep
#include <pthread.h>    //mutex, threads pesquisar
#include <sys/timeb.h>  //gettime
#include <limits.h>     //INT_MAX   

typedef struct s_data
{
    long    t_die;
    long    t_eat;
    long    t_sleep;
    long    meals;
    long    n_philo;
}               t_data;

size_t	ft_strlen(const char *s);
int	    ft_isdigit(int c);
long	ft_atol(const char *str);
void	free_and_exit_with_message(t_data *s, char *msg);

#endif