/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:15:20 by loandrad          #+#    #+#             */
/*   Updated: 2023/03/07 12:13:25 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *txt_blk, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!txt_blk)
	{
		txt_blk = (char *)malloc(1 * sizeof(char));
		txt_blk[0] = '\0';
	}
	if (!txt_blk || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(txt_blk) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (txt_blk)
		while (txt_blk[++i] != '\0')
			str[i] = txt_blk[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(txt_blk) + ft_strlen(buff)] = '\0';
	free(txt_blk);
	return (str);
}

char	*extract_line(char *txt_blk)
{
	int		i;
	char	*str;

	i = 0;
	if (!txt_blk[i])
		return (NULL);
	while (txt_blk[i] && txt_blk[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (txt_blk[i] && txt_blk[i] != '\n')
	{
		str[i] = txt_blk[i];
		i++;
	}
	if (txt_blk[i] == '\n')
	{
		str[i] = txt_blk[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_txt_blk(char *txt_blk)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (txt_blk[i] && txt_blk[i] != '\n')
		i++;
	if (!txt_blk[i])
	{
		free(txt_blk);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(txt_blk) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (txt_blk[i])
		str[j++] = txt_blk[i++];
	str[j] = '\0';
	free(txt_blk);
	return (str);
}

char	*append_txt_blk(int fd, char *txt_blk)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(txt_blk, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		txt_blk = ft_strjoin(txt_blk, buff);
	}
	free(buff);
	return (txt_blk);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*txt_blk;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	txt_blk = append_txt_blk(fd, txt_blk);
	if (!txt_blk)
		return (NULL);
	line = extract_line(txt_blk);
	txt_blk = new_txt_blk(txt_blk);
	return (line);
}
