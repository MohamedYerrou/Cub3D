/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:58:19 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/16 15:54:29 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == src)
		return (dst);
	if (src < dst)
	{
		while (len--)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/*
int main()
{
	char source[] = "Hello, World!";
    char destination[6] = "World";
	char src[] = "Hello, World!";
	char dest[6] = "World";

    ft_memmove(source, source, 14);
    printf("Destination after custom memmove: %s\n", source);

	memmove(src, src, 14);
	printf("Destination after original memmove: %s\n", src);
	
    return 0;
}*/