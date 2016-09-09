/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 15:23:34 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/15 15:50:24 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_grey_square(t_fdf *fdf, int x1, int y1, int size)
{
	int x;
	int y;

	y = y1;
	while (y <= y1 + size)
	{
		x = x1;
		while (x <= x1 + size)
		{
			mlx_pixel_put(fdf->mlx, fdf->hud->win, x, y, 0x929292);
			x++;
		}
		y++;
	}
}

void		ft_color_square(t_fdf *fdf, int x1, int y1, int color)
{
	int x;
	int y;

	y = y1;
	while (y <= y1 + 100)
	{
		x = x1;
		while (x <= x1 + 100)
		{
			mlx_pixel_put(fdf->mlx, fdf->hud->win, x, y, color);
			x++;
		}
		y++;
	}
}

char		**ft_init_infos(t_fdf *fdf)
{
	char **infos;

	infos = NULL;
	infos = (char **)malloc(sizeof(char *) * 8);
	infos[7] = NULL;
	infos[0] = ft_itoa(fdf->win->width);
	infos[1] = ft_itoa(fdf->win->height);
	infos[2] = ft_itoa(fdf->tile_width);
	infos[3] = ft_itoa(fdf->tile_height);
	infos[4] = ft_itoa(fdf->alt_quota);
	infos[5] = ft_itoa(fdf->begin_x);
	infos[6] = ft_itoa(fdf->begin_y);
	return (infos);
}

void		ft_draw_infos(t_fdf *fdf)
{
	char **infos;

	infos = ft_init_infos(fdf);
	mlx_string_put(fdf->mlx, fdf->hud->win, 180, 10, 0xFFFFFF, infos[0]);
	mlx_string_put(fdf->mlx, fdf->hud->win, 180, 40, 0xFFFFFF, infos[1]);
	mlx_string_put(fdf->mlx, fdf->hud->win, 180, 70, 0xFFFFFF, infos[2]);
	mlx_string_put(fdf->mlx, fdf->hud->win, 180, 110, 0xFFFFFF, infos[3]);
	mlx_string_put(fdf->mlx, fdf->hud->win, 180, 150, 0xFFFFFF, infos[4]);
	mlx_string_put(fdf->mlx, fdf->hud->win, 180, 180, 0xFFFFFF, infos[5]);
	mlx_string_put(fdf->mlx, fdf->hud->win, 180, 210, 0xFFFFFF, infos[6]);
	ft_delinfos(infos);
}

void		ft_draw_buttons(t_fdf *fdf)
{
	ft_grey_square(fdf, 355, 10, 40);
	ft_grey_square(fdf, 315, 50, 40);
	ft_grey_square(fdf, 395, 50, 40);
	ft_grey_square(fdf, 355, 90, 40);
	ft_grey_square(fdf, 315, 160, 20);
	ft_grey_square(fdf, 315, 190, 20);
	ft_grey_square(fdf, 415, 160, 20);
	ft_grey_square(fdf, 415, 190, 20);
	mlx_string_put(fdf->mlx, fdf->hud->win, 370, 20, 0x0, "U");
	mlx_string_put(fdf->mlx, fdf->hud->win, 330, 60, 0x0, "L");
	mlx_string_put(fdf->mlx, fdf->hud->win, 410, 60, 0x0, "R");
	mlx_string_put(fdf->mlx, fdf->hud->win, 370, 100, 0x0, "D");
	mlx_string_put(fdf->mlx, fdf->hud->win, 360, 160, 0xFFFFFF, "alt");
	mlx_string_put(fdf->mlx, fdf->hud->win, 355, 190, 0xFFFFFF, "zoom");
	mlx_string_put(fdf->mlx, fdf->hud->win, 320, 161, 0x0, "-");
	mlx_string_put(fdf->mlx, fdf->hud->win, 420, 161, 0x0, "+");
	mlx_string_put(fdf->mlx, fdf->hud->win, 320, 191, 0x0, "-");
	mlx_string_put(fdf->mlx, fdf->hud->win, 420, 191, 0x0, "+");
}
