#include "../include/philosophers.h"

void    validate_arguments_and_parse(t_data *s, char *str, int  av)
{
    int i;

    i = 0;
    if (str[0] == '+')
        i ++;
    while (str[i])
    {
        if (!(ft_isdigit(str[i])))
            free_and_exit_with_message("Error write only numbers\n");
        i++;
    }
    if (av == 1)
        s->n_philo = ft_atol(str);
    if (av == 2)
        s->t_die = ft_atol(str);
    if (av == 3)
        s->t_eat = ft_atol(str);
    if (av == 4)
        s->t_sleep = ft_atol(str);
    if (av == 5)
        s->meals = ft_atol(str);
}