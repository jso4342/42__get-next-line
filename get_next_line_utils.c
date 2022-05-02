/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:59:23 by sjang             #+#    #+#             */
/*   Updated: 2019/11/13 18:39:35 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char*)s);
}

int			ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, const char *s2)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2 || !(p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	free((void *)s1);
	return (p);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*dest;
	size_t	i;

	source = (char*)src;
	dest = dst;
	i = 0;
	if (len == 0 || dst == src)
		return (dst);
	if (source < dest)
	{
		while (++i <= len)
			dest[len - i] = source[len - i];
	}
	else
	{
		while (len-- > 0)
			*(dest++) = *(source++);
	}
	return (dst);
}

char		*ft_strdup(const char *s1)
{
	char	*p;
	int		i;
	int		len;

	len = 0;
	while (s1[len] != '\0')
		len++;
	if (!(p = (char*)malloc(sizeof(char) * (len + 1))))
	{
		free((void *)s1);
		s1 = NULL;
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
