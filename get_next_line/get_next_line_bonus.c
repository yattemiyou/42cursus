/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 05:51:41 by anonymous         #+#    #+#             */
/*   Updated: 2023/07/01 17:25:38 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <limits.h>
#include <stdlib.h>

static ssize_t	initialize(int fd, char	**buffer)
{
	ssize_t	buffer_len;

	if (*buffer == NULL)
	{
		*buffer = (char *)ft_calloc(BUFFER_SIZE + 1);
		if (*buffer == NULL)
			return (-1);
	}
	buffer_len = (ssize_t)ft_strlen(*buffer);
	if (buffer_len == 0)
		buffer_len = read(fd, *buffer, BUFFER_SIZE);
	return (buffer_len);
}

static char	*cat(char *line, size_t *line_len, char *buffer, ssize_t buffer_len)
{
	char	*lf;
	ssize_t	tail_len;
	char	*new_line;

	lf = ft_strchr(buffer, '\n');
	if (lf == NULL)
		tail_len = buffer_len;
	else
		tail_len = ++lf - buffer;
	new_line = ft_calloc(*line_len + tail_len + 1);
	if (new_line != NULL)
	{
		ft_strlcpy(new_line, line, *line_len);
		ft_strlcpy(new_line + *line_len, buffer, tail_len);
		*line_len += tail_len;
		ft_strlcpy(buffer, buffer + tail_len, buffer_len - tail_len);
	}
	free(line);
	return (new_line);
}

static void	finalize(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX + 1];
	char		*line;
	size_t		line_len;
	ssize_t		buffer_len;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > SSIZE_MAX)
		return (NULL);
	line = NULL;
	line_len = 0;
	buffer_len = initialize(fd, &(buffer[fd]));
	while (buffer_len > 0)
	{
		buffer[fd][buffer_len] = '\0';
		line = cat(line, &line_len, buffer[fd], buffer_len);
		if (line == NULL)
			break ;
		if (line[line_len - 1] == '\n')
			return (line);
		buffer_len = read(fd, buffer[fd], BUFFER_SIZE);
		if (buffer_len < 0)
			finalize(&line);
	}
	finalize(&(buffer[fd]));
	return (line);
}
