/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:14:59 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/08 17:45:51 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipx.h"

static size_t	count_word(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c && *s)
			s++;
		if (*s == '\0' && *(s - 1) == c)
			break ;
		count++;
	}
	return (count);
}

static void	free_loc(char **s, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(s[i++]);
	free(s);
}

static char	*duplicate(const char *str, int start, int end)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		new_str[i++] = str[start++];
	new_str[i] = '\0';
	return (new_str);
}

static char	**allocation(const char *s, char **splited_list, char c)
{
	size_t	i;
	size_t	j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || s[i] == '\0') && start >= 0)
		{
			splited_list[j] = duplicate(s, start, i);
			if (!splited_list[j])
				free_loc(splited_list, j);
			j++;
			start = -1;
		}
		i++;
	}
	splited_list[j] = 0;
	return (splited_list);
}

char	**ft_split(char const *s, char c)
{
	char	**splited_list;

	if (!s)
		return (0);
	splited_list = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!s || !splited_list)
		return (0);
	splited_list = allocation(s, splited_list, c);
	return (splited_list);
}
