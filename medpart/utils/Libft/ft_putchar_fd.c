/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:00:04 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/11 18:11:38 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
// int	main()
// {
// 	char c;
// 	c = 'A';
// 	int fd = open("YER.txt", O_RDWR | O_CREAT, "rwx" );
// 	ft_putchar_fd(c, fd);
// 	close(fd);
// }