/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:34:32 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/21 14:30:53 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPX_H
# define PIPX_H
# include "./bonus/gnl/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*path;
	char			**params;
	struct s_list	*next;
}					t_list;

char				**ft_split(char const *s, char c);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
size_t				ft_strlen(const char *s);
char				*get_true_path(char **env, char *av);
void				pipex(int fd1, int fd2, char **av, char **env);
void				put_error(char *str);

/****************** Bonus **********************/
void				fill_lst(int ac, t_list **head, char **av, char **env);
void				fill_lst_here_doc(int ac, t_list **head, char **av,
						char **env);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(char *));
void				ft_lstdelone(t_list *lst, void (*del)(char *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew_bonus(char *path, char **params);
int					ft_lstsize(t_list *lst);
int					ft_strcmp(char *s1, char *s2);

#endif