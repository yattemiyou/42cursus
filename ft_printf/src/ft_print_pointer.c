/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 09:43:11 by anonymous         #+#    #+#             */
/*   Updated: 2023/06/03 11:37:11 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_print_pointer(uintptr_t p)
{
	ssize_t	sum;
	ssize_t	len;

	sum = 0;
	if (p == '\0')
		return (ft_print_string("(nil)"));
	len = ft_print_string("0x");
	if (len < 0)
		return (-1);
	sum += len;
	len = ft_print_number(p, 16, 0);
	if (len < 0)
		return (-1);
	return (sum + len);
}
