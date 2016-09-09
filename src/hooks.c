/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 17:08:20 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/15 17:01:51 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_exit_fdf(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win->win);
	free(fdf->win);
	ft_destroy_hud(fdf);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	free(fdf->img);
	ft_free_parse(fdf->parse);
	ft_lstdel(&fdf->map);
	free(fdf);
	exit(1);
}

int			ft_handle_hud_win_sequel(int x, int y, t_fdf *fdf)
{
	if (x >= 300 && x <= 400 && y >= 270 && y <= 370)
		ft_modify_color(fdf, 0x0000FF);
	else if (x >= 100 && x <= 200 && y >= 370 && y <= 470)
		ft_modify_color(fdf, 0xFFFF00);
	else if (x >= 200 && x <= 300 && y >= 370 && y <= 470)
		ft_modify_color(fdf, 0x0);
	else if (x >= 300 && x <= 400 && y >= 370 && y <= 470)
		ft_modify_color(fdf, 0xFF00FF);
	else if (x >= 100 && x <= 200 && y >= 470 && y <= 570)
		ft_modify_color(fdf, 0x00FFFF);
	else if (x >= 200 && x <= 300 && y >= 470 && y <= 570)
		ft_modify_color(fdf, 0xFFFFFF);
	else if (x >= 300 && x <= 400 && y >= 470 && y <= 570)
		ft_modify_color(fdf, 0xF5B041);
	return (1);
}

int			ft_handle_hud_win(int button, int x, int y, t_fdf *fdf)
{
	(void)button;
	if (x >= 355 && x <= 395 && y >= 10 && y <= 50)
		ft_move_vertical(fdf, -20);
	else if (x >= 315 && x <= 355 && y >= 50 && y <= 90)
		ft_move_horizontal(fdf, -20);
	else if (x >= 395 && x <= 435 && y >= 50 && y <= 90)
		ft_move_horizontal(fdf, 20);
	else if (x >= 355 && x <= 395 && y >= 90 && y <= 130)
		ft_move_vertical(fdf, 20);
	else if (x >= 315 && x <= 335 && y >= 160 && y <= 180)
		ft_modify_alt_quota(fdf, -1);
	else if (x >= 415 && x <= 435 && y >= 160 && y <= 180)
		ft_modify_alt_quota(fdf, 1);
	else if (x >= 315 && x <= 335 && y >= 190 && y <= 210 &&
			fdf->tile_height - 2 >= 1)
		ft_modify_tiles_length(fdf, -2);
	else if (x >= 415 && x <= 435 && y >= 190 && y <= 210)
		ft_modify_tiles_length(fdf, 2);
	else if (x >= 100 && x <= 200 && y >= 270 && y <= 370)
		ft_modify_color(fdf, 0xFF0000);
	else if (x >= 200 && x <= 300 && y >= 270 && y <= 370)
		ft_modify_color(fdf, 0x00FF00);
	else
		return (ft_handle_hud_win_sequel(x, y, fdf));
	return (1);
}
