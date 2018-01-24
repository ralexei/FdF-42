/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:40:32 by alrusu            #+#    #+#             */
/*   Updated: 2017/01/26 13:42:23 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_put_legend(t_fdf fdf)
{
	mlx_string_put(fdf.mlx, fdf.win, 10, 10, 16777215, "Instruction:");
	mlx_string_put(fdf.mlx, fdf.win, 10, 25, 16777215, "WASD: move the map");
	mlx_string_put(fdf.mlx, fdf.win, 10, 40, 16777215,
			"Arrows: rotate the map");
	mlx_string_put(fdf.mlx, fdf.win, 10, 55, 16777215,
			"Q/E: change the heights");
	mlx_string_put(fdf.mlx, fdf.win, 10, 70, 16777215, "-/+: zoom");
	mlx_string_put(fdf.mlx, fdf.win, 10, HEIGHT - 60, 16777215, "Colors(RGB):");
	mlx_string_put(fdf.mlx, fdf.win, 10, HEIGHT - 45, 16777215,
			"Y/U/I keys for R+/G+/B+");
	mlx_string_put(fdf.mlx, fdf.win, 10, HEIGHT - 30, 16777215,
			"H/J/K keys for R-/G-/B-");
}

int				ft_input(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == Q || keycode == E)
		ft_change_heights(fdf, keycode);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		ft_translate(fdf, keycode);
	else if (keycode == UP || keycode == LEFT || keycode == RIGHT ||
			keycode == DOWN)
		ft_rotate(keycode, fdf);
	else if (keycode == MINUS || keycode == PLUS)
		ft_zoom(keycode, fdf);
	else if (keycode == Y || keycode == U || keycode == I || keycode == H ||
			keycode == J || keycode == K)
		ft_change_rgb(keycode, fdf);
	return (0);
}

void			ft_init(t_fdf *fdf)
{
	fdf->rows = 0;
	fdf->cols = 0;
	fdf->fd = 0;
	fdf->cos_rot = 30;
	fdf->sin_rot = 40;
	fdf->zoom = 0;
	fdf->r = 255;
	fdf->g = 255;
	fdf->b = 255;
	fdf->rgb = (0 << 24) + (fdf->r << 16) + (fdf->g << 8) + fdf->b;
}

void			ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

int				main(int ac, char **av)
{
	t_fdf		fdf;

	ft_init(&fdf);
	if (ac != 2)
		ft_error("usage: ./fdf file_name\n");
	fdf.fd = open(av[1], O_RDONLY);
	if (fdf.fd < 0)
		ft_error("File not found\n");
	ft_to_vector_map(&fdf, ft_read_map(&fdf));
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, TITLE);
	ft_translate(&fdf, 0);
	ft_put_legend(fdf);
	mlx_key_hook(fdf.win, ft_input, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
