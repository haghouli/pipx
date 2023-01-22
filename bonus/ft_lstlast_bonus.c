/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:55:06 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/15 13:35:23 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipx.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*t;

	if (lst == NULL)
		return (NULL);
	t = lst;
	while (t->next != NULL)
		t = t->next;
	return (t);
}
