/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:32:13 by anonymous         #+#    #+#             */
/*   Updated: 2023/07/23 07:49:07 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_common.h"

#include <signal.h>

#define BITS 8

static int	send_byte(pid_t pid, unsigned char byte)
{
	int	i;
	int	ret;

	i = BITS;
	while (i--)
	{
		if ((byte >> i) & 0x01)
			ret = kill(pid, SIGUSR2);
		else
			ret = kill(pid, SIGUSR1);
		if (ret < 0)
		{
			ft_print_string("Error: kill\n");
			return (-1);
		}
		ret = usleep(1000);
		if (ret < 0)
		{
			ft_print_string("Error: usleep\n");
			return (-1);
		}
	}
	return (0);
}

static pid_t	ft_initialize(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
		return (-1);
	pid = ft_read_pid(argv[1]);
	if (pid < 0)
		return (-1);
	return (pid);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*ptr;

	pid = ft_initialize(argc, argv);
	if (pid < 0)
	{
		ft_print_string("Error: ft_initialize\n");
		return (1);
	}
	ptr = argv[2];
	while (*ptr)
		if (send_byte(pid, (unsigned char)*ptr++) < 0)
			return (1);
	if (send_byte(pid, (unsigned char)0x00) < 0)
		return (1);
	return (0);
}
