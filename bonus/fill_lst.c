/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:21:50 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/15 14:27:51 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipx.h"

void    fill_lst(int ac,t_list **head, char **av, char **env)
{
    int i;
    char **params;
    char *path;

    i = 2;
    while(i < ac - 1)
    {
        params = ft_split(av[i], ' ');
        path = get_true_path(env, params[0]);
        ft_lstadd_back(head, ft_lstnew_bonus(path, params));
        i++;
    }
}