/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:09:54 by pferdina          #+#    #+#             */
/*   Updated: 2019/12/26 17:19:59 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		parse_line(char **line, char **storage)
{
	size_t	position;
	char	*temp;

	position = 0;
	while ((*storage)[position] != '\n' &&
			(*storage)[position] != '\0')
		position++;
	if ((*storage)[position] == '\n')
	{
		*line = ft_strsub(*storage, 0, position);
		temp = ft_strdup(&((*storage)[position + 1]));
		ft_strdel(storage);
		*storage = temp;
		if (*storage[0] == '\0')
			ft_strdel(storage);
	}
	else
	{
		*line = ft_strdup(*storage);
		ft_strdel(storage);
	}
	return (1);
}

int		result(ssize_t buff_size, char **storage, char **line)
{
	if (buff_size < 0)
		return (-1);
	if (!(*storage) && !buff_size)
		return (0);
	else
		return (parse_line(line, &(*storage)));
}

char	*strjoinf(char *storage, char *buffer)
{
	char	*result;

	result = ft_strjoin(storage, buffer);
	ft_strdel(&storage);
	return (result);
}

int		get_next_line(int fd, char **line)
{
	static char	*storage[OPEN_MAX];
	ssize_t		buff_size;
	char		buffer[BUFF_SIZE + 1];

	if (fd < 0 || !line)
		return (-1);
	while ((buff_size = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[buff_size] = '\0';
		if (!storage[fd])
			storage[fd] = ft_strdup(buffer);
		else
			storage[fd] = strjoinf(storage[fd], buffer);
		if (ft_strchr(storage[fd], '\n'))
			break ;
	}
	return (result(buff_size, &storage[fd], line));
}
