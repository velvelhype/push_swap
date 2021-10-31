#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

static void process(void);

int main(void)
{
    struct timespec begin, end;

    clock_gettime(CLOCK_REALTIME, &begin);

    process();

    clock_gettime(CLOCK_REALTIME, &end);
    double summed = 0;
    summed += (double)(end.tv_sec - begin.tv_sec);
    summed += (double)(end.tv_nsec - begin.tv_nsec) / (1000 * 1000 * 1000);

    printf("\nresult is %f", summed);
}

void process(void)
{
    for(int i; i < 10000 ; i++)
    {
        write(1, "wooo woooo woooooooo", 21);
    }
}