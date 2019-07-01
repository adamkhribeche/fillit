/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:53:32 by fokrober          #+#    #+#             */
/*   Updated: 2019/07/01 02:05:18 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		readline(int fd, t_string *f, char **line)
{
	char	buf[BUFF_SIZE];
	char	*tmp;
	ssize_t	r;
	ssize_t	i;

	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if ((i = ft_memichr(buf, '\n', (size_t)r)) != -1)
		{
			tmp = (char*)ft_memjoin(*line, buf, f->size, (size_t)i);
			ft_strdel(line);
			*line = tmp;
			f->size = (size_t)(r - (i + 1));
			ft_strdel(&(f->s));
			f->s = (char*)ft_memdupz(buf + i + 1, f->size);
			return (1);
		}
		tmp = (char*)ft_memjoin(*line, buf, f->size, (size_t)r);
		ft_strdel(line);
		*line = tmp;
		f->size += (size_t)r;
	}
	ft_strdel(&(f->s));
	f->size = 0;
	return (r);
}

int			chk_last(int fd, t_string *f, char **line)
{
	ssize_t	r;
	size_t	i;
	char	*tmp;

	i = 0;
	while ((f->s)[i] != '\n' && i < f->size)
		i++;
	*line = (char*)ft_memdupz(f->s, i);
	if (i < f->size)
	{
		if (!(tmp = (char*)ft_memdupz(f->s + i + 1, f->size)))
			return (-1);
		ft_strdel(&(f->s));
		f->s = tmp;
		f->size -= i + 1;
		return (1);
	}
	if ((r = readline(fd, f, line)) == -1)
		return (-1);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static t_string		f[MAX_FD];
	ssize_t				r;

	if (fd < 0 || BUFF_SIZE < 0 || !line)
		return (-1);
	*line = NULL;
	if (f[fd].s && f[fd].size)
		return (chk_last(fd, &f[fd], line));
	if ((r = readline(fd, &f[fd], line)) == 0)
		return (f[fd].size == 0 && *line);
	return (r);
}
