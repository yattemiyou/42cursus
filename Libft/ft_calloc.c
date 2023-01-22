/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:36:14 by anonymous         #+#    #+#             */
/*   Updated: 2023/01/22 14:38:33 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb > ULLONG_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
// （参考）
// https://hiroyukichishiro.com/arithmetic-overflow-in-c-language/
