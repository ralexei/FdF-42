/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:11:56 by alrusu            #+#    #+#             */
/*   Updated: 2017/01/25 16:11:21 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char			*ft_read_map(t_fdf *fdf)
{
	char		*buf;
	char		*rez;

	rez = ft_strnew(1);
	buf = ft_strnew(BUFF_SIZE);
	while (read(fdf->fd, buf, BUFF_SIZE) > 0)
		rez = ft_strjoin(rez, buf);
	fdf->cols = ft_count_columns(rez);
	fdf->rows = ft_count_rows(rez);
	return (rez);
}

void			ft_add_to_map(t_fdf *fdf, int i, int j, int h)
{
	int tmp;

	tmp = 0;
	if (h != 0)
	{
		fdf->map[i][j].h = h;
		tmp = fdf->h_off;
	}
	else
		fdf->map[i][j].h = 0;
	fdf->map[i][j].x = (i - fdf->rows / 2) * fdf->line_len * -fdf->cos_a +
		(j - fdf->cols / 2) * fdf->line_len * fdf->cos_a + WIDTH / 2 +
		fdf->x_pos;
	fdf->map[i][j].y = (i - fdf->rows / 2) * fdf->line_len *
		fdf->sin_a - (j - fdf->cols / 2) * fdf->line_len * -fdf->sin_a -
		(h + tmp) * 0.105 * fdf->line_len + HEIGHT / 2 + fdf->y_pos;
}

void			ft_to_vector_map(t_fdf *fdf, char *str)
{
	int i;
	int j;

	i = 0;
	ft_alloc_map(fdf);
	ft_calc_additives(fdf);
	while (i < fdf->rows)
	{
		j = 0;
		while (j < fdf->cols)
		{
			while (!ft_isdigit(*str) && *str)
				str++;
			if (ft_isdigit(*str))
				ft_add_to_map(fdf, i, j, ft_atoi(str));
			while (!ft_is_space(*str) && *str)
				str++;
			j++;
		}
		i++;
	}
}
