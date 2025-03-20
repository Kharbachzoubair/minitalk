/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sigint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:45:01 by zkharbac          #+#    #+#             */
/*   Updated: 2025/03/20 17:55:47 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Program is running, send SIGSTOP to pause it and SIGCONT to resume.\n");

    while(1) {
        printf("Running...\n");
        sleep(1);  // The program will keep running until you send SIGSTOP
    }

    return 0;
}
