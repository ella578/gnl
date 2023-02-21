/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:57:14 by ewang             #+#    #+#             */
/*   Updated: 2023/02/01 11:31:59 by ewang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *buff)
{
	size_t	file_len;
	char	*str;

	str = (char *)malloc ((sizeof (char) * BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	file_len = 1;
	while (file_len != 0 && ft_strchr(buff, '\n') == 0)
	{
		file_len = read (fd, str, BUFFER_SIZE);
		if ((int)file_len == -1)
		{
			free (str);
			return (NULL);
		}
	str[file_len] = '\0';
	buff = ft_strjoin(buff, str);
	}
	free (str);
	return (buff);
}

char	*ft_define_line(char *buff)
{
	char	*new;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	new = (char *)malloc (sizeof (char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		new[i] = buff[i];
		i++;
	}
	if (buff[i])
	{
	new[i] = buff[i];
	i++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	char		*new;
	static char	*buff[4096];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff[fd] = ft_read_line(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	new = ft_define_line(buff[fd]);
	buff[fd] = ft_new_buff(buff[fd]);
	return (new);
}
