/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:59:15 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/23 20:33:29 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	index;

	if (s == NULL)
		return (NULL);
	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	index = 0;
	while (str[index])
	{
		str[index] = f(index, str[index]);
		index++;
	}
	return (str);
}
