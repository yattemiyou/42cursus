/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:31:41 by anonymous         #+#    #+#             */
/*   Updated: 2023/08/19 20:36:04 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_chunk.h"
#include "ft_error.h"
#include "ft_operation.h"
#include "ft_stack.h"
#include "ft_util.h"

static void	free_memory(t_stack *stack)
{
	t_node	*ptr;
	t_node	*next;

	if (stack == NULL)
		return ;
	ptr = stack->head->next;
	while (ptr != stack->head)
	{
		next = ptr->next;
		free(ptr);
		ptr = next;
	}
	free(stack->head);
	free(stack);
}

static int	initialize(t_stack **a, t_stack **b, int argc, char *argv[])
{
	int		i;
	int64_t	value;

	*a = initialize_stack('a');
	*b = initialize_stack('b');
	if (*a == NULL || *b == NULL)
		return (FALSE);
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (value == INT64_MIN)
			return (FALSE);
		if (is_duplicated_number(*a, value))
			return (FALSE);
		if (add_node(*a, value) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	make_chunk(t_stack *stack_a, t_stack *stack_b, int n)
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

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	if (initialize(&stack_a, &stack_b, argc, argv) == FALSE)
	{
		free_memory(stack_a);
		free_memory(stack_b);
		ft_print_string(STDERR_FILENO, ERROR);
		return (1);
	}
	make_chunk(stack_a, stack_b, stack_a->len);
	free_memory(stack_a);
	free_memory(stack_b);
	return (0);
}
