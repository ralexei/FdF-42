/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 18:14:27 by alrusu            #+#    #+#             */
/*   Updated: 2016/10/19 18:14:27 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s)
		return (NULL);
	if (!(dest = (char *)malloc((len + 1) * sizeof(*s))))
		return (NULL);
	ft_strncpy(dest, &(s[start]), len);
	dest[len] = '\0';
	return (dest);
}
