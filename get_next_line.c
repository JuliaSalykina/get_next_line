/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:56:39 by mannette          #+#    #+#             */
/*   Updated: 2019/12/12 16:30:45 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	findline(char **str, char **line, int fd)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = ft_strchr(str[fd], '\n');
	if (s1)
	{
		s2 = ft_strdup(s1 + 1);
		i = s1 - str[fd];
		*line = ft_strsub(str[fd], 0, i);
		ft_strdel(&str[fd]);
		str[fd] = s2;
		return (1);
	}
	else if (str[fd][0])
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[10240];
	char		buff[BUFF_SIZE + 1];
	char		*ready;
	int			result;

	if (fd < 0 || read(fd, buff, 0) < 0 || !line
			|| fd > 10240 || BUFF_SIZE <= 0)
		return (-1);
	while ((result = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[result] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		ready = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = ready;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (result < 0)
		return (-1);
	else if (result == 0 && str[fd] == NULL)
		return (0);
	return (findline(str, line, fd));
}
