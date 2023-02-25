/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:15:12 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/25 14:32:24 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**get_array(char const *s, char c)
{
	char const	*ptr = s;
	int			count;

	if (s == NULL)
		return (NULL);
	count = 0;
	while (*ptr)
	{
		if (*ptr != c)
		{
			if (ptr == s || *(ptr - 1) == c)
				count++;
		}
		ptr++;
	}
	return (ft_calloc(count + 1, sizeof(char *)));
}

char	**ft_split(char const *s, char c)
{
	char const	*ptr = s;
	char		*head;
	int			count;
	char		**buffer;

	buffer = get_array(s, c);
	if (buffer == NULL)
		return (NULL);
	head = NULL;
	count = 0;
	while (*ptr)
	{
		if (*ptr == c)
		{
			if (head != NULL)
				buffer[count++] = ft_substr(head, 0, ptr - head);
			head = NULL;
		}
		else if (ptr == s || *(ptr - 1) == c)
			head = (char *)ptr;
		ptr++;
	}
	if (head != NULL)
		buffer[count++] = ft_substr(head, 0, ptr - head);
	return (buffer);
}
