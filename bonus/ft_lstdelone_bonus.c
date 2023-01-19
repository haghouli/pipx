/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:06:32 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/15 13:37:01 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipx.h"

void	ft_lstdelone(t_list *lst, void (*del)(char*))
{
	if (del == NULL || lst == NULL)
		return ;
	del(lst -> path);
	free(lst);
}
