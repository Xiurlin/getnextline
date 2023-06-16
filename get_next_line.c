/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:56:22 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/16 11:40:58 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readed(int fd, char *readed)
{
	char	*stash;
	int		buf;

	if (!readed)
		readed = ft_calloc(sizeof(char), 1);
	stash = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	buf = 1;
	while (!ft_strchr(stash, '\n') && buf != 0)
	{
		buf = read(fd, stash, BUFFER_SIZE);
		if (buf == -1)
		{
			free (readed);
			free (stash);
			return (NULL);
		}
		stash[buf] = '\0';
		readed = ft_strjoin(readed, stash);
	}
	free (stash);
	return (readed);
}

char	*ft_get_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*readed;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	readed = ft_readed(fd, readed);
	if (!readed)
		return (0);
	line = ft_get_line(readed);
	readed = ft_next_line(readed);
	return (line);
}
/*
int	main(void)
{
	char	*line;
	//char	*left;
	int		fd;
	int		i;

	i = 1;
	fd = open("test00.txt", O_RDONLY);

	while (i < 5)
	{
		line = get_next_line(fd);
		printf("Línea[%d]: %s\n", i, line);
		free (line);
		i++;
	}
	close(fd);
	return (0);
}
*/