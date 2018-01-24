/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:04:38 by alrusu            #+#    #+#             */
/*   Updated: 2017/01/25 16:28:28 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_translate(t_fdf *fdf, int key)
{
	int i;
	int j;

	i = 0;
	ft_clean(fdf);
	if (key == W)
		fdf->y_pos -= TRANSLATE_DIST;
	else if (key == S)
		fdf->y_pos += TRANSLATE_DIST;
	else if (key == A)
		fdf->x_pos -= TRANSLATE_DIST;
	else if (key == D)
		fdf->x_pos += TRANSLATE_DIST;
	while (i < fdf->rows)
	{
		j = 0;
		while (j < fdf->cols)
		{
			ft_add_to_map(fdf, i, j, fdf->map[i][j].h);
			j++;
		}
		i++;
	}
	ft_draw_grid(*fdf, fdf->rgb);
}

void			ft_change_heights(t_fdf *fdf, int key)
{
	int i;
	int j;

	i = 0;
	fdf->h_off += (key == E) ? H_TO_CHANGE : -H_TO_CHANGE;
	ft_clean(fdf);
	while (i < fdf->rows)
	{
		j = 0;
		while (j < fdf->cols)
		{
			ft_add_to_map(fdf, i, j, fdf->map[i][j].h);
			j++;
		}
		i++;
	}
	ft_draw_grid(*fdf, fdf->rgb);
}

void			ft_rotate(int key, t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	ft_clean(fdf);
	if (key == LEFT)
		fdf->cos_rot += ROT_X;
	else if (key == RIGHT)
		fdf->cos_rot -= ROT_X;
	else if (key == UP)
		fdf->sin_rot += ROT_Y;
	else if (key == DOWN)
		fdf->sin_rot -= ROT_Y;
	ft_calc_additives(fdf);
	while (i < fdf->rows)
	{
		j = 0;
		while (j < fdf->cols)
		{
			ft_add_to_map(fdf, i, j, fdf->map[i][j].h);
			j++;
		}
		i++;
	}
	ft_draw_grid(*fdf, fdf->rgb);
}

void			ft_change_rgb(int key, t_fdf *fdf)
{
	if (key == Y)
		fdf->r += (fdf->r + RGB <= 255) ? RGB : 0;
	else if (key == H)
		fdf->r -= (fdf->r - RGB >= 0) ? RGB : 0;
	else if (key == U)
		fdf->g += (fdf->g + RGB <= 255) ? RGB : 0;
	else if (key == J)
		fdf->g -= (fdf->g - RGB >= 0) ? RGB : 0;
	else if (key == I)
		fdf->b += (fdf->b + RGB <= 255) ? RGB : 0;
	else if (key == K)
		fdf->b -= (fdf->b - RGB >= 0) ? RGB : 0;
	ft_clean(fdf);
	fdf->rgb = (0 << 24) + (fdf->r << 16) + (fdf->g << 8) + fdf->b;
	ft_draw_grid(*fdf, fdf->rgb);
}

void			ft_zoom(int key, t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	ft_clean(fdf);
	if (key == MINUS)
		fdf->zoom -= ZOOM;
	else
		fdf->zoom += ZOOM;
	ft_calc_additives(fdf);
	while (i < fdf->rows)
	{
		j = 0;
		while (j < fdf->cols)
		{
			ft_add_to_map(fdf, i, j, fdf->map[i][j].h);
			j++;
		}
		i++;
	}
	ft_draw_grid(*fdf, fdf->rgb);
}
