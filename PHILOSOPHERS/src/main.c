#include "../include/philosophers.h"

void	free_and_exit_with_message(t_data *s, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (s != NULL)
		free(s);
	
    exit(1);
}

static void    validate_arguments_and_parse(t_data *s, char **av, int  ac)
{
    int     i;
    int     j;
    long    num;

    i = 0;
    if (ac < 5 || ac > 6)
        free_and_exit_with_message(s, "Please write the corrcet arguments\n");
    while (++i < ac)
    {
        j = -1;
        while (av[i][++j])
        {
            if (!(ft_isdigit(av[i][j])))
                free_and_exit_with_message(s, "Error write only numbers\n");
        }
        num = ft_atol(av[i]);
        if (i == 1)
            s->n_philo = num;
        else if (i == 2)
            s->t_die = num;
        else if (i == 3)
            s->t_eat = num;
        else if (i == 4)
            s->t_sleep = num;
        else if (i == 5)
            s->meals = num;
    }

}

int main (int ac, char **av)
{
    t_data  *s;

    s = malloc(sizeof(*s));
    
    validate_arguments_and_parse(s, av, ac);
    free_and_exit_with_message(s, "OK");
    return 0;
}