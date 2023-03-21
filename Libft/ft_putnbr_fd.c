/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:35:33 by anonymous         #+#    #+#             */
/*   Updated: 2023/03/21 12:56:24 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	positive;

	positive = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		positive = (unsigned int)(-1 * n);
	}
	if (positive / 10 > 0)
		ft_putnbr_fd(positive / 10, fd);
	ft_putchar_fd(positive % 10 + '0', fd);
}
