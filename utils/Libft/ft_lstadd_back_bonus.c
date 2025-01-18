/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:35:47 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/14 20:36:31 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
// int main()
// {
// 	t_list *head = NULL;
// 	t_list *node1 = malloc(sizeof(t_list));
// 	t_list *node2 = malloc(sizeof(t_list));

// 	node1->data = 10;
// 	node1->next = NULL;

// 	node2->data = 20;
// 	node2->next = NULL;

// 	ft_lstadd_back(&head, node1);
// 	ft_lstadd_back(&head, node2);

// 	t_list *current = head;
// 	while (current != NULL)
// 	{
// 		printf("%d ", current->data);
// 		current = current->next;
// 	}

// 	return (0);
// }