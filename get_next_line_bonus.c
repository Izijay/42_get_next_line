/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:06:41 by mdupuis           #+#    #+#             */
/*   Updated: 2021/02/04 14:25:48 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char		*new_l(char *str)
{
	int			i;
	char		*ret;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char		*next_l(char *to_read)
{
	char		*ret;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!to_read)
		return (0);
	while (to_read[i] && to_read[i] != '\n')
		i++;
	if (!to_read[i])
	{
		free(to_read);
		return (0);
	}
	if (!(ret = (char *)malloc(sizeof(char) * ((ft_strlen(to_read) - i) + 1))))
		return (0);
	i++;
	while (to_read[i])
		ret[j++] = to_read[i++];
	ret[j] = '\0';
	free(to_read);
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*to_read[LIMIT];
	int			r;

	r = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!check_gnl(to_read[fd]) && r != 0)
	{
		if ((r = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[r] = '\0';
		to_read[fd] = strjoin_gnl(to_read[fd], buff);
	}
	free(buff);
	*line = new_l(to_read[fd]);
	to_read[fd] = next_l(to_read[fd]);
	if (r == 0)
		return (0);
	return (1);
}
