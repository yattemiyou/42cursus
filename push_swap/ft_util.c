/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:46:36 by anonymous         #+#    #+#             */
/*   Updated: 2023/08/08 21:52:02 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"

size_t	ft_strlen(const char *s)
{
	const char	*ptr = s;

	while (*ptr)
		ptr++;
	return (ptr - s);
}

ssize_t	ft_print_string(const char *s)
{
	return (write(STDOUT_FILENO, s, ft_strlen(s)));
}
