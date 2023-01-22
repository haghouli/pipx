/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:44:31 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/22 14:46:24 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipx.h"

void	free_and_move_on(t_list **head)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *head;
	(*head) = (*head)->next;
	free(tmp->path);
	while (tmp->params[i])
		free(tmp->params[i++]);
	free(tmp);
}

void	pipxx(char *path, t_list *head, int fd2)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		put_error("Error");
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		if (!head->next)
			dup2(fd2, 1);
		close(fd[1]);
		if (execve(path, head->params, NULL) == -1)
			exit(0);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
}

void	read_output(int fd1, char **av)
{
	char	*str;

	while (1)
	{
		write(1, "heredoc> ", 10);
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if (!ft_strcmp(str, ft_strjoin(av[2], "\n")))
			break ;
		write(fd1, str, ft_strlen(str));
		free(str);
	}
}

void	heredoc(int ac, char **av, char **env, t_list **head)
{
	char	*str;
	char	*name;
	int		fd1;
	int		fd2;

	name = "tmp";
	fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	fd1 = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	read_output(fd1, av);
	fill_lst_here_doc(ac, head, av, env);
	close(fd1);
	fd1 = open(name, O_RDONLY, 0777);
	dup2(fd1, 0);
	close(fd1);
	while (*head)
	{
		pipxx((*head)->path, *head, fd2);
		free_and_move_on(head);
	}
	while (wait(NULL) != -1)
		;
	unlink(name);
}

int	main(int ac, char *av[], char *env[])
{
	int		fd1;
	int		fd2;
	t_list	*head;

	head = NULL;
	fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (!ft_strcmp("here_doc", av[1]))
		heredoc(ac, av, env, &head);
	else
	{
		fill_lst(ac, &head, av, env);
		fd1 = open(av[1], O_RDONLY);
		if (fd1 < 0)
			return (put_error("Error"), 0);
		dup2(fd1, 0);
		while (head)
		{
			pipxx(head->path, head, fd2);
			free_and_move_on(&head);
		}
		while (wait(NULL) != -1)
			;
	}
	return (0);
}
