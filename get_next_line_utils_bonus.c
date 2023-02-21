/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:58:07 by ewang             #+#    #+#             */
/*   Updated: 2023/01/25 10:28:15 by ewang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof (char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	while (s1[j])
		join[i++] = s1[j++];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free (s1);
	return (join);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s) +1;
	while (i--)
	{
		if (*s == (char) c)
			return ((char *)s);
	s++;
	}
	return (0);
}	

char	*ft_new_buff(char *buff)
{
	size_t	len;
	size_t	i;
	char	*tmp;

	len = 0;
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (!buff[i])
	{
		free (buff);
		return (NULL);
	}
	tmp = (char *)malloc (sizeof (char) * (ft_strlen(buff) - i + 1));
	if (!tmp)
		return (NULL);
	i++;
	while (buff[i])
		tmp[len++] = buff[i++];
	tmp[len] = '\0';
	free (buff);
	return (tmp);
}
