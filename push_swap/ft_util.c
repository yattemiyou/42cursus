/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:46:36 by anonymous         #+#    #+#             */
/*   Updated: 2023/08/19 15:02:21 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"

size_t	ft_strlen(const char *s)
{
	const char	*ptr = s;

	while (*ptr)
		ptr++;
	return (ptr - s);
}

ssize_t	ft_print_string(int fd, const char *s)
{
	return (write(fd, s, ft_strlen(s)));
}

int64_t	ft_atoi(const char *nptr)
{
	int64_t	sign;
	int64_t	value;

	sign = 1;
	value = 0;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (('0' <= *nptr) && (*nptr <= '9'))
	{
		value = value * 10 + (*nptr - '0');
		if ((sign * value > INT32_MAX) || (sign * value < INT32_MIN))
			return (INT64_MIN);
		nptr++;
		if (*nptr == '\0')
			return (sign * value);
	}
	return (INT64_MIN);
}
