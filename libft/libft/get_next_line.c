/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:07:09 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/20 18:35:39 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoiner(char *buffer, char *str)
{
	size_t	size;
	char	*res;
	char	*response;
	char	*buf_free;

	if (!buffer)
		return (ft_strdup(str));
	if (!buffer && !ft_strlen(str))
		return (NULL);
	size = ft_strlen(buffer) + ft_strlen(str);
	res = (char *)malloc(sizeof (char) * (size + 1));
	if (!res)
		return (free(buffer), NULL);
	buf_free = buffer;
	response = res;
	while (*buffer)
		*res++ = *buffer++;
	while (*str)
		*res++ = *str++;
	*res = '\0';
	return (free(buf_free), response);
}

static char	*ft_get_rough_line(char *buffer, int fd)
{
	char	*tempo;
	int		size;

	tempo = (char *)malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!tempo)
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}
	size = 1;
	while (size > 0)
	{
		size = read(fd, tempo, BUFFER_SIZE);
		if (size < 0)
			return (free(tempo), free(buffer), NULL);
		tempo[size] = '\0';
		buffer = ft_strjoiner(buffer, tempo);
		if (!buffer || ft_strchr(buffer, '\n'))
			break ;
	}
	free(tempo);
	return (buffer);
}

static char	*ft_sep_n_trim(char *str)
{
	size_t	len;
	char	*res;
	char	*buff;

	len = 0;
	if (!ft_strlen(str))
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	res = (char *)malloc(sizeof (char) * (len + 1));
	if (!res)
		return (NULL);
	buff = res;
	while (*str && *str != '\n')
		*res++ = *str++;
	if (*str == '\n')
		*res++ = *str;
	*res = '\0';
	return (buff);
}

static char	*ft_get_rest(char *str, size_t offset)
{
	char	*res;
	char	*buf_res;
	char	*buf_str;

	if (!offset)
		return (free(str), NULL);
	buf_str = str;
	while (offset--)
		str++;
	res = (char *)malloc(sizeof (char) * (ft_strlen(str) + 1));
	if (!res)
		return (free(str), NULL);
	buf_res = res;
	while (*str)
		*buf_res++ = *str++;
	*buf_res = '\0';
	return (free(buf_str), res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD_NUMBER];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer[fd] && !ft_strchr(buffer[fd], '\n'))
		buffer[fd] = ft_get_rough_line(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	str = ft_sep_n_trim(buffer[fd]);
	if (str)
		buffer[fd] = ft_get_rest(buffer[fd], ft_strlen(str));
	else
		buffer[fd] = ft_get_rest(buffer[fd], 0);
	return (str);
}
