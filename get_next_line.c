/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:56:22 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/06 04:21:29 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// EL ERROR ESTÁ AQUÍIIII

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

/*
char	*ft_readed(int fd, char *left_str)
{
    char    *buff;
    int     rd_bytes;

    buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return (NULL);
    rd_bytes = 1;
    while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
    {
        rd_bytes = read(fd, buff, BUFFER_SIZE);
        if (rd_bytes == -1)
        {
            free(buff);
            return (NULL);
        }
        buff[rd_bytes] = '\0';
        left_str = ft_strjoin(left_str, buff);
    }
    free(buff);
    return (left_str);
}*/

char	*get_next_line(int fd)
{
	static char	*readed;
	char		*line;
	
	if (!fd || BUFFER_SIZE <= 0)
		return (0);
	//line = buf;
	printf("readed0:%s\n", readed);
	readed = ft_readed(fd, readed);
	printf("readed1:%s\n", readed);
	//line = ft_strcpy(readed, '\n');
	line = ft_get_line(readed);
	printf("readed2:%s\n", line);
	readed = ft_next_line(readed);
	printf("readed3:%s\n", readed);
	return (line);
}


int	main(void)
{
	char	*line;
	//char	*left;
	int		fd;
	int		i;

	i = 1;
	fd = open("test01.txt", O_RDONLY);
	while (i < 3)
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