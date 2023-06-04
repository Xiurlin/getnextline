/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlprueba.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:56:22 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/04 18:58:55 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*BUFFER SIZE AL PRINCIPIO + 1*/
/*
char	*get_stash(int fd, char *buf)
{
	char	*stash;
	
	stash = (char *) malloc(100 * sizeof(char));
	if (!stash)
		return (NULL);
	read(fd, buf, 5); //BUFFER SIZE AL FINAL
	stash = get_line(fd, buf);
	return (stash);
}

char	*get_line(int fd, char *buf)
{
	char	*stash;
	int		i;

	i = 1;
	stash = ft_strjoin(stash, buf);
	if (ft_strchr(stash, '\n') != 0)
		return (stash);
	else
		buf = get_stash(fd, buf);*/
	/*
	while(i)
	{
		read(fd, buf, BUFFER_SIZE);
		stash = ft_strjoin(stash, buf);
		if (ft_strchr(stash, '\n') != 0)
			break ;
	}
	*/
	/*return (stash);
	return (0);
}*/

char	*prueba(int fd, char *buf)
{
	char	*stash;
	//char	*line;
	//char	*readed; 

	stash = (char *) malloc(100 * sizeof(char));
	if (!stash)
		return (NULL);
	while (ft_strchr(stash, '\n') == 0) // Si no encuentra \n en stash
	{
		buf = (char *) malloc(BUFFER_SIZE * sizeof(char)); // 100 se sustituye por BUFFER_SIZE
		if (!buf)
			return (NULL);
		read(fd, buf, BUFFER_SIZE); // Último parámetro BUFFER_SIZE
		stash = ft_strjoin(stash, buf);
		free (buf);
	}
	//readed = stash;
	return (stash);
	/*
	if (ft_strchr(stash, '\n') != 0) // Si encuentra \n en stash
	{
		line = ft_strcpy(stash, '\n');
		stash = ft_strchr(stash, '\n');
		return (line);
	}
	*/
	return (0);
}

char	*get_next_line(int fd)
{
	if (!fd || BUFFER_SIZE <= 0)
		return (0);
	char		*buf;
	char		*line;

	buf = (char *) malloc(100 * sizeof(char));
	buf = prueba(fd, buf);
	line = buf;
	return (line);
}


int	main(void)
{
	char	*line;
	char	*left;
	int		fd;
	int		i;

	i = 1;
	fd = open("test01.txt", O_RDONLY);
	line = get_next_line(fd);
	left = ft_strchr(line, '\n');
	line = ft_strcpy(line, '\n');
	printf("Línea: %s\nSobrante: %s\n", line, left);
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



/*
int main(void)
{
    char    *line;
    int     i;
    int     fd1;
    //int       fd2;
    //int       fd3;
    fd1 = open("tests/test.txt", O_RDONLY);
    //fd2 = open("tests/test2.txt", O_RDONLY);
    //fd3 = open("tests/test3.txt", O_RDONLY);
    i = 1;
    while (i < 2)
    {
        line = get_next_line(fd1);
        printf("line [%02d]: %s", i, line);
        free(line);
		*/
		/*
        line = get_next_line(fd2);
        printf("line [%02d]: %s", i, line);
        free(line);
        line = get_next_line(fd3);
        printf("line [%02d]: %s", i, line);
        free(line);
		*/
        /*
		i++;
    }
    close(fd1);
    //close(fd2);
    //close(fd3);
    return (0);
}
*/



// NO FUNCIONA CON BUFFER_SIZE = 32 ?!?!?!?!?!?!?