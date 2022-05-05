/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:49:36 by sjang             #+#    #+#             */
/*   Updated: 2019/11/27 16:07:28 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void		ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char*)s;
	while (n-- > 0)
		*(p++) = 0;
}

static char		*give(size_t size)
{
	void			*r;

	if (size - 1 <= 0)
		return (NULL);
	if (!(r = (char*)malloc(sizeof(char) * (size))))
		return (NULL);
	ft_bzero(r, size);
	return ((char *)r);
}

static char		*combinebuffer(int fd, char *buffer, int *i)
{
	char			*storage;

	if (!(storage = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (NULL);
	*i = read(fd, storage, BUFFER_SIZE);
	storage[*i] = '\0';
	if (!(buffer = ft_strjoin(buffer, storage)))
		return (NULL);
	free(storage);
	return (buffer);
}

static void		ft_free(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
}

int				get_next_line(int fd, char **line)
{
	static char		*buffer[OPEN_MAX];
	int				i;
	char			*str;

	if ((fd < 0 || fd > OPEN_MAX || !line || read(fd, buffer[fd], 0) < 0) ||
		(buffer[fd] == NULL && ((buffer[fd] = give(BUFFER_SIZE + 1)) == NULL)))
		return (-1);
	i = 1;
	while (i != 0)
	{
		if ((str = ft_strchr(buffer[fd], '\n')) != 0)
		{
			*str = '\0';
			if ((*line = ft_strdup(buffer[fd])) == NULL)
				return (-1);
			ft_memmove(buffer[fd], str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		if ((buffer[fd] = combinebuffer(fd, buffer[fd], &i)) == NULL)
			return (-1);
	}
	if ((*line = ft_strdup(buffer[fd])) == NULL)
		return (-1);
	ft_free(&buffer[fd]);
	return (0);
}
