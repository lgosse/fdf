/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:29:00 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/15 15:11:23 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_modify_alt_quota(t_fdf *fdf, int value)
{
	ft_reinit_fdf(fdf);
	fdf->alt_quota += value;
	ft_draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win->win, fdf->img->img, 0, 0);
}

void	ft_modify_tiles_length(t_fdf *fdf, int value)
{
	int x1;
	int y1;
	int x2;
	int y2;

	ft_reinit_fdf(fdf);
	x1 = (fdf->begin_x + (fdf->size->x - fdf->size->y) * (fdf->tile_width) / 2)
		/ 2;
	y1 = (fdf->begin_y + (fdf->size->x + fdf->size->y) * (fdf->tile_height) / 2)
		/ 2;
	fdf->tile_height += value;
	fdf->tile_width = fdf->tile_height * 2;
	x2 = (fdf->begin_x + (fdf->size->x - fdf->size->y) * (fdf->tile_width) / 2)
		/ 2;
	y2 = (fdf->begin_y + (fdf->size->x + fdf->size->y) * (fdf->tile_height) / 2)
		/ 2;
	fdf->begin_x += x1 - x2;
	fdf->begin_y += y1 - y2;
	ft_draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win->win, fdf->img->img, 0, 0);
}

void	ft_move_horizontal(t_fdf *fdf, int value)
{
	ft_reinit_fdf(fdf);
	fdf->begin_x += value;
	ft_draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win->win, fdf->img->img, 0, 0);
}

void	ft_move_vertical(t_fdf *fdf, int value)
{
	ft_reinit_fdf(fdf);
	fdf->begin_y += value;
	ft_draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win->win, fdf->img->img, 0, 0);
}

void	ft_modify_color(t_fdf *fdf, int color)
{
	ft_reinit_fdf(fdf);
	fdf->color = color;
	ft_draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win->win, fdf->img->img, 0, 0);
}
