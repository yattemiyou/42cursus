/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:34:50 by anonymous         #+#    #+#             */
/*   Updated: 2023/07/22 15:44:17 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_common.h"

#include <signal.h>
#include <stdint.h>
#include <stdlib.h>

static void	ft_write(sig_atomic_t byte)
{
	static uint8_t	buffer[2];
	static uint32_t	counter = 0;

	if (byte != '\0')
		buffer[counter++] = byte;
	if (byte == '\0' || counter >= sizeof(buffer))
	{
		if (write(STDOUT_FILENO, buffer, counter) < 0)
			exit(1);
		counter = 0;
	}
}

static void	ft_handler(int sig, siginfo_t *info, void *ucontext)
{
	static sig_atomic_t	byte = 0x01;

	(void)info;
	(void)ucontext;
	if (sig == SIGUSR1)
		byte = (byte << 1);
	else if (sig == SIGUSR2)
		byte = (byte << 1) | 0x01;
	if ((byte & 0x100) != 0x00)
	{
		ft_write(byte & 0xff);
		byte = 0x01;
	}
}

static int	ft_initialize(void)
{
	struct sigaction	s_act;

	s_act.sa_sigaction = ft_handler;
	s_act.sa_flags = SA_SIGINFO;
	if (sigemptyset(&s_act.sa_mask) < 0)
		return (-1);
	if (sigaddset(&s_act.sa_mask, SIGUSR1) < 0)
		return (-1);
	if (sigaddset(&s_act.sa_mask, SIGUSR2) < 0)
		return (-1);
	if (sigaction(SIGUSR1, &s_act, NULL) < 0)
		return (-1);
	if (sigaction(SIGUSR2, &s_act, NULL) < 0)
		return (-1);
	if (ft_print_pid(getpid()) < 0)
		return (-1);
	if (ft_print_string("\n") < 0)
		return (-1);
	return (0);
}

int	main(void)
{
	if (ft_initialize() < 0)
		return (1);
	while (1)
		pause();
	return (0);
}
