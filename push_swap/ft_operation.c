/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:27:59 by anonymous         #+#    #+#             */
/*   Updated: 2023/08/19 16:15:49 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"

#include "ft_util.h"

static void	print_operation(char *operation, char label)
{
	static char	label_lf[] = {'x', '\n', '\0'};

	ft_print_string(STDOUT_FILENO, operation);
	label_lf[0] = label;
	ft_print_string(STDOUT_FILENO, label_lf);
}

void	swap_stack(t_stack *stack)
{
	t_node	*n0;
	t_node	*n1;
	t_node	*n2;
	t_node	*n3;

	if (stack->len <= 1)
		return ;
	print_operation("s", stack->label);
	n0 = stack->head;
	n1 = n0->next;
	n2 = n1->next;
	n3 = n2->next;
	n0->next = n2;
	n2->prev = n0;
	n2->next = n1;
	n1->prev = n2;
	n1->next = n3;
	n3->prev = n1;
}

void	rotate_stack(t_stack *stack)
{
	t_node	*n0;
	t_node	*n1;
	t_node	*n2;
	t_node	*nz;

	if (stack->len <= 1)
		return ;
	print_operation("r", stack->label);
	n0 = stack->head;
	n1 = n0->next;
	n2 = n1->next;
	nz = stack->head->prev;
	nz->next = n1;
	n1->prev = nz;
	n1->next = n0;
	n0->prev = n1;
	n0->next = n2;
	n2->prev = n0;
}

void	rrotate_stack(t_stack *stack)
{
	t_node	*n0;
	t_node	*n1;
	t_node	*ny;
	t_node	*nz;

	if (stack->len <= 1)
		return ;
	print_operation("rr", stack->label);
	n0 = stack->head;
	n1 = n0->next;
	nz = stack->head->prev;
	ny = nz->prev;
	ny->next = n0;
	n0->prev = ny;
	n0->next = nz;
	nz->prev = n0;
	nz->next = n1;
	n1->prev = nz;
}
