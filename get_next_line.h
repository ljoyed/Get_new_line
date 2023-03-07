/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:23:32 by loandrad          #+#    #+#             */
/*   Updated: 2023/03/07 12:12:24 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*append_txt_blk(int fd, char *txt_blk);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *txt_blk, char *buff);
size_t	ft_strlen(char *s);
char	*extract_line(char *txt_blk);
char	*new_txt_blk(char *txt_blk);

#endif