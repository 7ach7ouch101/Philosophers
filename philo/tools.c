#include "philo.h"

long long	time_now(void)
{
	struct timeval	time_start;
	long long		ms;

	gettimeofday(&time_start, NULL);
	ms = (time_start.tv_sec * 1000) + (time_start.tv_usec / 1000);
	return (ms);
}

void	my_usleep(long long time)
{
	long long	current;

	current = time_now();
	while ((time_now() - time) < current)
		usleep(50);
}

int	ft_isdigit(char *str)
{
    int i;
    i = 0;
	while(str[i])
	{
        if(str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return 0;
	}
	return (1);
}

int ft_atoi(char *str)
{
    int i;
    int sing;
    int res;

    sing = 1;
    i = 0;
    res = 0;
    while(str[i] <= 33 && str[i] >= 127)
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sing = sing * (-1);
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return (res * sing);
}

void	print(philos_info *philo, char *s, int check)
{
	pthread_mutex_lock(&philo->i_data->mutex_print);
    if(s)
	    printf("%lldms %d %s\n", (time_now() - philo->i_data->time),
			    philo->id, s);
    if(check)
	    pthread_mutex_unlock(&philo->i_data->mutex_print);
}