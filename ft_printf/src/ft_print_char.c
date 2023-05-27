/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 07:12:58 by anonymous         #+#    #+#             */
/*   Updated: 2023/05/28 07:21:03 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

ssize_t	ft_print_char(va_list *ap)
{
	const char	c = (char)va_arg(*ap, int);

	return (write(1, &c, 1));
}
