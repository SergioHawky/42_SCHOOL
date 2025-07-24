#include "../include/philosophers.h"

int parsing()
int main (int ac, char **av)
{
    if (ac != 5 && ac != 6)
    {
        write(2 ,"Please write: ./[program name] [n_of_philo] [t_die] [t_eat] [t_sleep]\n", 70);
        write(2 ,"or\n", 3)
        write(2 ,"Please write: ./[program name] [n_of_philo] [t_die] [t_eat] [t_sleep] [n_meals]\n", 80);
        return(1);
    }

    validate_arguments()
}