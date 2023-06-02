/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 07:25:21 by anonymous         #+#    #+#             */
/*   Updated: 2023/06/02 21:46:51 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_print_decimal(long d)
{
	ssize_t			len;

	len = 0;
	if (d < 0)
	{
		len = ft_print_char('-');
		d *= -1;
	}
	if (d / 10 > 0)
		len += ft_print_decimal(d / 10);
	len += ft_print_char(d % 10 + '0');
	return (len);
}
