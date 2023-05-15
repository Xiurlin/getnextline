/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlprueba.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:56:22 by drestrep          #+#    #+#             */
/*   Updated: 2023/05/15 05:59:01 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*BUFFER SIZE AL PRINCIPIO + 1*/
//char	*get_stash(int fd, char *stash)
char	*get_stash(char *buf)
{
	char	*stash;
	int		i;

	i = 1;
	stash = (char *) malloc(100 * sizeof(char));
	if (!stash)
		return (NULL);
	stash = buf;
	/*
	while(i)
	{
		read(fd, buf, BUFFER_SIZE);
		stash = ft_strjoin(stash, buf);
		if (ft_strchr(stash, '\n') != 0)
			break ;
	}
	*/
	return (stash);
}

char	*get_line(char *buf)
{
	char	*stash;
	char	*line;

	stash = get_stash(buf);
	line = stash;
	return (line);
}

char    *get_rest (static char *rest)
{
    char    *buf;

    while (ft_strchr(get_str, '\n') )
    buf = get_buf(rest);
    
}
char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buf;
	char		*line;

    rest = get_rest(rest);
	//stash = get_stash(buf);
	read(fd, buf, 5); /*BUFFER SIZE AL FINAL*/
	line = get_line(buf);
	line = buf;
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
	fd = open("test01.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	close(fd);
	return (0);
	/*
	while (i < 10)
	{
		line = (char *)malloc(sizeof(*line) * 1);
		line = get_next_line(fd);
		printf("%s\n", line);
		i++;
	}
	*/
}