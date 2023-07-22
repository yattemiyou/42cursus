/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:34:50 by anonymous         #+#    #+#             */
/*   Updated: 2023/07/22 11:39:40 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_common.h"

static int	initialize(void)
{
	if (ft_print_pid(getpid()) < 0)
		return (-1);
	if (ft_print_string("\n") < 0)
		return (-1);
	return (0);
}

int	main(void)
{
	if (initialize() < 0)
		return (1);
	while (1)
		pause();
	return (0);
}
