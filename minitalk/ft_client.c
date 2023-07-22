/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:32:13 by anonymous         #+#    #+#             */
/*   Updated: 2023/07/23 06:44:04 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_common.h"

#include <signal.h>
#include <unistd.h>

#define BITS 8

static void	send_byte(pid_t pid, unsigned char byte)
{
	int	i;

	i = BITS;
	while (i--)
	{
		if ((byte >> i) & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1000);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*ptr;

	if (argc != 3)
		return (1);
	pid = ft_read_pid(argv[1]);
	if (pid < 0)
		return (1);
	ptr = argv[2];
	while (*ptr)
		send_byte(pid, (unsigned char)*ptr++);
	send_byte(pid, (unsigned char)0x00);
	return (0);
}
