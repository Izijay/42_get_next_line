/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:12:15 by mdupuis           #+#    #+#             */
/*   Updated: 2021/02/04 14:17:36 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t				ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static void			*memmove_gnl(void *dst, const void *src, size_t size)
{
	size_t		i;
	char		*mem_dst;
	char		*mem_src;

	i = 0;
	mem_dst = (char *)dst;
	mem_src = (char *)src;
	if (dst == src)
		return (dst);
	if (mem_src < mem_dst)
	{
		while (++i <= size)
			mem_dst[size - i] = mem_src[size - i];
		return (dst);
	}
	while (size--)
		*mem_dst++ = *mem_src++;
	return (dst);
}

char				*strjoin_gnl(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*join;

	if (!s1 && !s2)
		return (0);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	if (!(join = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	memmove_gnl(join, s1, len1);
	memmove_gnl(join + len1, s2, len2);
	join[len1 + len2] = '\0';
	free((char *)s1);
	return (join);
}

int					check_gnl(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
