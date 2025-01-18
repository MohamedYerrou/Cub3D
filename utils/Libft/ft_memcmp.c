/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:36:34 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/03 14:52:29 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	 unsigned char data1[] = {0x10, 0x20, 0x30, 0x40, 0x50};
    unsigned char data2[] = {0x10, 0x20, 0x35, 0x40, 0x50};
    size_t num_bytes = sizeof(data1);

    int result = ft_memcmp(data1, data2, num_bytes);

    if (result == 0) {
        printf("Memory blocks are equal\n");
    } else if (result < 0) {
        printf("Memory block 1 is less than block 2\n");
    } else {
        printf("Memory block 1 is greater than block 2\n");
    }
	return (0);
}*/