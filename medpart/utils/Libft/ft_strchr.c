/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:44:05 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/11 11:51:27 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if(!str)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}
/*
int main()
{
	char	*str = "teste";
	char	*c;
	char	*d;

	c = strchr(str, '\0');
	d = ft_strchr(str, '\0');

	printf("*%s*\n", c);
	printf("*%s*\n", d);
	return NULL;
}*/
