/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:54:38 by myerrou           #+#    #+#             */
/*   Updated: 2023/12/25 14:44:15 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include "../Libft/libft.h"

char	*get_strchr(char *s, int c);
char	*get_strdup(char *s1);
char	*get_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
