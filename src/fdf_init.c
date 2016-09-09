/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 11:38:32 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/15 11:47:30 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_list		*ft_getmap(char *filename)
{
	t_list	*file;
	t_list	*tmp;
	t_list	*map;
	int		i;

	file = ft_parse_file(filename, NULL);
	tmp = file;
	i = 0;
	while (tmp && ++i)
		tmp = tmp->next;
	map = NULL;
	while (file)
	{
		ft_nbrsplit(&map, (char *)file->content);
		if (!map && ft_printf("Error malloc\n"))
			exit(0);
		file = file->next;
	}
	return (map);
}

t_win		*ft_init_win(t_fdf *fdf, int width, int height)
{
	t_win	*win;

	win = NULL;
	if ((win = (t_win *)malloc(sizeof(t_win) * 1)))
	{
		win->width = width;
		win->height = height;
		win->win = mlx_new_window(fdf->mlx, width, height,
			fdf->parse->args->content);
	}
	return (win);
}

t_img		*ft_init_img(t_fdf *fdf)
{
	t_img	*img;

	img = NULL;
	if ((img = (t_img *)malloc(sizeof(t_img) * 1)))
	{
		img->img = mlx_new_image(fdf->mlx, fdf->win->width, fdf->win->height);
		img->data = mlx_get_data_addr(img->img, &img->bpp, &img->sline,
			&img->endian);
	}
	return (img);
}

t_fdf		*ft_init_fdf(int ac, char **av)
{
	t_parse		*parse;
	t_fdf		*fdf;

	fdf = NULL;
	if ((!(parse = ft_parse(ac, av, "h")) || !parse->args) &&
		ft_printf("Error\n"))
		return (NULL);
	if ((fdf = (t_fdf *)malloc(sizeof(t_fdf) * 1)))
	{
		fdf->parse = parse;
		if (!(fdf->map = ft_getmap(parse->args->content)))
			return (NULL);
		fdf->tile_height = 32;
		fdf->tile_width = 2 * fdf->tile_height;
		fdf->alt_quota = 2;
		fdf->color = 0xFFFFFF;
		fdf->mlx = mlx_init();
	}
	else
	{
		ft_printf("Error malloc\n");
		return (0);
	}
	return (fdf);
}
