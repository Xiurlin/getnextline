/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:56:22 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/08 13:04:42 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// EL ERROR ESTÁ AQUÍIIII
/*
char	*ft_readed(int fd, char *readed)
{
	char	*stash;
	int		buf; 

	stash = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!stash)
		return (NULL);
	buf = 1;
	//stash = buf;
	//free (buf);
	while (ft_strchr(stash, '\n') == 0) // Si no encuentra \n en stash
	{
		if (!readed)
			readed = (char *) malloc(BUFFER_SIZE * sizeof(char));
		if (!readed)
			return (NULL);
		buf = read(fd, stash, BUFFER_SIZE);
		readed[buf] = '\0';
		readed = ft_strjoin(readed, stash);
	}
	//readed = stash;
	free (stash);
	return (readed);
}
*/

char	*ft_readed(int fd, char *readed)
{
	char	*stash;
	int		buf; 

	if (!readed)
		readed = ft_calloc(sizeof(char), 1);
    if (!readed)
	    return (NULL);
	stash = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));;
	if (!stash)
		return (NULL);
	buf = 1;
	while (ft_strchr(stash, '\n') == 0 && buf != 0) // Si no encuentra \n en stash
	{
		buf = read(fd, stash, BUFFER_SIZE);
		if (buf < 0)
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

/*
char	*ft_readed(int fd, char *readed)
{
    char    *buff;
    int     rd_bytes;

    buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return (NULL);
    rd_bytes = 1;
    while (!ft_strchr(readed, '\n') && rd_bytes != 0)
    {
        rd_bytes = read(fd, buff, BUFFER_SIZE);
        if (rd_bytes == -1)
        {
            free(buff);
            return (NULL);
        }
        buff[rd_bytes] = '\0';
        readed = ft_strjoin(readed, buff);
    }
    free(buff);
    return (readed);
}*/


char	*get_next_line(int fd)
{
	static char	*readed;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	//printf("readed0:%s\n", readed);
	readed = ft_readed(fd, readed);
	if (!readed)
		return (0);
	//printf("readed1:%s\n", readed);
	line = ft_get_line(readed);
	//printf("readed2:%s\n", line);
	readed = ft_next_line(readed);
	//printf("readed3:%s\n", readed);
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
		//left = ft_strchr(line, '\n');
		//line = ft_strcpy(line, '\n');
		printf("Línea[%d]: %s\n", i, line); //Sobrante: %s\n, left
		free (line);
		i++;
	}
	close(fd);
	return (0);
}
*/