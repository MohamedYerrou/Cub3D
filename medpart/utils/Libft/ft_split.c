/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:06:06 by myerrou           #+#    #+#             */
/*   Updated: 2023/11/19 14:04:55 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(const char *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cnt);
}

static void	ft_test(char **sub, size_t i, size_t j)
{
	j = 0;
	while (j < i)
	{
		free(sub[j]);
		j++;
	}
	free(sub);
}

static int	creat_string(const char *s, char c, char **sub, size_t len)
{
	size_t	i;

	i = 0;
	while (s && *s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			sub[i] = ft_substr(s - len, 0, len);
			if (!sub[i])
			{
				ft_test(sub, i, 0);
				return (0);
			}
			i++;
		}
		else
			s++;
	}
	sub[i] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**sub;

	if (!s)
		return (NULL);
	sub = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!sub)
		return (NULL);
	if (creat_string(s, c, sub, 0) == 0)
		return (NULL);
	return (sub);
}
/*
int	main(void)
{
	char *str = NULL;
	char c = 0;
	char **res = ft_split(str, c);
	printf("%s\n", (char *)res);
}*/