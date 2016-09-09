/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 16:54:06 by lgosse            #+#    #+#             */
/*   Updated: 2016/07/20 15:58:20 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_reinit_fdf(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win->win);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	fdf->img->img = mlx_new_image(fdf->mlx, fdf->win->width, fdf->win->height);
	fdf->img->data = mlx_get_data_addr(fdf->img->img, &fdf->img->bpp,
		&fdf->img->sline, &fdf->img->endian);
}

void	ft_destroy_hud(t_fdf *fdf)
{
	if (fdf->hud)
	{
		mlx_destroy_window(fdf->mlx, fdf->hud->win);
		free(fdf->hud);
		fdf->hud = NULL;
	}
}

int		ft_handle_graph_win(int button, int x, int y, t_fdf *fdf)
{
	(void)button;
	ft_reinit_fdf(fdf);
	fdf->begin_x = x -
		((fdf->size->x - fdf->size->y) * (fdf->tile_width) / 2) / 2;
	fdf->begin_y = y -
		(fdf->size->x + fdf->size->y) * (fdf->tile_height / 2) / 2;
	ft_draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win->win, fdf->img->img, 0, 0);
	return (1);
}

int		ft_handle_keys(int keycode, t_fdf *fdf)
{
	if (keycode == FT_ESC)
		ft_exit_fdf(fdf);
	else if (keycode == FT_PLUS)
		ft_modify_alt_quota(fdf, 1);
	else if (keycode == FT_MINUS)
		ft_modify_alt_quota(fdf, -1);
	else if (keycode == FT_WILDCARD)
		ft_modify_tiles_length(fdf, 2);
	else if (keycode == FT_DIVIDE && fdf->tile_height - 2 >= 1)
		ft_modify_tiles_length(fdf, -2);
	else if (keycode == FT_LEFT)
		ft_move_horizontal(fdf, -20);
	else if (keycode == FT_RIGHT)
		ft_move_horizontal(fdf, 20);
	else if (keycode == FT_UP)
		ft_move_vertical(fdf, -20);
	else if (keycode == FT_DOWN)
		ft_move_vertical(fdf, 20);
	else if (keycode == FT_H && !fdf->hud)
		ft_init_hud(fdf, 500, WIN_HEIGHT / 2);
	else if (keycode == FT_H && fdf->hud)
		ft_destroy_hud(fdf);
	return (1);
}
