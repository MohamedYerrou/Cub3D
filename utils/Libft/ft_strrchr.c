/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:47:03 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/11 11:54:16 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	int		i;

	ptr = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			ptr = &((char *)str)[i];
		i++;
	}
	if ((char)c == '\0')
		ptr = &((char *)str)[i];
	return (ptr);
}
/*
int main()
{
	char *str = "Mohamed Yerrou";
	char *c;
	char *d;

	c = strrchr(str, 'x');
	d = ft_strrchr(str, 'x');

	printf("%s\n", c);
	printf("%s\n", d);
	return (0);
}*/