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

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>  // Needed for SIGUSR1, SIGUSR2, kill()

unsigned long is_int(char *str)
{
    unsigned long val = 0;
    int i = 0;
    int sign = 1;

    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            val = val * 10 + (str[i] - '0');
        else
            return (0);
        if ((sign == 1 && val > 2147483647) || (sign == -1 && val > 2147483648))
            return (0);
        i++;
    }
    return (val * sign);
}

void send_bit(pid_t server_pid, char c)
{
    int i = 7;
    while (i >= 0)
    {
        if ((c >> i) & 1)
            kill(server_pid, SIGUSR1);
        else
            kill(server_pid, SIGUSR2);
        usleep(150);
        i--;
    }
}

void send_message(pid_t server_pid, char *message)
{
    while (*message)
    {
        send_bit(server_pid, *message);
        message++;
    }
    send_bit(server_pid, '\0');
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <Server PID> <Message>\n", argv[0]);
        return (1);
    }
    
    pid_t server_pid = is_int(argv[1]);
    if (server_pid <= 0)
    {
        printf("SOS -- Invalid PID --\n");
        return (1);
    }
    
    send_message(server_pid, argv[2]);

}
