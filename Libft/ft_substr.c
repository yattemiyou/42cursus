/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:10:16 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/24 22:03:05 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	void	*buffer;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	size = ft_strlen(s) - start;
	if (len < size)
		size = len;
	size += 1;
	buffer = ft_calloc(size, 1);
	if (buffer == NULL)
		return (NULL);
	ft_strlcpy(buffer, s + start, size);
	return (buffer);
}
