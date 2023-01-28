/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:00:00 by anonymous         #+#    #+#             */
/*   Updated: 2023/01/28 18:06:45 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		count;
	char	*buffer;

	if (s1 == NULL || set == NULL)
		return (NULL);
	ptr = (char *)s1;
	count = 0;
	while (*ptr)
	{
		if (ft_strchr(set, *ptr) != NULL)
			count++;
		ptr++;
	}
	buffer = ft_calloc(1, ft_strlen(s1) - count + 1);
	ptr = buffer;
	while (*s1)
	{
		if (ft_strchr(set, *s1) == NULL)
			*ptr++ = *s1;
		s1++;
	}
	return (buffer);
}
