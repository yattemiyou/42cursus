/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 07:28:11 by anonymous         #+#    #+#             */
/*   Updated: 2023/08/19 07:45:29 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NODE_H
# define FT_NODE_H

# include <stdint.h>

typedef struct s_node
{
	int64_t			value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

#endif
