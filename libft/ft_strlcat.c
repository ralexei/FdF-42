/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 18:14:23 by alrusu            #+#    #+#             */
/*   Updated: 2016/10/19 18:14:23 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	siz_dst;
	unsigned int	siz_src;
	int				len;

	siz_dst = ft_strlen(dst);
	siz_src = ft_strlen(src);
	len = size - 1 - siz_dst;
	if (size <= siz_dst)
		return (size + siz_src);
	while (*dst)
		dst++;
	while (*src && len)
	{
		*dst++ = *src++;
		len--;
	}
	*dst = '\0';
	return (siz_dst + siz_src);
}
