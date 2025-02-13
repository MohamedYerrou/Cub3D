/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:58:29 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/20 21:21:51 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	n;

	if (!s || !f)
		return (NULL);
	i = 0;
	n = ft_strlen(s);
	str = (char *)malloc((n + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char ft_map(unsigned int x, char c)
{
	x = 1;
	return (c + x);
}

int main()
{

	const char *input = "Hello, World!";
	char *output = ft_strmapi(input, ft_map);
	
	if (output != NULL)
	{
		printf("Original: %s\n", input);
		printf("Transformed: %s\n", output);
		free(output);
	} 
	else 
		printf("Memory allocation error.\n");
	return (0);
}
*/