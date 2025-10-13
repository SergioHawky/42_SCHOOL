#include "../include/philosophers.h"

void print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->mutexes.write_lock);
	printf("%ld %d %s\n", get_current_time(), philo->id, msg);
	pthread_mutex_unlock(philo->mutexes.write_lock);
}

void eat(t_philo *philo)
{
	pthread_mutex_lock(philo->mutexes.left_fork);
	print_status(philo, "has taken a fork");

	pthread_mutex_lock(philo->mutexes.right_fork);
	print_status(philo, "has taken a fork");

	pthread_mutex_lock(philo->mutexes.meal_lock);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->mutexes.meal_lock);

	print_status(philo, "is eating");
	usleep(philo->data.eat * 1000);

	philo->meals_eaten++;

	pthread_mutex_unlock(philo->mutexes.left_fork);
	pthread_mutex_unlock(philo->mutexes.right_fork);
}

void philo_sleep_and_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->data.sleep * 1000);

	print_status(philo, "is thinking");
}

void *philo_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	if (philo->id % 2 == 0)
		usleep(1000);

	while (1)
	{
		eat(philo);
		if (philo->must_eat != -1 && philo->meals_eaten >= philo->must_eat)
			break;
		philo_sleep_and_think(philo);
	}
	return (NULL);
}
