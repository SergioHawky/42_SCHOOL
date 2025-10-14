#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>      //printf
#include <stdlib.h>     //malloc free
#include <unistd.h>     //write, usleep
#include <pthread.h>    //mutex, threads pesquisar
#include <sys/time.h>   //gettime
#include <limits.h>     //INT_MAX


typedef pthread_t		t_id;
typedef pthread_mutex_t	t_mutex;

typedef struct s_data
{
    long    die;
    long    eat;
    long    sleep;
    long    meals;
    long    n_philo;
}               t_data;

typedef struct s_mutexes
{
	t_mutex	*left_fork;
	t_mutex	*right_fork;
	t_mutex	*write_lock;
	t_mutex	*meal_lock;
}               t_mutexes;

typedef struct s_philo
{
	int			id;
	t_data		data;
	t_mutexes	mutexes;
    t_id		thread_id;
	int			must_eat;
	int			meals_eaten;
	int			philo_count;
    long        last_meal;
}	            t_philo;

typedef struct s_engine
{
    t_data      data;
    t_mutex     *forks;
    t_mutex     write_lock;
    t_mutex     meal_lock;
    t_philo     *philos;
}               t_engine;



size_t	ft_strlen(const char *s);
int	    ft_isdigit(int c);
long	ft_atol(const char *str);
void	free_and_exit_with_message(t_engine *engine, char *msg);
long    get_current_time(void);

void    validate_arguments_and_store(t_engine *engine, int ac, char **av);
void    init_forks(t_engine *engine);
void    init_philos(t_engine *engine);
void    start_simulation(t_engine *engine);
void    *philo_routine(void *arg);

#endif