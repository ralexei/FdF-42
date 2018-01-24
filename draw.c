/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:06:53 by alrusu            #+#    #+#             */
/*   Updated: 2017/01/26 13:43:39 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_draw_grid(t_fdf fdf, int color)
{
	int			i;
	int			j;

	i = 0;
	while (i < fdf.rows)
	{
		j = 0;
		while (j < fdf.cols)
		{
			if (j + 1 != fdf.cols)
				ft_draw_line(fdf, fdf.map[i][j], fdf.map[i][j + 1], color);
			if (i + 1 != fdf.rows)
				ft_draw_line(fdf, fdf.map[i][j], fdf.map[i + 1][j], color);
			j++;
		}
		i++;
	}
}

void			ft_draw_line(t_fdf fdf, t_vector p0, t_vector p1, int color)
{
	t_vector	d;
	t_vector	s;
	int			e[2];

	d.x = abs(p1.x - p0.x);
	d.y = abs(p1.y - p0.y);
	s.x = (p0.x < p1.x) ? 1 : -1;
	s.y = (p0.y < p1.y) ? 1 : -1;
	e[0] = ((d.x > d.y) ? d.x : -d.y) / 2;
	while (1)
	{
		mlx_pixel_put(fdf.mlx, fdf.win, p0.x, p0.y, color);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		e[1] = e[0];
		e[0] -= (e[1] > -d.x) ? d.y : 0;
		p0.x += (e[1] > -d.x) ? s.x : 0;
		e[0] += (e[1] < d.y) ? d.x : 0;
		p0.y += (e[1] < d.y) ? s.y : 0;
	}
}

void			ft_clean(t_fdf *fdf)
{
	ft_draw_grid(*fdf, BLACK);
}
