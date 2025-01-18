/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:37:55 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/14 20:55:09 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
// int main()
// {
//     // Create a linked list with 3 nodes
//     t_list node1, node2, node3;
//     node1->data = 10;
//     node1->next = &node2;
//     node2->data = 20;
//     node2->next = &node3;
//     node3->data = 30;
//     node3->next = NULL;

//     // Calculate the size of the linked list
//     int size = ft_lstsize(&node1);

//     // Print the size
//     printf("Size of the linked list: %d\n", size);

//     return (0);
// }