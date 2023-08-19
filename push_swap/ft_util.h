/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:46:06 by anonymous         #+#    #+#             */
/*   Updated: 2023/08/19 13:46:44 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
# define FT_UTIL_H

# include <stdint.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

size_t	ft_strlen(const char *s);
ssize_t	ft_print_string(const char *s);
int64_t	ft_atoi(const char *nptr);

#endif
