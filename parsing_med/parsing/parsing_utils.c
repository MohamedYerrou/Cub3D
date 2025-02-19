/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:57:30 by myerrou           #+#    #+#             */
/*   Updated: 2025/02/19 09:20:45 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	spaces(char c)
{
	if (c != ' ' && c != '\t' && c != '\r'
		&& c != '\n' && c != '\v' && c != '\f')
		return (FAILURE);
	else
		return (SUCCESS);
}

size_t	max_len(t_mapdet map, int i)
{
	size_t	biggest_len;

	if (!map.file[i])
		return (0);
	biggest_len = ft_strlen(map.file[i]);
	while (map.file[i])
	{
		if (ft_strlen(map.file[i]) > biggest_len)
			biggest_len = ft_strlen(map.file[i]);
		i++;
	}
	return (biggest_len);
}
