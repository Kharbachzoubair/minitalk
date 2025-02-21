#include <unistd.h>
#include <signal.h>
#include <stdio.h>


void    zoubir(int s)
{
    char c = 0;
    int count = 0;
    int bit;
    if (s == SIGUSR1)
        bit = 1;
    else if (s == SIGUSR2)
        bit = 0;

    while (count < 8)
    {
        c
        count++;
    }
}



int main()
{
    signal(SIGUSR1, zoubir);
    signal(SIGUSR2, zoubir);
    printf("server pid  =  %d\n", getpid());
    while (1)
    {
        pause();
    }
    
}