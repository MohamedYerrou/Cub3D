/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:22:52 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/14 20:35:24 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
// int main()
// {
//     // Create the head node
//     t_list *head = malloc(sizeof(t_list));
//     head->content = 1;
//     head->next = NULL;

//     // Create a new node
//     t_list *newNode = malloc(sizeof(t_list));
//     newNode->content = 2;
//     newNode->next = NULL;

//     // Add the new node at the front of the linked list
//     ft_lstadd_front(&head, newNode);

//     // Print the linked list
//     t_list *current = head;
//     while (current != NULL)
//     {
//         printf("%d ", current->content);
//         current = current->next;
//     }
//     return 0;
// }