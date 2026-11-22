/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelberka <aelberka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:43:58 by aelberka          #+#    #+#             */
/*   Updated: 2026/11/21 21:26:59 by aelberka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*find_new_line(char *line)
{
	size_t	i;
	char	*remainder;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	remainder = ft_strdup(line + i + 1);
	if (!remainder || *remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	line[i + 1] = '\0';
	return (remainder);
}

static char	*read_and_store(int fd, char *ptr, char *buff)
{
	ssize_t	read_bytes;
	char	*temp;

	read_bytes = read(fd, buff, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buff[read_bytes] = '\0';
		if (!ptr)
			ptr = ft_strdup("");
		temp = ft_strjoin(ptr, buff);
		free(ptr);
		if (!temp)
			return (NULL);
		ptr = temp;
		if (ft_strchr(ptr, '\n'))
			break ;
		read_bytes = read(fd, buff, BUFFER_SIZE);
	}
	if (read_bytes < 0)
	{
		free(ptr);
		ptr = NULL;
		return (NULL);
	}
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*ptr[FD_MAX];
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	line = read_and_store(fd, ptr[fd], buff);
	free(buff);
	if (!line)
	{
		ptr[fd] = NULL;
		return (NULL);
	}
	ptr[fd] = find_new_line(line);
	return (line);
}
