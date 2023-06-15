/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:26:28 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/15 11:11:07 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (0);
	ptr = malloc(count * size);
	if (ptr == 0)
	{
		free (ptr);
		return (NULL);
	}
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *readed, char *stash)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!readed || !stash)
		return (NULL);
	line = malloc(sizeof(char) * ((ft_strlen(readed) + ft_strlen(stash)) + 1));
	if (!line)
		return (NULL);
	while (readed[i])
	{
		line[i] = readed[i];
		i++;
	}
	while (stash[j])
	{
		line[i] = stash[j];
		i++;
		j++;
	}
	line[ft_strlen(readed) + ft_strlen(stash)] = '\0';
	free(readed);
	return (line);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_next_line(char *readed)
{
	char	*nl;
	int		i;
	int		j;

	i = 0;
	while (readed[i] != '\n' && readed[i])
		i++;
	if (!readed[i])
	{
		free(readed);
		return (NULL);
	}
	nl = malloc(sizeof(char) * (ft_strlen(readed) - i + 1));
	if (!nl)
		return (NULL);
	i++;
	j = 0;
	while (readed[i])
		nl[j++] = readed[i++];
	nl [j] = '\0';
	free(readed);
	return (nl);
}
