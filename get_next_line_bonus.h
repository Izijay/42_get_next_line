/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:11:36 by mdupuis           #+#    #+#             */
/*   Updated: 2021/02/04 14:15:11 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define LIMIT 2147483647

int			get_next_line(int fd, char **line);
int			check_gnl(char *str);
size_t		ft_strlen(const char *s);
char		*strjoin_gnl(const char *s1, const char *s2);

#endif
