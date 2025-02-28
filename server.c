#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void    zoubir(int signal)
{
    static char c = 0;
    static int count = 0;

    // 1️⃣ Check which signal was received
    int bit = (signal == SIGUSR1) ? 1 : 0;

    // 2️⃣ Shift and store the bit
    c = (c << 1) | bit;
    count++;

    // 3️⃣ If 8 bits are received, print the character
    if (count == 8)
    {
        write(1, &c, 1); // Print the character
        count = 0;       // Reset counter
        c = 0;           // Reset character
    }
}


int main()
{
    printf("Server PID: %d\n", getpid());

    // Listen for signals
    signal(SIGUSR1, zoubir);
    signal(SIGUSR2, zoubir);

    // Keep running
    while (1)
        pause(); // Wait for signals
}