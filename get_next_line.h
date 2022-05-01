/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:07:57 by sjang             #+#    #+#             */
/*   Updated: 2019/11/13 18:34:04 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif

int				get_next_line(int fd, char **line);
char			*ft_strjoin(char const *s1, const char *s2);
int				ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strdup(const char *s1);
#endif
