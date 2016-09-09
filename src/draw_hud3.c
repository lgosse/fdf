/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 15:39:10 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/15 15:50:22 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_clear_text(t_fdf *fdf)
{
	void	*win;
	int		x;
	int		y;

	win = fdf->hud->win;
	x = 180;
	y = 0;
	while (y <= 230)
	{
		x = 180;
		while (x <= 280)
		{
			mlx_pixel_put(fdf->mlx, win, x, y, 0x0);
			x++;
		}
		y++;
	}
}

void		ft_draw_text(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->hud->win, 10, 10, 0xFFFFFF, "WIDTH : ");
	mlx_string_put(fdf->mlx, fdf->hud->win, 10, 40, 0xFFFFFF, "HEIGHT : ");
	mlx_string_put(fdf->mlx, fdf->hud->win, 10, 70, 0xFFFFFF, "TILE_WIDTH : ");
	mlx_string_put(fdf->mlx, fdf->hud->win, 10, 110, 0xFFFFFF,
		"TILE_HEIGHT : ");
	mlx_string_put(fdf->mlx, fdf->hud->win, 10, 150, 0xFFFFFF,
		"ALTITUDE QUOTA : ");
	mlx_string_put(fdf->mlx, fdf->hud->win, 10, 180, 0xFFFFFF, "BEGIN_X : ");
	mlx_string_put(fdf->mlx, fdf->hud->win, 10, 210, 0xFFFFFF, "BEGIN_Y : ");
	mlx_string_put(fdf->mlx, fdf->hud->win, 10, 240, fdf->color, "COLOR");
}
