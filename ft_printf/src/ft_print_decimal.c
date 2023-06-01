/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 07:25:21 by anonymous         #+#    #+#             */
/*   Updated: 2023/06/01 21:07:36 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_print_decimal(const int d)
{
	unsigned int	positive;
	ssize_t			len;

	positive = (unsigned int)d;
	len = 0;
	if (d < 0)
	{
		len = ft_print_char('-');
		positive = (unsigned int)(-1 * d);
	}
	if (positive / 10 > 0)
		len += ft_print_decimal(positive / 10);
	len += ft_print_char(positive % 10 + '0');
	return (len);
}
