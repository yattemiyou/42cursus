/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 05:54:47 by anonymous         #+#    #+#             */
/*   Updated: 2023/06/24 11:00:10 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	const char	*ptr = s;

	if (ptr == NULL)
		return (0);
	while (*ptr)
		ptr++;
	return (ptr - s);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

void	*ft_calloc(size_t size)
{
	void	*ptr;
	size_t	index;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	index = 0;
	while (index < size)
		((unsigned char *)ptr)[index++] = (unsigned char)0;
	return (ptr);
}

void	ft_strlcpy(char *dest, const char *src, size_t size)
{
	if (dest == NULL || src == NULL)
		return ;
	while (size-- && *src)
		*dest++ = *src++;
	*dest = '\0';
}
