/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:39:51 by marvin            #+#    #+#             */
/*   Updated: 2025/02/27 00:39:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <windows.h>
#include <stdio.h>

#define PIPE_NAME "\\\\.\\pipe\\MyPipe"

int main(int argc, char *argv[])
{
    HANDLE hPipe;
    DWORD bytesWritten;

    if (argc != 2)
    {
        printf("Usage: %s <Message>\n", argv[0]);
        return 1;
    }

    hPipe = CreateFileA(
        PIPE_NAME, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

    if (hPipe == INVALID_HANDLE_VALUE)
    {
        printf("Failed to connect to server.\n");
        return 1;
    }

    WriteFile(hPipe, argv[1], strlen(argv[1]), &bytesWritten, NULL);
    CloseHandle(hPipe);

    printf("Message sent to server!\n");
    return 0;
}
