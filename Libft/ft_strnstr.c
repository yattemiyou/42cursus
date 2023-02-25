/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:19:39 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/26 08:57:23 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t range)
{
	size_t	len;

	len = ft_strlen(little);
	if (len == 0)
		return ((char *)big);
	while (*big && range-- >= len)
	{
		if (ft_strncmp(big, little, len) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
