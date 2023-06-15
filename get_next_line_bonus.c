/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:56:22 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/15 11:22:37 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
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
*/

char    *get_next_line(int fd)
{
    static char *stash[OPEN_MAX];
    char        *line;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    stash[fd] = ft_readed(fd, stash[fd]);
    if (!stash[fd])
        return (NULL);
    line = ft_get_line(stash[fd]);
    stash[fd] = ft_next_line(stash[fd]);
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
