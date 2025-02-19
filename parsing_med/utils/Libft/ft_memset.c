/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:14:14 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/10 15:53:13 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = (char)c;
		i++;
	}
	return (b);
}
// int main()
// {
//     char	arr[6] = {1,2,3,4,5,6};
// 	char	ar[6] = {1,2,3,4,5,6};

//     ft_memset(arr, 0xff, sizeof(char) * 3);
//     printf("Memory filled ft_memset (using while loop):\n");

//     for (int i = 0; i < 6; i++)
// 	{
//         printf("arr[%d] = %c\n", i, arr[i]);
//     }

// 	memset(ar, 0xff, sizeof(char) * 3);
// 	printf("Memory filled with original memset :\n");

//     for (int i = 0; i < 6; i++)
// 	{
//         printf("arr[%d] = %c\n", i, ar[i]);
//     }
//     return 0;
// }
// int main ()
// {
// 	int a;
// 	a = 3;
// 	ft_memset(&a, 255, 4);
// 	ft_memset(&a, 250, 2);
// 	ft_memset(&a, 199, 1);
// 	printf("%d\n",a);//=== min int
// }