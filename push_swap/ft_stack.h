/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:16:23 by anonymous         #+#    #+#             */
/*   Updated: 2023/08/19 15:13:15 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdint.h>

typedef struct s_node
{
	int64_t			value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	char		label;
	t_node		*head;
	uint64_t	len;
}	t_stack;

t_stack	*initialize_stack(char label);
int		add_node(t_stack *stack, int value);
int		is_sorted(t_stack *stack);

#endif
