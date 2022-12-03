#include "philo.h"

void    *routine(void *arg)
{
    philos_info	*philo;

	philo = arg;
    if(philo->id % 2 == 0)
        my_usleep(philo->i_data->t_to_e / 2);
    while(1)
    {
        init_forks(philo , 1);
        print(philo,"is eating", 1);
        philo->ate = philo->ate + 1;
        my_usleep(philo->i_data->t_to_e);
        init_forks(philo , 0);
        philo->time = time_now();
        print(philo, "is sleeping", 1);
        my_usleep(philo->i_data->t_to_s);
        print(philo, "is thinking", 1);
    }
}

int	e_p_must_eat(int *j, philos_info *philo)
{
	if (philo->ate >= philo->i_data->n_e_p_m_eat)
		*j = *j + 1;
	if (*j == philo->i_data->n_of_philos)
	{
		print(philo, NULL, 0);
		return (0);
	}
	return (1);
}

void	*super_visor(input_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (1)
	{
		if (i == data->n_of_philos)
		{
			i = 0;
			j = 0;
		}
		if (data->n_e_p_m_eat)
        {
			if (!e_p_must_eat(&j, &data->philos[i]))
				return (NULL);
        }
		if ((time_now() - data->philos[i].time) >= data->t_to_d)
		{
			print(&data->philos[i], "died", 0);
			return (NULL);
		}
		i++;
	}
	return (NULL);
}