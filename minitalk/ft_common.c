/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:21:06 by anonymous         #+#    #+#             */
/*   Updated: 2023/07/22 11:09:07 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_common.h"

size_t	ft_strlen(const char *s)
{
	const char	*ptr = s;

	while (*ptr)
		ptr++;
	return (ptr - s);
}

ssize_t	ft_print_pid(pid_t pid)
{
	ssize_t	len;
	char	c;

	len = 0;
	if (pid >= 10)
	{
		len = ft_print_pid(pid / 10);
		if (len < 0)
			return (-1);
	}
	c = (pid % 10) + '0';
	if (write(STDOUT_FILENO, &c, sizeof(char)) < 0)
		return (-1);
	return (++len);
}

ssize_t	ft_print_string(const char *s)
{
	return (write(STDOUT_FILENO, s, ft_strlen(s)));
}
