/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:06:31 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/05 02:18:50 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*get_buffer(int fd, char *buf);
char	*get_stash(int fd, char *buf);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strcpy(char *str, char c);
char	*ft_next_line(char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(const char *str);

#endif
