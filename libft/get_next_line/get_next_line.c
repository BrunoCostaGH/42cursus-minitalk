/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:47:19 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/12/14 11:23:46 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_len(const char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (size);
	while (str[size])
		size++;
	return (size);
}

static char	*get_char(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i] != c)
	{
		if (str[i] == 0)
			return (0);
		i++;
	}
	return (str + (++i));
}

static char	*handle_stash(int fd, char *stash, char *buf, size_t read_bytes)
{
	stash = join_to_stash(stash, buf, read_bytes);
	while (!get_char(buf, '\n') && read_bytes == BUFFER_SIZE)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		stash = handle_stash(fd, stash, buf, read_bytes);
	}
	if (!stash || (!get_len(stash) && read_bytes == 0)
		|| read_bytes > BUFFER_SIZE)
	{
		if (stash)
		{
			free(stash);
			stash = 0;
		}
		return (0);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;
	char		*buf;
	char		*ptr;
	size_t		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (0);
	read_bytes = read(fd, buf, BUFFER_SIZE);
	stash[fd] = handle_stash(fd, stash[fd], buf, read_bytes);
	free(buf);
	if (!stash[fd])
		return (0);
	line = get_line(stash[fd], '\n');
	ptr = stash[fd];
	stash[fd] = get_char(stash[fd], '\n');
	if (stash[fd])
		stash[fd] = ft_strdup(stash[fd]);
	free(ptr);
	return (line);
}
