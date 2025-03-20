/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:39:19 by marvin            #+#    #+#             */
/*   Updated: 2025/03/20 23:37:17 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>  
#include <stdio.h>   
#include <stdlib.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"


void	p_character(int *count, char *c)
{
	if (*count == 8)
	{
		*count = 0;
		if (*c == '\0')
			write(1, "\n", 1);
		else
			write(1, c, 1);
		*c = 0;
	}
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static char		c;
	static int		count;
	static pid_t	pid;
	int				bit;

	(void)context;
	if (pid != info->si_pid)
	{
		count = 0;
		c = 0;
		pid = info->si_pid;
	}
	if (signal == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	c = (c << 1) | bit;
	count++;
	p_character(&count, &c);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
