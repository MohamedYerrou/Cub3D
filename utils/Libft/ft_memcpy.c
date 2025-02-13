/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:22:01 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/18 09:58:18 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
/*
int main()
{
	int i;
	double src_arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double dst_arr[5];
	char src[] = "Mohamed is here";
	char dst[100];

	char *dst_ptr = ft_memcpy(dst, src, strlen(src) + 1);
	printf("src : %s\n", src);
	printf("dst : %s\n", dst);

	printf("dst_ptr : %p\n", dst_ptr);
	printf("    dst : %p\n", dst);

	i = 0;
	ft_memcpy(dst_arr, src_arr, sizeof(src_arr));
	while (i < 5)
	{
		printf("dst_arr[%d] = %f\n", i, dst_arr[i]);
		i++;
	}

	char *dst_ptr = memcpy(dst, src, strlen(src) + 1);
	printf("src : %s\n", src);
	printf("dst : %s\n", dst);

	printf("dst_ptr : %p\n", dst_ptr);
	printf("    dst : %p\n", dst);

	i = 0;
	memcpy(dst_arr, src_arr, sizeof(src_arr));
	while (i < 5)
	{
		printf("dst_arr[%d] = %f\n", i, dst_arr[i]);
		i++;
	}
}*/