/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 11:46:07 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/14 11:55:30 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pos		*ft_init_size(t_list *map)
{
	t_pos *size;

	size = (t_pos *)malloc(sizeof(t_pos) * 1);
	size->x = (map->content_size / sizeof(int));
	size->y = 0;
	while (map)
	{
		map = map->next;
		size->y++;
	}
	return (size);
}

t_pos		*ft_init_extremes(t_list *map)
{
	t_pos	*extremes;
	int		i;
	int		*line;

	extremes = (t_pos *)malloc(sizeof(t_pos) * 1);
	extremes->x = 0;
	extremes->y = 0;
	while (map)
	{
		line = map->content;
		i = 0;
		while (i < (int)(map->content_size / sizeof(int)))
		{
			if (extremes->x < line[i])
				extremes->x = line[i];
			if (extremes->y > line[i])
				extremes->y = line[i];
			i++;
		}
		map = map->next;
	}
	return (extremes);
}
