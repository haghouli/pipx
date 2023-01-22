/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:03:35 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/15 13:37:18 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipx.h"

void	ft_lstclear(t_list **lst, void (*del)(char *))
{
	t_list	*tmp;

	if (del == NULL || lst == NULL)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		del((*lst)->path);
		free(*lst);
		*lst = tmp;
	}
}
