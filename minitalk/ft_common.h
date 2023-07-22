/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:10:08 by anonymous         #+#    #+#             */
/*   Updated: 2023/07/22 11:13:31 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMMON_H
# define FT_COMMON_H

# include <unistd.h>

size_t	ft_strlen(const char *s);
ssize_t	ft_print_pid(pid_t pid);
ssize_t	ft_print_string(const char *s);

#endif
