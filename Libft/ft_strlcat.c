/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:28:17 by anonymous         #+#    #+#             */
/*   Updated: 2023/01/18 22:17:43 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	offset;

	offset = ft_strlen(dest);
	if (size <= offset)
		return (size + ft_strlen(src));
	return (offset + ft_strlcpy(dest + offset, src, size - offset));
}