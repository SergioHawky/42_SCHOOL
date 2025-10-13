#include "../include/philosophers.h"

#include "../include/philosophers.h"

void validate_arguments_and_store(t_engine *engine, int ac, char **av)
{
	int i, j;
	long num;

	if (ac < 5 || ac > 6)
		free_and_exit_with_message(NULL, "Invalid number of arguments\n");

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				free_and_exit_with_message(NULL, "Only numeric arguments allowed\n");

		num = ft_atol(av[i]);
		if (i == 1) engine->data.n_philo = num;
		if (i == 2) engine->data.die = num;
		if (i == 3) engine->data.eat = num;
		if (i == 4) engine->data.sleep = num;
		if (i == 5) engine->data.meals = num;
	}
	if (ac == 5)
		engine->data.meals = -1;
}

void init_forks(t_engine *engine)
{
	int i;

	engine->forks = malloc(sizeof(t_mutex) * engine->data.n_philo);
	if (!engine->forks)
		free_and_exit_with_message(engine, "Malloc failed for forks\n");

	i = -1;
	while (++i < engine->data.n_philo)
		if (pthread_mutex_init(&engine->forks[i], NULL) != 0)
			free_and_exit_with_message(engine, "Mutex init failed\n");

	pthread_mutex_init(&engine->write_lock, NULL);
	pthread_mutex_init(&engine->meal_lock, NULL);
}

void init_philos(t_engine *engine)
{
	int i;
	long now = get_current_time();

	engine->philos = malloc(sizeof(t_philo) * engine->data.n_philo);
	if (!engine->philos)
		free_and_exit_with_message(engine, "Malloc failed for philos\n");

	i = -1;
	while (++i < engine->data.n_philo)
	{
		engine->philos[i].id = i + 1;
		engine->philos[i].data = engine->data;
		engine->philos[i].philo_count = engine->data.n_philo;
		engine->philos[i].meals_eaten = 0;
		engine->philos[i].must_eat = engine->data.meals;
		engine->philos[i].last_meal = now;
		engine->philos[i].mutexes.left_fork = &engine->forks[i];
		engine->philos[i].mutexes.right_fork = &engine->forks[(i + 1) % engine->data.n_philo];
		engine->philos[i].mutexes.write_lock = &engine->write_lock;
		engine->philos[i].mutexes.meal_lock = &engine->meal_lock;
	}
}
