/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:43:19 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/09 05:39:38 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipx.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((haystack == 0) && (len == 0))
		return (0);
	if ((*needle == 0))
		return ((char *)haystack);
	while (*haystack && i < len)
	{
		while (haystack[j] == needle[j] && (i + j) < len && haystack[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack);
		haystack++;
		i++;
		j = 0;
	}
	return (0);
}
