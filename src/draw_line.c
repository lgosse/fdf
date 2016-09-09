/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:48:47 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/15 15:13:15 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_addcolor(int color, int add)
{
	int col;

	col = color;
	if ((char)col == 0)
		col += (unsigned char)add;
	if ((char)(col >> 8) == 0)
		col += ((unsigned char)add << 8);
	if ((char)(col >> 16) == 0)
		col += ((unsigned char)add << 16);
	return (col);
}

int			ft_getcolor(t_fdf *fdf, t_pos *alt, t_pos *pos, t_seg *seg)
{
	int alti;
	int color;
	int add;

	color = fdf->color;
	add = 0;
	if (color != 0xFFFFFF)
	{
		if (alt->x != alt->y && (seg->x2 * seg->y2 - seg->x1 * seg->y1) != 0)
		{
			alti = (seg->x1 * seg->y1 - pos->x * pos->y) * (alt->y - alt->x) /
				(seg->x1 * seg->y1 - seg->x2 * seg->y2);
			alti -= fdf->extremes->y - (alt->x);
			alti = alti < 0 ? fdf->extremes->x + alti : alti;
			add = (alti * 255) / (fdf->extremes->x - fdf->extremes->y);
			color = ft_addcolor(color, add);
		}
		else if (alt->x != 0)
		{
			add = (alt->x * 255) / (fdf->extremes->x - fdf->extremes->y);
			add = add < 0 ? -add : add;
			color = ft_addcolor(color, add);
		}
	}
	return (color);
}

void		ft_put_line(t_fdf *fdf, t_seg *seg, int alt_begin, int alt_end)
{
	int		x;
	int		y;
	t_pos	pos;
	t_pos	alt;

	x = seg->x1;
	alt.x = alt_begin;
	alt.y = alt_end;
	while (x <= seg->x2)
	{
		if (seg->x1 != seg->x2)
			y = seg->y1 + ((seg->y2 - seg->y1) * (x - seg->x1)) /
				(seg->x2 - seg->x1);
		else
			y = seg->y2;
		pos.x = x;
		pos.y = y;
		if (x >= 0 && x < fdf->win->width && y >= 0 && y < fdf->win->height)
		{
			ft_pixel_put_to_image(fdf->img, x, y,
			ft_getcolor(fdf, &alt, &pos, seg));
		}
		x++;
	}
}

void		ft_put_line2(t_fdf *fdf, t_seg *seg, int alt_begin, int alt_end)
{
	int		x;
	int		y;
	t_pos	pos;
	t_pos	alt;

	y = seg->y1;
	alt.x = alt_begin;
	alt.y = alt_end;
	while (y <= seg->y2)
	{
		if (seg->y1 != seg->y2)
			x = seg->x1 + ((seg->x2 - seg->x1) * (y - seg->y1)) /
				(seg->y2 - seg->y1);
		else
			x = seg->x2;
		pos.x = x;
		pos.y = y;
		if (x > 0 && x < fdf->win->width && y > 0 && y < fdf->win->height)
			ft_pixel_put_to_image(fdf->img, x, y,
			ft_getcolor(fdf, &alt, &pos, seg));
		y++;
	}
}

void		ft_draw_line(t_fdf *fdf, t_seg *seg, int alt_begin, int alt_end)
{
	if (ft_abs(seg->x2 - seg->x1) > ft_abs(seg->y2 - seg->y1))
	{
		if (seg->x2 - seg->x1 > 0)
			ft_put_line(fdf, seg, alt_begin, alt_end);
		else
		{
			ft_swap_int(&seg->x1, &seg->x2);
			ft_swap_int(&seg->y1, &seg->y2);
			ft_put_line(fdf, seg, alt_begin, alt_end);
		}
	}
	else if (seg->y2 - seg->y1 > 0)
	{
		ft_put_line2(fdf, seg, alt_begin, alt_end);
	}
	else
	{
		ft_swap_int(&seg->x1, &seg->x2);
		ft_swap_int(&seg->y1, &seg->y2);
		ft_put_line2(fdf, seg, alt_begin, alt_end);
	}
}
