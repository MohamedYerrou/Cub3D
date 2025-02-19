/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:44:54 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/20 21:23:44 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
// void free_content(void *content)
// {
//     free(content);
// }

// int main()
// {
//     // Create a linked list with a single node
//     t_list *node = malloc(sizeof(t_list));
//     node->content = malloc(sizeof(int));
//     *(int *)(node->content) = 42;
//     node->next = NULL;

//     // Delete the node using ft_lstdelone
//     ft_lstdelone(node, free_content);

//     return (0);
// }