/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:15:49 by anonymous         #+#    #+#             */
/*   Updated: 2023/06/02 21:56:21 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <string.h>

static ssize_t	dispatch(char type, va_list *ap)
{
	if (type == 'c')
		return (ft_print_char((char)va_arg(*ap, int)));
	if (type == 's')
		return (ft_print_string(va_arg(*ap, char *)));
	if (type == 'd' || type == 'i')
		return (ft_print_decimal(va_arg(*ap, int)));
	if (type == 'u')
		return (ft_print_decimal(va_arg(*ap, unsigned int)));
	if (type == '%')
		return (ft_print_char('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		sum;
	ssize_t		len;
	char		c;

	sum = 0;
	va_start(ap, format);
	while (*format)
	{
		c = *format++;
		if (c == '%' && strchr("csdiu%", *format))
		{
			len = dispatch(*format, &ap);
			format++;
		}
		else
			len = ft_print_char(c);
		sum += len;
	}
	va_end(ap);
	return (sum);
}
