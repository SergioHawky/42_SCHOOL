#include "../include/philosophers.h"

void *monitor_death(void *arg)
{
	t_engine *engine = (t_engine *)arg;
	int i;
	int full;
	long now;

	while (1)
	{
		full = 0;
		i = -1;
		while (++i < engine->data.n_philo)
		{
			pthread_mutex_lock(engine->philos[i].mutexes.meal_lock);
			now = get_current_time();
			if ((now - engine->philos[i].last_meal) >= engine->data.die)
			{
				pthread_mutex_unlock(engine->philos[i].mutexes.meal_lock);
				pthread_mutex_lock(&engine->write_lock);
				printf("%ld %d died\n", now, engine->philos[i].id);
				exit(0);
			}
			if (engine->data.meals != -1 &&
				engine->philos[i].meals_eaten >= engine->data.meals)
				full++;
			pthread_mutex_unlock(engine->philos[i].mutexes.meal_lock);
		}
		if (engine->data.meals != -1 && full == engine->data.n_philo)
			exit(0);
		usleep(1000);
	}
	return (NULL);
}

void start_simulation(t_engine *engine)
{
	int i = -1;
	while (++i < engine->data.n_philo)
	{
		if (pthread_create(&engine->philos[i].thread_id, NULL,
				&philo_routine, &engine->philos[i]) != 0)
			free_and_exit_with_message(engine, "Thread creation failed\n");
	}

	pthread_t monitor_thread;
	if (pthread_create(&monitor_thread, NULL, &monitor_death, engine) != 0)
		free_and_exit_with_message(engine, "Monitor thread failed\n");

	pthread_join(monitor_thread, NULL);

	i = -1;
	while (++i < engine->data.n_philo)
		pthread_join(engine->philos[i].thread_id, NULL);
}
