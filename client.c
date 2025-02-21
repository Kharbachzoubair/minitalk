#include <unistd.h>
#include <signal.h>
#include <stdio.h>


int main()
{
    char arv[] = "hello world hey ";
    kill (15251, SIGUSR2);
}