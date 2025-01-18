/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:33:00 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/09 15:39:38 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (dup == NULL)
		return (NULL);
	while (*s1)
		dup[i++] = *s1++;
	dup[i] = '\0';
	return (dup);
}
/*
int	main(int ac, char **av)
{
	char *me;
	char *him;

	if (ac == 2)
	{
	me = ft_strdup(av[1]);
	him = strdup(av[1]);
	printf("*%s*\n*%s*\n", me, him);
	}
}*/