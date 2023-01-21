/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:19:39 by anonymous         #+#    #+#             */
/*   Updated: 2023/01/21 11:50:04 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s2);
	if (n < len)
		return (NULL);
	ptr = ft_strchr(s1, s2[0]);
	while (ptr != NULL && (size_t)(ptr - s1) <= (n - len))
	{
		if (ft_strncmp(ptr, s2, len) == 0)
			return (ptr);
		ptr = ft_strchr(++ptr, s2[0]);
	}
	return (NULL);
}
