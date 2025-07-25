#include "../include/philosophers.h"

int main (int ac, char **av)
{
    t_data  *s;

    int i = 1;

    if (ac != 5 && ac != 6)
    {
        write(2 ,"Please write: ./[program name] [n_of_philo] [t_die] [t_eat] [t_sleep]\n", 70);
        write(2 ,"or\n", 3);
        write(2 ,"Please write: ./[program name] [n_of_philo] [t_die] [t_eat] [t_sleep] [n_meals]\n", 80);
        return(1);
    }
    s = malloc(sizeof(*s));
    while (i < ac)
    {
        validate_arguments_and_parse(s, av[i], i);
        i++;
    }
    printf("n_philo: %d\n", s->n_philo);
    printf("die: %ld\n", s->t_die);
    printf("eat: %ld\n", s->t_eat);
    printf("sleep: %ld\n", s->t_sleep);
    printf("meals: %d\n", s->meals);
    return 0;
}