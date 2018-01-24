/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:36:37 by alrusu            #+#    #+#             */
/*   Updated: 2017/01/08 17:47:01 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 10000

typedef struct				s_fd_list
{
	int						fd;
	char					*buf;
	struct s_fd_list		*next;
	struct s_fd_list		*origin;
}							t_fd_list;
int							get_next_line(int const fd, char **line);
#endif
