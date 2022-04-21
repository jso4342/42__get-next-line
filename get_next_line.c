/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:49:36 by sjang             #+#    #+#             */
/*   Updated: 2019/11/13 19:05:21 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char*)s;
	while (n-- > 0)
		*(p++) = 0;
}

static char		*ft_givespace(size_t size)
{
	void			*r;

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
	static char		*buffer = NULL;
	int				i;
	char			*str;

	if ((fd < 0 || !line || (read(fd, buffer, 0) < 0) || BUFFER_SIZE == 0) || \
		(buffer == NULL && ((buffer = ft_givespace(BUFFER_SIZE + 1)) == NULL)))
		return (-1);
	i = 1;
	while (i != 0)
	{
		if ((str = ft_strchr(buffer, '\n')) != 0)
		{
			*str = '\0';
			if ((*line = ft_strdup(buffer)) == NULL)
				return (-1);
			ft_memmove(buffer, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		if ((buffer = combinebuffer(fd, buffer, &i)) == NULL)
			return (-1);
	}
	if ((*line = ft_strdup(buffer)) == NULL)
		return (-1);
	ft_free(&buffer);
	return (0);
}
