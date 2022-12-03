#include "philo.h"

int main(int ac, char **av)
{
    input_data data;

    if(ac == 5 || ac == 6)
    {
        if(!(parse_data(av, &data,ac)))
            return (printf("INPUT INCORRECT\n"), 0);
        init_philos(&data);
        init_threads(&data);
        super_visor(&data);
        free_all(&data);
    }
    else
        printf("NUMBER OF ARGUMENTS INCORRECT\n");
    return (0);
}