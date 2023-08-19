/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:13:57 by anonymous         #+#    #+#             */
/*   Updated: 2023/08/20 05:38:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_chunk.h"

#include "ft_operation.h"
#include "ft_sort.h"
#include "ft_util.h"

void	make_chunk(t_stack *stack_a, t_stack *stack_b, int n)
{
	int	chunked;
	int	asc;

	chunked = 0;
	asc = FALSE;
	while (n - chunked > 1)
	{
		if (is_sorted(stack_a) && is_sorted(stack_b))
			break ;
		if (stack_a->len <= 3)
		{
			chunked += sort_node(stack_a, stack_a->len, TRUE);
			break ;
		}
		chunked += sort_node(stack_a, 2, asc);
		if (asc)
		{
			if (n - chunked > 1)
				rotate_stack(stack_a, 2);
		}
		else
			push_stack(stack_a, stack_b, 2);
		asc ^= 0x01;
	}
}
