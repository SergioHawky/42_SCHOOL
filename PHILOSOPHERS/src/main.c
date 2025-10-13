#include "../include/philosophers.h"

void cleanup(t_engine *engine)
{
	int i = -1;

	while (++i < engine->data.n_philo)
		pthread_mutex_destroy(&engine->forks[i]);
	pthread_mutex_destroy(&engine->write_lock);
	pthread_mutex_destroy(&engine->meal_lock);

	free(engine->forks);
	free(engine->philos);
}

int main(int ac, char **av)
{
	t_engine engine;

	validate_arguments_and_store(&engine, ac, av);
	init_forks(&engine);
	init_philos(&engine);
	start_simulation(&engine);
	cleanup(&engine);
	return (0);
}