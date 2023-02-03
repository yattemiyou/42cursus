/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:46:07 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/03 21:11:35 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>

static int	get_digits(int n)
{
	int	digits;

	digits = 1;
	while (n / 10 > 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	int		negative;
	int		digits;
	char	*buffer;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	negative = 0;
	if (n < 0)
	{
		negative = 1;
		n *= -1;
	}
	digits = get_digits(n);
	buffer = ft_calloc(negative + digits + 1, sizeof(char));
	while (--digits >= 0)
	{
		buffer[negative + digits] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		buffer[0] = '-';
	return (buffer);
}
