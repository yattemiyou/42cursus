/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:05:21 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/28 21:22:53 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static long	is_overflow(int sign, long n, int m)
{
	int	ones_place;

	if (sign == 1)
	{
		ones_place = LONG_MAX % 10;
		if (n > LONG_MAX / 10 || (n == LONG_MAX / 10 && m > ones_place))
			return (LONG_MAX);
	}
	else
	{
		ones_place = (LONG_MIN - (LONG_MIN / 10) * 10) * -1;
		if (n > LONG_MIN / -10 || (n == LONG_MIN / -10 && m > ones_place))
			return (LONG_MIN);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	ret;
	long	overflow;

	sign = 1;
	ret = 0;
	while ((0x09 <= *nptr && *nptr <= 0x0d) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		overflow = is_overflow(sign, ret, *nptr - '0');
		if (overflow != 0)
			return ((int)overflow);
		ret = ret * 10 + (*nptr++ - '0');
	}
	return (sign * ret);
}
