/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:12:34 by anonymous         #+#    #+#             */
/*   Updated: 2023/08/20 05:46:26 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHUNK_H
# define FT_CHUNK_H

# include "ft_stack.h"

void	make_chunk(t_stack *stack_a, t_stack *stack_b, int n);
void	merge_chunk(t_stack *src, t_stack *dest);

#endif
