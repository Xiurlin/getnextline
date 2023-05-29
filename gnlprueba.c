/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlprueba.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:56:22 by drestrep          #+#    #+#             */
/*   Updated: 2023/05/29 05:47:44 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_buffer(int fd, char *buf)
{
	char	*stash;
	
	read(fd, buf, 2); // Tamaño del búfer al finalizar
	stash = get_stash(fd, buf);
	return (stash);
}

char	*get_stash(int fd, char *buf)
{
	char	*stash;

	stash = (char *)malloc(100 * sizeof(char));
	if (!stash)
		return (NULL);
	stash = ft_strjoin(stash, buf);
	if (ft_strchr(stash, '\n') != 0)
		return (stash);
	else
		buf = get_buffer(fd, buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;

	buf = (char *)malloc(sizeof(char) * 2); // Tamaño del búfer al principio + 1
	line = get_buffer(fd, buf);
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test01.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	close(fd);
	return (0);
}