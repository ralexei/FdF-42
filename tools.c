/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:02:58 by alrusu            #+#    #+#             */
/*   Updated: 2017/01/25 16:19:00 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\b' || c == '\n')
		return (1);
	return (0);
}

int				ft_count_rows(char *l)
{
	int			i;
	int			r;

	r = 0;
	i = 0;
	while (l[i])
	{
		if (l[i] == '\n')
			r++;
		i++;
	}
	return (r);
}

int				ft_count_columns(char *l)
{
	int			i;
	int			c;

	c = 0;
	i = 0;
	while (l[i] && l[i] != '\n')
	{
		if (ft_isdigit(l[i]))
		{
			c++;
			while (!ft_is_space(l[i]) && l[i] && l[i + 1] != '\n')
				i++;
		}
		if (l[i] == '\n' || l[i + 1] == '\n')
			break ;
		i++;
	}
	return (c);
}

void			ft_alloc_map(t_fdf *fdf)
{
	int			i;

	i = 0;
	fdf->map = (t_vector **)malloc(fdf->rows * sizeof(t_vector *));
	while (i < fdf->rows)
		fdf->map[i++] = (t_vector *)malloc(fdf->cols * sizeof(t_vector));
}

void			ft_calc_additives(t_fdf *fdf)
{
	fdf->cos_a = cos(fdf->cos_rot * M_PI / 180);
	fdf->sin_a = cos(fdf->sin_rot * M_PI / 180);
	fdf->line_len = 0.75 * (WIDTH / (fdf->rows * 0.5 + fdf->cols * 0.86)) +
		fdf->zoom;
}
