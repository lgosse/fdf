/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 15:45:15 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/14 16:48:10 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_pixel_put_to_image(t_img *img, int x, int y, int color)
{
	int			i;
	char		*data;

	i = 0;
	data = img->data + y * img->sline + x * (img->bpp / 8);
	if (!img->endian)
	{
		data[i++] = (char)color;
		data[i++] = (char)(color >> 8);
		data[i] = (char)(color >> 16);
	}
	else
	{
		data[i++] = (char)(color >> 16);
		data[i++] = (char)(color >> 8);
		data[i] = (char)color;
	}
}

int			ft_calc_x(t_fdf *fdf, int x, int y)
{
	int		x2;

	x2 = 0;
	x2 = (x - y) * (fdf->tile_width / 2) + fdf->begin_x;
	return (x2);
}

int			ft_calc_y(t_list *map, t_fdf *fdf, int x, int y)
{
	int		y2;
	int		*tab;

	tab = map->content;
	y2 = (x + y) * (fdf->tile_height / 2) - (fdf->alt_quota * tab[x]) +
		fdf->begin_y;
	return (y2);
}

void		ft_calc_call_draw(t_list *map, t_fdf *fdf, t_pos *pos, t_seg *seg)
{
	int		*content;
	int		*content_next;

	seg->x1 = ft_calc_x(fdf, pos->x, pos->y);
	seg->y1 = ft_calc_y(map, fdf, pos->x, pos->y);
	if (pos->x + 1 < ((int)map->content_size / (int)sizeof(int)))
	{
		content = map->content;
		seg->x2 = ft_calc_x(fdf, pos->x + 1, pos->y);
		seg->y2 = ft_calc_y(map, fdf, pos->x + 1, pos->y);
		ft_draw_line(fdf, seg, content[pos->x], content[pos->x + 1]);
	}
	seg->x1 = ft_calc_x(fdf, pos->x, pos->y);
	seg->y1 = ft_calc_y(map, fdf, pos->x, pos->y);
	if (map->next && pos->x < ((int)map->next->content_size / (int)sizeof(int)))
	{
		content_next = map->next->content;
		seg->x2 = ft_calc_x(fdf, pos->x, pos->y + 1);
		seg->y2 = ft_calc_y(map->next, fdf, pos->x, pos->y + 1);
		ft_draw_line(fdf, seg, content[pos->x], content_next[pos->x]);
	}
}

void		ft_draw(t_fdf *fdf)
{
	t_list		*map;
	t_seg		*seg;
	t_pos		pos;

	map = fdf->map;
	seg = (t_seg *)malloc(sizeof(t_seg) * 1);
	pos.y = 0;
	while (map)
	{
		pos.x = 0;
		while (pos.x <= (int)map->content_size / (int)sizeof(int))
		{
			seg->x1 = 0;
			seg->x2 = 0;
			seg->y1 = 0;
			seg->y2 = 0;
			ft_calc_call_draw(map, fdf, &pos, seg);
			pos.x++;
		}
		map = map->next;
		pos.y++;
	}
	if (fdf->hud)
		ft_draw_hud(fdf);
}
