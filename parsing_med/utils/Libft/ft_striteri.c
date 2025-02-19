/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:59:22 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/22 11:00:09 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (i < ft_strlen(s))
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	*f(unsigned int x, char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] += x;
		i++;
	}
}
int main()
{
	unsigned int x = 2;
	char *str = "Hello ,World !";
	void *s = ft_striteri(str, f(x, str));
	printf ("%s", s);
}*/