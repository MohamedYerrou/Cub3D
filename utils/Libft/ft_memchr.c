/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:06:03 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/03 11:41:33 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}
/*
int main()
{
	unsigned char data[] = {0x10, 0x20, 0x30, 0x40, 0x50};
    size_t num_bytes = sizeof(data);

    int target = 0x30;
    void *result = ft_memchr(data, target, num_bytes);

    if (result != NULL) {
        size_t index = (unsigned char *)result - data;
        printf("Byte 0x%02X found at index %zu\n", target, index);
    } else {
        printf("Byte 0x%02X not found\n", target);
    }

    return 0;
}*/
