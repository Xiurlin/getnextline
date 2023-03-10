/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:56:22 by drestrep          #+#    #+#             */
/*   Updated: 2023/03/10 07:32:20 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_bufer(int fd, char *buf)
{
	b
}

char	*get_line(char	*buf)
{
	char	*stash;
	char	*line;


	aux = ft_strrchr(buf, '\n');

	return (line);
}

char	*get_next_line(int fd1)
{
	static char	*buf;
	char		*line;
	//int		aux;

	buf = get_buffer(fd, buf);
	buf = (char *) calloc(100, sizeof(char));
	if (!buf)
		return (NULL);
	/*aux = */read(fd1, buf, BUFFER_SIZE);
	//buf[aux] = '\0';
	line = get_line(buf),
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("tests/test01.txt", O_RDONLY);
	while (i < 10)
	{
		line = (char *)malloc(sizeof(*line) * 1);
		line = get_next_line(fd);
		printf("%s\n", line);
		i++;
	}
}
