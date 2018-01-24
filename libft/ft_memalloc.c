/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 18:14:15 by alrusu            #+#    #+#             */
/*   Updated: 2016/10/19 18:14:15 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	mem = (unsigned char*)malloc(sizeof(unsigned char) * size);
	if (mem && size)
	{
		ft_bzero(mem, size);
		return ((void *)mem);
	}
	return ((void *)0);
}
