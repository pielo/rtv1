/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 19:13:25 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/23 18:50:30 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <libft.h>
#include <stdlib.h>
#include <get_next_line.h>

static int			ft_one(int fd, char *buff, char **line, char **str)
{
	size_t			i;

	i = 0;
	while (i < BUFF_SIZE && buff[i] != '\n')
		i++;
	if (i != BUFF_SIZE)
	{
		*line = ft_strjoin(*str, ft_strsub(buff, 0, i));
		*str = ft_strsub(buff, i + 1, BUFF_SIZE);
	}
	else
	{
		*str = ft_strjoin(*str, ft_strsub(buff, 0, BUFF_SIZE));
		get_next_line(fd, line);
	}
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	char			buff[BUFF_SIZE + 1] = {0};
	static char		*str;
	int				res;
	char			*t;

	*line = ft_strnew(0);
	if (str == NULL)
		str = ft_strnew(0);
	if ((t = ft_strchr(str, '\n')) != NULL)
	{
		*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(t));
		str = ft_strsub(str, ft_strlen(str) - ft_strlen(t) + 1, ft_strlen(t));
		return (1);
	}
	res = read(fd, buff, BUFF_SIZE);
	if (res == -1)
	{
		free (str);
		return (-1);
	}
	if (res > 0)
		return (ft_one(fd, buff, &*line, &str));
	free (str);
	return (0);
}
