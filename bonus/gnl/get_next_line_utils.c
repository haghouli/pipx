/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:51:41 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/19 05:28:35 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipx.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	full_size;
	size_t	i;
	void	*str;

	i = 0;
	full_size = count * size;
	if (full_size > SIZE_MAX)
		return (NULL);
	str = malloc(full_size);
	if (!str)
		return (NULL);
	while (i < full_size)
		((char *)str)[i++] = 0;
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_strchr(const char *s, int c)
{
	if ((char )c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if ((char)*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*dup;

	i = 0;
	size = ft_strlen(s1);
	dup = (char *)malloc((size + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < size)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*joined_str;
	int		full_size;

	if (s1 == 0 && s2 == 0)
		return (NULL);
	if (s1 == 0)
		return (ft_strdup(s2));
	if (s2 == 0)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	full_size = (ft_strlen(s1) + ft_strlen(s2));
	joined_str = (char *)malloc((full_size + 1) * sizeof(char));
	if (!joined_str)
		return (0);
	while (i < full_size)
	{
		while (s1[j])
			joined_str[i++] = s1[j++];
		j = 0;
		while (s2[j])
			joined_str[i++] = s2[j++];
	}
	joined_str[i] = '\0';
	return (joined_str);
}
