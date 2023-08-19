/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:58:34 by anonymous         #+#    #+#             */
/*   Updated: 2023/08/19 19:14:28 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

#include "ft_util.h"

int	is_duplicated_number(t_stack *stack, int64_t n)
{
	t_node	*ptr;

	ptr = stack->head->next;
	while (ptr != stack->head)
	{
		if (ptr->value == n)
			return (TRUE);
		ptr = ptr->next;
	}
	return (FALSE);
}
