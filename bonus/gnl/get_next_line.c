/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:51:22 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/19 05:29:17 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int	cheack_read(char *container, char *buff, int size)
{
	if (size < 0)
	{
		free(container);
		free(buff);
		return (0);
	}
	return (1);
}

char	*ft_after_first_nl(char *container)
{
	int		count;
	int		i;
	char	*new_container;
	int		rest_size;

	count = 0;
	i = 0;
	while (container[count] && container[count] != '\n')
		count++;
	if (!container[count])
	{
		free(container);
		return (NULL);
	}
	rest_size = ft_strlen(container) + 1 - count;
	new_container = ft_calloc(rest_size, sizeof(char));
	count++;
	while (container[count])
		new_container[i++] = container[count++];
	free(container);
	return (new_container);
}

char	*ft_get_line(char *container)
{
	char	*line;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (container[i] == '\0')
		return (NULL);
	while (container[count] && container[count] != '\n')
		count++;
	line = ft_calloc(count + 2, sizeof(char));
	while (i <= count)
	{
		line[i] = container[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *container)
{
	char	*buff;
	int		size;
	char	*tmp;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	size = read(fd, buff, BUFFER_SIZE);
	if (cheack_read(container, buff, size) == 0)
		return (NULL);
	while (size > 0)
	{
		buff[size] = '\0';
		tmp = ft_strjoin(container, buff);
		free(container);
		container = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
		size = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (container);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*line;

	if ((fd < 0 || fd > OPEN_MAX) || (BUFFER_SIZE <= 0))
		return (NULL);
	container = ft_read(fd, container);
	if (!container)
		return (NULL);
	line = ft_get_line(container);
	container = ft_after_first_nl(container);
	return (line);
}
