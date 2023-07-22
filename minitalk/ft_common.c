/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:21:06 by anonymous         #+#    #+#             */
/*   Updated: 2023/07/22 10:23:13 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_common.h"

void	ft_print_pid(pid_t pid)
{
	char	c;

	if (pid >= 10)
		ft_print_pid(pid / 10);
	c = (pid % 10) + '0';
	write(STDOUT_FILENO, &c, sizeof(char));
}
