/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:46:40 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/19 11:10:27 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipx.h"

static char	**get_paths(char **env)
{
	char	**paths;
	int		i;
	char	*tmp;
	char	*str;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			str = env[i];
		i++;
	}
	while (*str != '/')
		str++;
	paths = ft_split(str, ':');
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = tmp;
		i++;
	}
	return (paths);
}

char	*get_true_path(char **env, char *av)
{
	int		i;
	char	*tmp;
	char	*real_path;
	char	**paths;

	i = 0;
	real_path = NULL;
	paths = get_paths(env);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], av);
		if (!access(tmp, F_OK))
			real_path = tmp;
		else
			free(tmp);
		i++;
	}
	if (real_path == NULL)
	{
		ft_printf("Error: command not found %s\n", av);
		exit(1);
	}
	return (real_path);
}
