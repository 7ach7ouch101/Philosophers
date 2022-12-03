#include "philo.h"

int parse_data(char **str, input_data *data, int ac)
{
    int i;
    i = 1;

    while(str[i])
    {
        if(!(ft_isdigit(str[i])))
            return (0);
        i++;
    }
    data->n_of_philos = ft_atoi(str[1]);
    data->t_to_d = ft_atoi(str[2]);
    data->t_to_e = ft_atoi(str[3]);
    data->t_to_s = ft_atoi(str[4]);
    if(ac == 6)
        data->n_e_p_m_eat = ft_atoi(str[5]);
    if((data->n_of_philos <= 0) || (data->t_to_d <= 0) || (data->t_to_e <= 0 &&
        data->t_to_s <= 0) || (ac == 6 && data->n_e_p_m_eat <= 0))
        return (0);
    return (1);
}
