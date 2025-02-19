/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:12:06 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/18 14:23:04 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	write (fd, s, ft_strlen(s));
}
// int	main()
// {
// 	char *str = "Mohamed Yerrou";
// 	int fd = open("Med.txt", O_RDWR | O_CREAT, "rwx");
// 	ft_putstr_fd(str, fd);
// 	close(fd);
// }