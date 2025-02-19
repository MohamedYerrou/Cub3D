/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:45:55 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/14 20:46:46 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !(*lst) || !del)
		return ;
	if ((*lst)->next)
		ft_lstclear((&(*lst)->next), del);
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
// void del_content(void *content)
// {
//     free(content);
// }

// int main()
// {
//     t_list *list = malloc(sizeof(t_list));
//     list->content = malloc(sizeof(int));
//     *(int *)(list->content) = 42;
//     list->next = NULL;

//     ft_lstclear(&list, del_content);

//     return 0;
// }