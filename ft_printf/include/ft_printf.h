/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:11:28 by anonymous         #+#    #+#             */
/*   Updated: 2023/06/03 10:41:31 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
ssize_t	ft_print_char(char c);
ssize_t	ft_print_string(const char *s);
ssize_t	ft_print_pointer(uintptr_t p);
ssize_t	ft_print_decimal(int d);
ssize_t	ft_print_number(uint64_t n, int base, int upper);

#endif
