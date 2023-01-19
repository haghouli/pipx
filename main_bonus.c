/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:44:31 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/19 18:13:10 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipx.h"

void free_and_move_on(t_list **head)
{
    int     i;
    t_list  *tmp;
    
    i = 0;
    tmp = *head;
    (*head) = (*head) -> next;
    free(tmp->path);
    while(tmp->params[i])
        free(tmp->params[i++]);
    free(tmp);
}

void pipxx(char *path, t_list *head, int outfile)
{
    int fd[2];
    int id;

    pipe(fd);

    id = fork();
    if(id == 0)
    {
        close(fd[0]);
        dup2(fd[1], 1);
        if(!head->next)
            dup2(outfile, 1);
        close(fd[1]);
        execve(path, head->params, NULL);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], 0);
        close(fd[0]);
    }
}

int main(int ac, char *av[], char *env[])
{
    int     fd1;
    int     fd2;
    t_list  *head;

    head = NULL;
    if(!ft_strcmp("here_doc" ,av[1]))
    {
        char    *str;
        char    *name = "tmp";

        fd1 = open(name, O_RDWR| O_CREAT | O_TRUNC, 0777);
        fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
        while(1)
        {
            write(1,"heredoc> ", 10);
            str = get_next_line(0);
            if(str == NULL)
                break;
            if(!ft_strcmp(str, "stop\n"))
                break;
            write(fd1, str, ft_strlen(str));
            free(str);
        }
        fill_lst(ac ,&head, av, env);
        dup2(fd1, 0);
        while(head)
        {
            pipxx(head->path, head, fd2);
            free_and_move_on(&head);
        }
        while(wait(NULL) != -1);
        //unlink(name);
        exit(0);
    }
    // fd1 = open(av[1], O_RDONLY);
	// fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    // if(fd1 < 0)
    //    put_error("Error");
    // fill_lst(ac ,&head, av, env);
    // dup2(fd1, 0);
    // while(head)
    // {
    //     pipxx(head->path, head, fd2);
    //     free_and_move_on(&head);
    // }
    // while(wait(NULL) != -1);
    // return (0);
}