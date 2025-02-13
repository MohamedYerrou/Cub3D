/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:00:56 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/20 21:19:33 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(len1 + len2 + 1);
	if (res == NULL)
		return (NULL);
	ft_memmove(res, s1, len1);
	ft_memmove(res + len1, s2, len2);
	res[len1 + len2] = '\0';
	return (res);
}
// int main()
// {
// 	//const char* string1 = "Hello, ";
// 	//const char* string2 = "World!";
// 	printf("%s" , ft_strjoin("med", NULL));

// 	//if (joined != NULL)
// 	//{
// 	//	printf("Joined: %s\n", joined);
// //		free(joined);
// }
// 	// else
// 	// 	printf("Invalid input strings or memory allocation failed.\n");
// 	// return 0;