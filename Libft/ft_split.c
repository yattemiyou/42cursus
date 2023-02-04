/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:15:12 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/04 11:27:24 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_count(char const *s, char c)
{
	char const	*ptr = s;
	int			count;

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
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char const	*ptr = s;
	char		*head;
	int			count;
	char		**target;

	if (s == NULL)
		return (NULL);
	head = NULL;
	count = 0;
	target = ft_calloc(get_count(s, c) + 1, sizeof(char *));
	while (*ptr)
	{
		if (*ptr == c)
		{
			if (head != NULL)
				target[count++] = ft_substr(head, 0, ptr - head);
			head = NULL;
		}
		else if (ptr == s || *(ptr - 1) == c)
			head = (char *)ptr;
		ptr++;
	}
	if (head != NULL)
		target[count++] = ft_substr(head, 0, ptr - head);
	return (target);
}
