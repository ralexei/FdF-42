/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 18:14:17 by alrusu            #+#    #+#             */
/*   Updated: 2016/10/19 18:14:17 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;
	unsigned char	*dest;
	size_t			i;

	i = 0;
	str = (unsigned char*)src;
	dest = (unsigned char*)dst;
	if (str < dest)
	{
		while (++i <= len)
			dest[len - i] = str[len - i];
	}
	else
		while (i < len)
		{
			dest[i] = str[i];
			i++;
		}
	return (dst);
}
