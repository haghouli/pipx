/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 09:42:46 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/22 14:56:08 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipx.h"

void	exec_cmd_1(int *fd, int fd1, char **env, char **av)
{
	int		id;
	int		i;
	char	**cmd1_args;

	id = fork();
	cmd1_args = ft_split(av[2], ' ');
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd1, 0);
		dup2(fd[1], 1);
		close(fd[1]);
		if (execve(get_true_path(env, cmd1_args[0]), cmd1_args, NULL) == -1)
			exit(0);
	}
	else
	{
		i = 0;
		while (cmd1_args[i])
			free(cmd1_args[i++]);
		free(cmd1_args);
	}
}

void	exec_cmd_2(int *fd, int fd2, char **env, char **av)
{
	int		id;
	int		i;
	char	**cmd2_args;

	cmd2_args = ft_split(av[3], ' ');
	id = fork();
	if (id == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(fd2, 1);
		close(fd[0]);
		if (execve(get_true_path(env, cmd2_args[0]), cmd2_args, NULL) == -1)
			exit(0);
	}
	else
	{
		i = 0;
		while (cmd2_args[i])
			free(cmd2_args[i++]);
		free(cmd2_args);
	}
}

void	pipex(int fd1, int fd2, char **av, char **env)
{
	int	id1;
	int	id2;
	int	fd[2];

	if (pipe(fd) == -1)
		put_error("Error");
	exec_cmd_1(fd, fd1, env, av);
	exec_cmd_2(fd, fd2, env, av);
	close(fd[0]);
	close(fd[1]);
	while (wait(NULL) != -1)
		;
}
