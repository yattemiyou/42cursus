/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:46:07 by anonymous         #+#    #+#             */
/*   Updated: 2023/03/19 17:47:03 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>

static int	get_digits(unsigned int n)
{
	int	digits;

	digits = 1;
	while (n / 10 >= 1)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	unsigned int	positive;
	int				negative;
	int				digits;
	char			*buffer;

	positive = (unsigned int)n;
	negative = 0;
	if (n < 0)
	{
		positive = (unsigned int)((n + 1) * -1 + 1);
		negative = 1;
	}
	digits = get_digits(positive);
	buffer = ft_calloc(negative + digits + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (--digits >= 0)
	{
		buffer[negative + digits] = positive % 10 + '0';
		positive = positive / 10;
	}
	if (negative)
		buffer[0] = '-';
	return (buffer);
}
