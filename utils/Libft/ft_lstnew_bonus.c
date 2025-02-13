/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:53:44 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/20 21:50:34 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
// int main()
// {
//     int data = 42;
//     t_list *node = ft_lstnew(&data);

//     if (node != NULL)
// 	{
//         printf("Node created successfully!\n");
//         printf("Content: %d\n", *(int*)node->content);
//     }
//     return (0);
// }