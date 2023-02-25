/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:00:00 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/25 14:09:01 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*ptr = s1;
	char		*start;
	char		*end;

	if (s1 == NULL)
		return (NULL);
	while (*ptr && ft_strchr(set, *ptr) != NULL)
		ptr++;
	start = (char *)ptr;
	ptr = s1 + ft_strlen(s1);
	while (ptr != start && ft_strchr(set, *ptr) != NULL)
		ptr--;
	end = (char *)++ptr;
	return (ft_substr(start, 0, end - start));
}
