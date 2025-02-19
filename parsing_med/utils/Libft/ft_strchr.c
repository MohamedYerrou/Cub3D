/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:44:05 by myerrou           #+#    #+#             */
/*   Updated: 2025/02/19 09:46:44 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if (!str)
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
	char	*str = "testest tsteeee";
	char	*c;
	char	*d;

	c = strchr(str, '\0');
	d = ft_strchr(str, '\0');

	printf("*%s*\n", c);
	printf("*%s*\n", d);
	return NULL;
}*/
