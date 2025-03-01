/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:39:19 by marvin            #+#    #+#             */
/*   Updated: 2025/02/27 00:39:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <windows.h>
#include <stdio.h>

<<<<<<< HEAD
#define PIPE_NAME "\\\\.\\pipe\\MyPipe"

int main()
{
    HANDLE hPipe;
    char buffer[1024];
    DWORD bytesRead;

    printf("Server started. Waiting for client...\n");

    hPipe = CreateNamedPipeA(
        PIPE_NAME,              // Pipe name
        PIPE_ACCESS_INBOUND,    // Read-only pipe
        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, 
        1,                      // Only one client
        1024, 1024, 0, NULL);

    if (hPipe == INVALID_HANDLE_VALUE)
    {
        printf("Failed to create pipe.\n");
        return 1;
    }

    if (ConnectNamedPipe(hPipe, NULL))
    {
        printf("Client connected!\n");
        ReadFile(hPipe, buffer, sizeof(buffer), &bytesRead, NULL);
        buffer[bytesRead] = '\0'; // Ensure null termination
        printf("Received: %s\n", buffer);
        DisconnectNamedPipe(hPipe);
    }
    else
    {
        printf("Failed to connect.\n");
    }

    CloseHandle(hPipe);
    return 0;
}
=======
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
>>>>>>> 9ff2233dac2e17c0d600be32a2ed9866d055f918
