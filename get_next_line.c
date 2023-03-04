/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:56:22 by drestrep          #+#    #+#             */
/*   Updated: 2023/03/04 17:55:17 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
/*
char	*buffer(fd1)
{
	char	*str;
	read(fd1, str, BUFFER_SIZE);
	while (
}
*/
char	*get_next_line(int fd1)
{
	char	*buf;
	int		aux;

	buf = (char *) calloc(100, sizeof(char));
	aux = read(fd1, buf, 100);
	buf[aux] = '\0';
	return (buf);
}

int	main(void)
{
	char	*str;
	int		fd1;

	fd1 = open("tests/test01.txt", O_RDONLY);
	printf("%s", get_next_line(fd1));
	return (0);
}
