/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 15:21:29 by alrusu            #+#    #+#             */
/*   Updated: 2017/01/26 13:54:05 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "keys.h"
# define WIDTH 500
# define HEIGHT 500
# define TITLE "THE ULTRAMEGASUPERWINDOW"
# define H_TO_CHANGE 1
# define TRANSLATE_DIST 1
# define ROT_X 10
# define ROT_Y 10
# define ZOOM 1
# define RGB 15
# define BLACK 0x00000000

typedef struct	s_vector
{
	int			x;
	int			y;
	int			h;
}				t_vector;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	int			fd;
	t_vector	**map;
	int			rows;
	int			cols;
	double		line_len;
	double		cos_rot;
	double		sin_rot;
	double		cos_a;
	double		sin_a;
	int			h_off;
	int			x_pos;
	int			y_pos;
	int			zoom;
	int			r;
	int			g;
	int			b;
	int			rgb;
	int			opacity;
}				t_fdf;

void			ft_add_to_map(t_fdf *fdf, int i, int j, int h);
void			ft_draw_grid(t_fdf fdf, int color);
void			ft_draw_line(t_fdf fdf, t_vector p0, t_vector p1, int color);
void			ft_clean(t_fdf *fdf);
void			ft_draw_line(t_fdf fdf, t_vector p0, t_vector p1, int color);
void			ft_calc_additives(t_fdf *fdf);
void			ft_alloc_map(t_fdf *fdf);
int				ft_count_columns(char *l);
int				ft_count_rows(char *l);
int				ft_is_space(char c);
void			ft_to_vector_map(t_fdf *fdf, char *str);
void			ft_add_to_map(t_fdf *fdf, int i, int j, int h);
char			*ft_read_map(t_fdf *fdf);
void			ft_zoom(int key, t_fdf *fdf);
void			ft_change_rgb(int key, t_fdf *fdf);
void			ft_rotate(int key, t_fdf *fdf);
void			ft_change_heights(t_fdf *fdf, int key);
void			ft_translate(t_fdf *fdf, int key);
#endif
