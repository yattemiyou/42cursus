/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:28:17 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/19 15:18:38 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	offset;

	if (dest == NULL)
		return (ft_strlen(dest));
	offset = ft_strlen(dest);
	if (size <= offset)
		return (size + ft_strlen(src));
	return (offset + ft_strlcpy(dest + offset, src, size - offset));
}
