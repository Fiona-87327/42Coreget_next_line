/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 20:14:45 by jiyawang          #+#    #+#             */
/*   Updated: 2025/08/18 16:52:53 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*ft_strdup(char *s1)
{
	char	*dest;
	unsigned int	i;
	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t 	j;
	size_t	s_len;
	char	*subs;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	while (i < len && start < s_len && s[start + i])
		i++;
	subs = (char *)malloc(i + 1);
	if (!subs)
		return (NULL);
	j = 0;
	while (j < i)
	{
		subs[j] = s[start + j];
		j++;
	}
	subs[i] = '\0';
	return (subs);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;
	size_t	i;
	size_t	j;

	if (s1)
		s1_len = ft_strlen(s1);
	if (s2)
		s2_len = ft_strlen(s2);
	result = (char *)malloc(s1_len + s2_len + 1);
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1 && s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (free(s1), result);
}
