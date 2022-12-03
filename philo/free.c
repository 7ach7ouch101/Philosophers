#include "philo.h"

int	free_all(input_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_of_philos)
    {
		pthread_mutex_destroy(&(data->forks[i]));
        i++;
    }
	pthread_mutex_destroy(&(data->mutex_print));
	free(data->philos);
	free(data->forks);
	return (0);
}