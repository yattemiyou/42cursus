/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:15:12 by anonymous         #+#    #+#             */
/*   Updated: 2023/03/04 16:42:43 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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

static int	store_substr(char **buffer, int *index, char *head, char *tail)
{
	char	*str;

	if (head == NULL)
		return (0);
	str = ft_substr(head, 0, tail - head);
	if (str != NULL)
	{
		buffer[*index] = str;
		*index += 1;
		return (0);
	}
	while (*index >= 0)
	{
		free(buffer[*index]);
		*index -= 1;
	}
	free(buffer);
	return (1);
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
			if (store_substr(buffer, &count, head, (char *)ptr) == 1)
				return (NULL);
			head = NULL;
		}
		else if (ptr == s || *(ptr - 1) == c)
			head = (char *)ptr;
		ptr++;
	}
	if (store_substr(buffer, &count, head, (char *)ptr) == 1)
		return (NULL);
	return (buffer);
}
