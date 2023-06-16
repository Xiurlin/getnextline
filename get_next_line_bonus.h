/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:06:31 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/16 13:02:49 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_readed(int fd, char *readed);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *readed, char *stash);
char	*ft_get_line(char *left_str);
char	*ft_next_line(char *readed);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(const char *str);

#endif
