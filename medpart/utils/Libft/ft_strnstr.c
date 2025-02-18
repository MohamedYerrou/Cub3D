/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:04:22 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/18 18:12:21 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == 0)
		return ((char *)(haystack));
	if (len == 0)
		return (NULL);
	i = 0;
	while (haystack[i] && i < len && len > 0)
	{
		j = 0;
		while (needle[j] && (needle[j] == haystack[i + j] && i + j < len))
			j++;
		if (needle[j] == 0)
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	const char *haystack = "";
    const char *needle = NULL;
    size_t haystack_len = 0;

    char *result = strnstr(haystack, needle, haystack_len);

    if (result != NULL) {
        printf("Substring found: %s\n", result);
    } else {
        printf("Substring not found\n");
    }
	return (0);
}
*/