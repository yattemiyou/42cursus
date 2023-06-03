/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:08:15 by anonymous         #+#    #+#             */
/*   Updated: 2023/06/03 07:59:45 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	const char	*ptr = s;

	while (*ptr)
		ptr++;
	return (ptr - s);
}

ssize_t	ft_print_string(const char *s)
{
	if (s == NULL)
		s = "(null)";
	return (write(STDOUT_FILENO, s, ft_strlen(s)));
}
