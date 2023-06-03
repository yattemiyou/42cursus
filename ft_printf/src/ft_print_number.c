/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 09:55:57 by anonymous         #+#    #+#             */
/*   Updated: 2023/06/03 14:42:06 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define HEX "0123456789abcdef"

static int	ft_toupper(int c)
{
	if (c < 'a' || 'z' < c)
		return (c);
	else
		return (c - 0x20);
}

ssize_t	ft_print_number(uint64_t n, int base, int upper)
{
	ssize_t	sum;
	ssize_t	len;
	char	hex;

	sum = 0;
	if (n / base > 0)
	{
		sum = ft_print_number(n / base, base, upper);
		if (sum < 0)
			return (-1);
	}
	hex = HEX[n % base];
	if (upper)
		hex = ft_toupper(hex);
	len = ft_print_char(hex);
	if (len < 0)
		return (-1);
	return (sum + len);
}
