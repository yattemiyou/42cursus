/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:15:49 by anonymous         #+#    #+#             */
/*   Updated: 2023/06/03 11:57:12 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>

static int	ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s++ == (char)c)
			return (1);
	}
	return (0);
}

static ssize_t	dispatch(char type, va_list *ap)
{
	if (type == 'c')
		return (ft_print_char((char)va_arg(*ap, int)));
	if (type == 's')
		return (ft_print_string(va_arg(*ap, const char *)));
	if (type == 'p')
		return (ft_print_pointer(va_arg(*ap, uintptr_t)));
	if (type == 'd' || type == 'i')
		return (ft_print_decimal(va_arg(*ap, int)));
	if (type == 'u')
		return (ft_print_number(va_arg(*ap, unsigned int), 10, 0));
	if (type == 'x')
		return (ft_print_number(va_arg(*ap, unsigned int), 16, 0));
	if (type == 'X')
		return (ft_print_number(va_arg(*ap, unsigned int), 16, 1));
	if (type == '%')
		return (ft_print_char('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	ssize_t		sum;
	ssize_t		len;
	char		c;

	va_start(ap, format);
	sum = 0;
	while (*format)
	{
		c = *format++;
		if (c == '%' && ft_strchr("cspdiuxX%", *format))
			len = dispatch(*format++, &ap);
		else
			len = ft_print_char(c);
		if (len < 0 || sum + len > INT32_MAX)
		{
			sum = -1;
			break ;
		}
		sum += len;
	}
	va_end(ap);
	return (sum);
}
