/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:47:51 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/20 21:20:29 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && char_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && char_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
/*
int main()
{
	const char *s1 = "                                  ";
	const char *set = " ";
	printf("original: \"%s\"\n", s1);
	char* trimmed = ft_strtrim(s1, set);
	if (trimmed != NULL)
	{
		printf("Trimmed: \"%s\"\n", trimmed);
		free(trimmed);
	}
	else
		printf("Memory allocation failed or the entire input is in the set.\n");
}
*/