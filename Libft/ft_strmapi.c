/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:59:15 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/26 13:51:06 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	index;

	if (s == NULL || f == NULL)
		return (NULL);
	dest = ft_strdup(s);
	if (dest == NULL)
		return (NULL);
	index = 0;
	while (dest[index])
	{
		dest[index] = f(index, dest[index]);
		index++;
	}
	return (dest);
}
