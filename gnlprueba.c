/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlprueba.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:56:22 by drestrep          #+#    #+#             */
/*   Updated: 2023/05/31 08:55:07 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*line;
	char	buf[2];
	char	*stash;
	int		stash_size;
	int		read_size;

	line = NULL;
	stash = NULL;
	stash_size = 0;
	while ((read_size = read(fd, buf, 1)) > 0)
	{
		if (buf[0] == '\n')
		{
			line = ft_strjoin(stash, line);
			free(stash);
			stash = NULL;
			stash_size = 0;
			break;
		}
		stash = ft_strjoin(stash, buf);
		stash_size++;
	}
	if (read_size == 0 && stash != NULL)
	{
		line = ft_strjoin(stash, line);
		free(stash);
		stash = NULL;
	}
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