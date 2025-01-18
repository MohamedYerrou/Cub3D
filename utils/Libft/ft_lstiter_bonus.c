/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:47:22 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/14 20:56:14 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
}
// void print_int(void *data)
// {
//     int *ptr = (int *)data;
//     printf("%d\n", *ptr);
// }

// int main()
// {
//     t_list *list = NULL;

//     // Add elements to the linked list

//     ft_lstiter(list, print_int);

//     return (0);
// }