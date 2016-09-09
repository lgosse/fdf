/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 11:05:39 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/15 15:33:23 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_testprint(t_list *map)
{
	size_t	i;
	int		*tmp;

	while (map)
	{
		i = 0;
		tmp = map->content;
		while (i < (map->content_size / sizeof(int)))
		{
			ft_printf("%3d", tmp[i]);
			i++;
		}
		ft_printf("\n");
		map = map->next;
	}
}

void		ft_init_begin(t_fdf *fdf)
{
	fdf->begin_x = fdf->win->width / 2 -
		((fdf->size->x - fdf->size->y) * (fdf->tile_width) / 2) / 2;
	fdf->begin_y = fdf->win->height / 2 -
		(fdf->size->x + fdf->size->y) * (fdf->tile_height / 2) / 2;
}

int			ft_mlx_part(t_fdf *fdf)
{
	fdf->win = NULL;
	fdf->hud = NULL;
	if (fdf->parse->args && fdf->parse->args->next &&
		fdf->parse->args->next->next)
	{
		if (!fdf->win && !(fdf->win = ft_init_win(fdf,
				ft_atoi(fdf->parse->args->next->content),
				ft_atoi(fdf->parse->args->next->next->content))))
			return (ft_printf("Error malloc\n"));
	}
	else if (!(fdf->win = ft_init_win(fdf, WIN_WIDTH, WIN_HEIGHT)))
		return (ft_printf("Error malloc\n"));
	if (!(fdf->img = ft_init_img(fdf)) ||
		!(fdf->size = ft_init_size(fdf->map)) ||
		!(fdf->extremes = ft_init_extremes(fdf->map)))
		return (ft_printf("Error malloc\n"));
	ft_init_begin(fdf);
	ft_draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win->win, fdf->img->img, 0, 0);
	mlx_key_hook(fdf->win->win, ft_handle_keys, fdf);
	mlx_mouse_hook(fdf->win->win, ft_handle_graph_win, fdf);
	mlx_loop(fdf->mlx);
	return (1);
}

int			main(int ac, char **av)
{
	t_fdf		*fdf;

	if (!(fdf = ft_init_fdf(ac, av)))
		return (0);
	fdf->win = NULL;
	return (ft_mlx_part(fdf));
}
