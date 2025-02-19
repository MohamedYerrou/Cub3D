/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:42:46 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/14 20:43:48 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
// int main()
// {
//     // Create a linked list
//     t_list *node1 = malloc(sizeof(t_list));
//     t_list *node2 = malloc(sizeof(t_list));
//     t_list *node3 = malloc(sizeof(t_list));

//     node1->data = 1;
//     node1->next = node2;
//     node2->data = 2;
//     node2->next = node3;
//     node3->data = 3;
//     node3->next = NULL;

//     // Find the last node
//     t_list *lastNode = ft_lstlast(node1);

//     // Print the data of the last node
//     printf("Last node data: %d\n", lastNode->data);

//     return (0);
// }