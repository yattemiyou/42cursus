/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 07:25:21 by anonymous         #+#    #+#             */
/*   Updated: 2023/06/03 11:32:41 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_print_decimal(int d)
{
	int64_t	n;
	ssize_t	sum;
	ssize_t	len;

	n = (int64_t)d;
	sum = 0;
	if (d < 0)
	{
		n *= -1;
		len = ft_print_char('-');
		if (len < 0)
			return (-1);
		sum += len;
	}
	len = ft_print_number((uint64_t)n, 10, 0);
	if (len < 0)
		return (-1);
	return (sum + len);
}
