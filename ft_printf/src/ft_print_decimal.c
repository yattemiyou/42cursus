/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 07:25:21 by anonymous         #+#    #+#             */
/*   Updated: 2023/05/28 07:35:27 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

ssize_t	ft_print_decimal(va_list *ap)
{
	const int	value = va_arg(*ap, int);

	return (printf("%d", value));
}
