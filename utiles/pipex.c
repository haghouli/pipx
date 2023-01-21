/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 09:42:46 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/21 08:57:33 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipx.h"

void	pipex(int fd1, int fd2, char **av, char **env)
{
	int		id1;
	int		id2;
	int		fd[2];
	char	**cmd1_args;
	char	**cmd2_args;

	cmd1_args = ft_split(av[2], ' ');
	cmd2_args = ft_split(av[3], ' ');
	if(pipe(fd) == -1)
		put_error("Error");
	id1 = fork();
	if(id1 == 0)
	{
		close(fd[0]);
		dup2(fd1, 0);
		dup2(fd[1], 1);
		close(fd[1]);
		execve(get_true_path(env, cmd1_args[0]), cmd1_args, NULL);
	}
	id2 = fork();
	if(id2 == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(fd2, 1);
		close(fd[0]);
		execve(get_true_path(env, cmd2_args[0]), cmd2_args, NULL);
	}
	close(fd[0]);
	close(fd[1]);
	while(wait(NULL) != -1);
}
