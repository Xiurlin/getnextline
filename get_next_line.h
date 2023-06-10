/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:06:31 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/10 04:20:03 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_readed(int fd, char *readed);
//char	*ft_strchr(const char *s, int c);
char	*ft_strchr(char *s, int c);
//char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_get_line(char *left_str);
char	*ft_next_line(char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(const char *str);

#endif
