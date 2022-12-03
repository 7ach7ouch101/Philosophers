# ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct  philos_info
{
    pthread_t       philos_id;
    int                    id;
    long long                  time;
    int                   ate;
    struct input_data *i_data;
}                 philos_info;

typedef struct input_data
{
    int              n_of_philos;
    int                   t_to_d;
    int                   t_to_e;
    int                   t_to_s;
    int              n_e_p_m_eat;
    long long               time;
    philos_info          *philos;
    pthread_mutex_t	      *forks;
    pthread_mutex_t mutex_print;
}               input_data;


int         parse_data(char **str, input_data *data, int ac);
int	        ft_isdigit(char *str);
void	    my_usleep(long long time);
int         ft_atoi(char *str);
int         init_philos(input_data *data);
int         init_threads(input_data *data);
void        *routine(void *arg);
void        init_forks(philos_info *philo , int check);
long long	time_now(void);
void	    print(philos_info *philo, char *s, int check);
void	    *super_visor(input_data *data);
int	        free_all(input_data *philo);

# endif