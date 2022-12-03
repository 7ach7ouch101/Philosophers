#include "philo.h"

int init_philos(input_data *data)
{
    int i;

    i = 0;
    data->philos = malloc(sizeof(philos_info) * (data->n_of_philos));
    if(!data->philos)
        return 0;
    data->forks = malloc(sizeof(pthread_mutex_t) * (data->n_of_philos));
    if(!data->forks)
        return (0);
    data->time = time_now();
    while(i < data->n_of_philos)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        data->philos[i].id = i + 1;
        data->philos[i].i_data = data;
        data->philos[i].ate = 0;
        data->philos[i].time = data->time;
        i++;
    }
    return (1);
}

int init_threads(input_data *data)
{
    int i;
    i = 0;

    pthread_mutex_init(&data->mutex_print, NULL);
    while(i < data->n_of_philos)
    {
        pthread_create(&data->philos[i].philos_id, NULL,
            &routine, &data->philos[i]);
        pthread_detach(data->philos[i].philos_id);
        i++;
    }
    return (1);
}

void    init_forks(philos_info *philo , int check)
{
    if(check == 1)
    {
        pthread_mutex_lock(&philo->i_data->forks[(philo->id - 1) % (philo->i_data->n_of_philos)]);
        print(philo, "has taken a fork", 1);
        pthread_mutex_lock(&philo->i_data->forks[(philo->id) % (philo->i_data->n_of_philos)]);
        print(philo, "has taken a fork", 1);
    }
    else
    {
        pthread_mutex_unlock(&philo->i_data->forks[(philo->id - 1) % (philo->i_data->n_of_philos)]);
        pthread_mutex_unlock(&philo->i_data->forks[(philo->id) % (philo->i_data->n_of_philos)]);
    }
}