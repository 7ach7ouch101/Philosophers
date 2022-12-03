#include <unistd.h>
#include <stdio.h>
# include <sys/time.h>

int main(void)
{
	struct timeval	time_start;
	long long		ms;

	gettimeofday(&time_start, NULL);
    printf("%ld",time_start.tv_sec);
    return 0;
}