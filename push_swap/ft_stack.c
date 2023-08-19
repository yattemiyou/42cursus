/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:23:41 by anonymous         #+#    #+#             */
/*   Updated: 2023/08/19 14:50:01 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

#include <stdlib.h>
#include "ft_util.h"

t_stack	*initialize_stack(char label)
{
	t_stack	*stack;
	t_node	*sentinel;

	stack = (t_stack *)malloc(sizeof(t_stack));
	sentinel = (t_node *)malloc(sizeof(t_node));
	if (stack == NULL || sentinel == NULL)
	{
		free(stack);
		free(sentinel);
		return (NULL);
	}
	sentinel->value = INT64_MIN;
	sentinel->prev = sentinel;
	sentinel->next = sentinel;
	stack->label = label;
	stack->head = sentinel;
	stack->len = 0;
	return (stack);
}

int	add_node(t_stack *stack, int value)
{
	t_node	*head;
	t_node	*tail;
	t_node	*node;

	head = stack->head;
	tail = stack->head->prev;
	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (FALSE);
	node->value = value;
	node->prev = tail;
	node->next = head;
	tail->next = node;
	head->prev = node;
	stack->len += 1;
	return (TRUE);
}
