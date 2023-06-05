/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:26:28 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/05 02:17:52 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (0);
	ptr = malloc(count * size);
	if (ptr == 0)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char    *ft_strcpy(char *str, char c)
{
    char    *newstr;
    int     i;

    i = 0;
    newstr = (char *) malloc(100 * sizeof(char));
	if (!newstr)
		return (0);
    while (str[i] != c)
    {
        newstr[i] = str[i];
        i++;
	}
	return (newstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s3 = (char *)malloc ((ft_strlen
				((char *)s1) + ft_strlen((char *)s2) + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	s3[ft_strlen((char *)s1) + ft_strlen((char *)s2)] = '\0';
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	return (s3);
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

char	*ft_strchr(const char *s, int c)
{
	int	i;
	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	if (c == '\0' && s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_next_line(char *str)
{
	int i;
	int j;
	char	*next_line;
	
	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
        i++;
	next_line = (char *) malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!next_line)
		return (NULL);
	i++;
	while (str[i])
		next_line[j++] = str[i++];
	free (str);
	next_line[j] = '\0';
	return (next_line);
}
/* LA IDEA EN ESTE TROZO ES HACERLO CON UN PUNTERO DE MODO QUE (*i)++
SEA IGUAL A LO QUE SOBRA PA LA SIGUIENTE LÍNEA
char	*ft_next_line(char *str)
{
	int i;
	int j;
	char	*next_line;
	
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
        i++;
	next_line = (char *) malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!next_line)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		next_line[j++] = str[i++];
	free (str);
	next_line[j] = '\0';
	return (next_line);
}
*/