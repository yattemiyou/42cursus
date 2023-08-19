/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:13:57 by anonymous         #+#    #+#             */
/*   Updated: 2023/08/19 20:16:31 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_chunk.h"

#include "ft_operation.h"

static void	sort_2node_asc(t_stack *stack)
{
	t_node	*n1;
	t_node	*n2;

	n1 = stack->head->next;
	n2 = n1->next;
	if (n1->value > n2->value)
		swap_stack(stack);
}

static void	sort_2node_desc(t_stack *stack)
{
	t_node	*n1;
	t_node	*n2;

	n1 = stack->head->next;
	n2 = n1->next;
	if (n1->value < n2->value)
		swap_stack(stack);
}

static void	sort_3node_asc(t_stack *stack)
{
	t_node	*n1;
	t_node	*n2;
	t_node	*n3;

	n1 = stack->head->next;
	n2 = n1->next;
	n3 = n2->next;
	if (n1->value < n3->value && n3->value < n2->value)
	{
		swap_stack(stack);
		rotate_stack(stack, 1);
	}
	else if (n2->value < n1->value && n1->value < n3->value)
		swap_stack(stack);
	else if (n2->value < n3->value && n3->value < n1->value)
		rotate_stack(stack, 1);
	else if (n3->value < n1->value && n1->value < n2->value)
		rrotate_stack(stack);
	else if (n3->value < n2->value && n2->value < n1->value)
	{
		swap_stack(stack);
		rrotate_stack(stack);
	}
}

int	sort_node(t_stack *stack, int len, int asc)
{
	if (asc)
	{
		if (len == 2)
			sort_2node_asc(stack);
		if (len == 3)
			sort_3node_asc(stack);
	}
	else
	{
		if (len == 2)
			sort_2node_desc(stack);
	}
	return (len);
}
