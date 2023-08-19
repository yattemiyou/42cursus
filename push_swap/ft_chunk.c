/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:13:57 by anonymous         #+#    #+#             */
/*   Updated: 2023/08/20 07:00:26 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_chunk.h"

#include "ft_operation.h"
#include "ft_sort.h"
#include "ft_util.h"

static int64_t	move_chunk(t_stack *src, t_stack *dest)
{
	int64_t	current_value;

	if (src->head->next->value < dest->head->next->value)
	{
		current_value = src->head->next->value;
		push_stack(src, dest, 1);
	}
	else
	{
		current_value = dest->head->next->value;
		push_stack(dest, dest, 1);
	}
	rotate_stack(dest, 1);
	return (current_value);
}

static void	gather_chunk(t_stack *src, t_stack *dest, int64_t current_value)
{
	t_node	*node;

	node = src->head->next;
	while (node != src->head && current_value < node->value)
	{
		push_stack(src, dest, 1);
		rotate_stack(dest, 1);
		current_value = node->value;
		node = src->head->next;
	}
}

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

void	merge_chunk(t_stack *src, t_stack *dest, int final)
{
	int64_t	current_value;
	t_stack	*temp;

	while (is_sorted(src) == FALSE || is_sorted(dest) == FALSE || final--)
	{
		current_value = INT64_MIN;
		while (src->len > 0 && dest->len > 0)
		{
			if (current_value > src->head->next->value)
				break ;
			if (current_value > dest->head->next->value)
				break ;
			current_value = move_chunk(src, dest);
		}
		if (src->len == 0 || current_value > src->head->next->value)
			gather_chunk(dest, dest, current_value);
		else if (dest->len == 0 || current_value > dest->head->next->value)
			gather_chunk(src, dest, current_value);
		temp = src;
		src = dest;
		dest = temp;
	}
}
