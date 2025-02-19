/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:03:18 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/05 16:08:02 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
int main() {
    int arr[5] = {1,2,3,4,5};
    size_t num_elements = 2;

    ft_bzero(arr, num_elements* sizeof(int));

    printf("Memory cleared with custom bzero (using ft_memset):\n");
    for (size_t i = 0; i < 5; i++) {
        printf("arr[%zu] = %d\n", i, (unsigned char)arr[i]);
    }
	bzero(arr, num_elements * sizeof(int));

    printf("Memory cleared with bzero (using memset):\n");
    for (size_t i = 0; i < 5; i++) {
        printf("arr[%zu] = %d\n", i, (unsigned char)arr[i]);
    }

    return 0;
}*/
