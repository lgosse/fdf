/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:39:09 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/07 14:45:40 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_checkstr(char *chars, char *cmp)
{
	int i;

	i = 0;
	if (chars == NULL)
		return (1);
	while (ft_strchr(chars, cmp[i]))
		i++;
	if (cmp[i] != '\0')
		return (0);
	return (1);
}
