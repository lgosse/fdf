/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 14:10:10 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/15 16:17:25 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_init_hud(t_fdf *fdf, int width, int height)
{
	t_win	*hud;

	hud = NULL;
	if ((hud = (t_win *)malloc(sizeof(t_win) * 1)))
	{
		hud->width = width;
		hud->height = height;
		hud->win = mlx_new_window(fdf->mlx, width, height, "HUD");
		mlx_key_hook(hud->win, ft_handle_keys, fdf);
		mlx_mouse_hook(hud->win, ft_handle_hud_win, fdf);
		fdf->hud = hud;
		ft_draw_hud(fdf);
		ft_draw_buttons(fdf);
		ft_draw_colors(fdf);
		ft_draw_text(fdf);
	}
}

void		ft_draw_background_hud(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < 500)
		{
			mlx_pixel_put(fdf->mlx, fdf->hud->win, x, y, 0x929292);
			x++;
		}
		y++;
	}
}

void		ft_delinfos(char **infos)
{
	int i;

	i = 0;
	if (infos)
	{
		while (infos[i])
		{
			free(infos[i]);
			infos[i] = NULL;
			i++;
		}
		free(infos);
		infos = NULL;
	}
}

void		ft_draw_colors(t_fdf *fdf)
{
	ft_color_square(fdf, 100, 270, 0xFF0000);
	ft_color_square(fdf, 200, 270, 0x00FF00);
	ft_color_square(fdf, 300, 270, 0x0000FF);
	ft_color_square(fdf, 100, 370, 0xFFFF00);
	ft_color_square(fdf, 300, 370, 0xFF00FF);
	ft_color_square(fdf, 100, 470, 0x00FFFF);
	ft_color_square(fdf, 200, 470, 0xFFFFFF);
	ft_color_square(fdf, 300, 470, 0xF5B041);
}

void		ft_draw_hud(t_fdf *fdf)
{
	ft_clear_text(fdf);
	ft_draw_infos(fdf);
}
