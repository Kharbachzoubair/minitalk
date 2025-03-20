/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:39:19 by marvin            #+#    #+#             */
/*   Updated: 2025/03/20 20:40:38 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>  
#include <stdio.h>   
#include <stdlib.h>
#include <signal.h>

void signal_handler(int signal, siginfo_t *info, void *context)
{
	static char c = 0;
	static int count = 0;
	static pid_t pid = -1;
   

	(void)context;
	if (pid != info->si_pid)
	{
		count = 0;
		c = 0;
		pid = info->si_pid;
	}
	
	int bit = (signal == SIGUSR1) ? 1 : 0;

	c = (c << 1) | bit;
	count++;

	if (count == 8) 
	{
	if (c == '\0') 
	write(1, "\n", 1);
	else 
	write(1, &c, 1);
	
	c = 0;
	count = 0;
	}

	}


int main()
{
	struct sigaction sa;
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;

	sigemptyset(&sa.sa_mask);

	printf("Server PID: %d\n", getpid());

	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
	perror("sigaction failed");
	return EXIT_FAILURE;
	}

	while (1)
	pause();

	return 0;
}
