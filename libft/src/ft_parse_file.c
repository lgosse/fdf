/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 15:12:59 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/07 17:13:58 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_parse_file(char *filename, char *chars)
{
	int		fd;
	t_list	*file;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file = NULL;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (!ft_checkstr(chars, line))
		{
			ft_lstdel(&file);
			return (NULL);
		}
		else
			ft_lstaddtail(&file, ft_lstnew(line, ft_strlen(line) + 1));
		ft_memdel((void **)&line);
	}
	return (file);
}
