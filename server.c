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
