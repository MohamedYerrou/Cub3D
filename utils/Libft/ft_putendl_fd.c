/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:05:48 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/12 10:08:22 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
// int	main()
// {
// 	char *str = "HELLO WORLD !";
// 	int fd = open("HE.txt", O_RDWR | O_CREAT , "rwx");
// 	ft_putendl_fd(str, fd);
// 	close(fd);
// }