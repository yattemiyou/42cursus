/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:25:07 by anonymous         #+#    #+#             */
/*   Updated: 2023/08/19 20:15:38 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPERATION_H
# define FT_OPERATION_H

# include "ft_stack.h"

void	push_stack(t_stack *src, t_stack *dest, int n);
void	swap_stack(t_stack *stack);
void	rotate_stack(t_stack *stack, int n);
void	rrotate_stack(t_stack *stack);

#endif
