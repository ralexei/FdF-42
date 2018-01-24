/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:37:50 by alrusu            #+#    #+#             */
/*   Updated: 2016/11/23 17:36:24 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int						ft_find_nl(char *buf)
{
	int					pos;

	pos = 0;
	while (buf[pos] != '\n' && buf[pos] != '\0')
		pos++;
	return (pos);
}

char					*ft_njoin(char *s, char *buf, int nl)
{
	char				*str;
	int					i;
	int					j;

	i = 0;
	j = 0;
	str = ft_strnew(ft_strlen(s) + nl + 1);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	while (j < nl)
	{
		str[i++] = buf[j];
		j++;
	}
	free(s);
	return (str);
}

void					ft_delete_used(char **s, char buf[], int nl)
{
	int					i;

	i = 0;
	if (buf[0] == '\0' && *s != '\0')
		return ;
	while (buf[i + nl + 1] != '\0')
	{
		buf[i] = buf[i + nl + 1];
		i++;
	}
	while (i < BUFF_SIZE)
		buf[i++] = '\0';
}

static t_fd_list		*get_fd(int fd, t_fd_list *cur_lst)
{
	t_fd_list			*tmp;

	tmp = cur_lst;
	if (tmp)
	{
		while (tmp->next)
		{
			if (tmp->fd == fd)
				return (tmp);
			tmp = tmp->next;
		}
		if (tmp->fd == fd)
			return (tmp);
		if (!(tmp->next = (t_fd_list *)malloc(sizeof(t_fd_list))))
			return (NULL);
		tmp = tmp->next;
	}
	else if (!(tmp = (t_fd_list*)malloc(sizeof(t_fd_list))))
		return (NULL);
	tmp->fd = fd;
	tmp->buf = ft_strnew(BUFF_SIZE + 1);
	tmp->next = NULL;
	tmp->origin = (cur_lst) ? cur_lst : tmp;
	return (tmp);
}

int						get_next_line(int const fd, char **line)
{
	static t_fd_list	*rfd = NULL;
	int					rb;
	int					nl;

	if (!line || fd < 0 || !(rb = 1))
		return (-1);
	*line = ft_strnew(1);
	rfd = get_fd(fd, rfd);
	while (rb > 0)
	{
		if (rfd->buf[0] == '\0')
			rb = read(fd, rfd->buf, BUFF_SIZE);
		if (rb < 0)
			return (-1);
		nl = ft_find_nl(rfd->buf);
		*line = ft_njoin(*line, rfd->buf, nl);
		if (rfd->buf[nl] != '\0' || (rfd->buf[0] == '\0' && *line[0] != '\0'))
		{
			ft_delete_used(line, rfd->buf, nl);
			rfd = rfd->origin;
			return (1);
		}
		ft_strclr(rfd->buf);
	}
	return (0);
}
