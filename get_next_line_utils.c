/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelberka <aelberka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:38:32 by aelberka          #+#    #+#             */
/*   Updated: 2026/11/21 21:26:52 by aelberka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*m;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	m = malloc((len + 1) * sizeof(char));
	if (!m)
		return (NULL);
	while (s[i])
	{
		m[i] = s[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	len;
	size_t	j;
	char	*m;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	m = malloc(len + 1);
	if (!m)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		m[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		m[i++] = s2[j++];
	m[i] = '\0';
	return (m);
}
