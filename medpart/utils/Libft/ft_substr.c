/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:14:20 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/11 15:51:56 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sl;

	if (!s)
		return (NULL);
	sl = ft_strlen(s);
	if (start >= sl)
		return (ft_strdup("\0"));
	if (len > sl - start)
		len = sl - start;
	sub = (char *)malloc(sizeof(*s) * (len + 1));
	if (!sub)
		return (0);
	ft_strlcpy(sub, (char *)s + start, len + 1);
	return (sub);
}
/*
int	main(void)
{
	const char	*original = "Hello, World!";
	unsigned int start_index = 7;  // Start index of the substring
	int substring_length = 5;  // Length of the substring

	char* sub = ft_substr(original, start_index, substring_length);

	if (sub != NULL) {
		printf("Original: %s\n", original);
		printf("Substring: %s\n", sub);
		free(sub);
	} else {
		printf("Invalid input parameters.\n");
	}

	return (0);
}*/