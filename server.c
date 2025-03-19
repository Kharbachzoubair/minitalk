/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:39:19 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 13:39:52 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>  
#include <unistd.h>  
#include <stdio.h>   


void    zoubir(int signal)
{
    static char c = 0;
    static int count = 0;

    
    int bit = (signal == SIGUSR1) ? 1 : 0;

   
    c = (c << 1) | bit;
    count++;

   
    if (count == 8)
    {
        write(1, &c, 1); 
        count = 0;
        c = 0;
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

