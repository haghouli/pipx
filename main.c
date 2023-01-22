/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 05:51:30 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/18 07:41:20 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipx.h"

int	main(int ac, char *av[], char *env[])
{
	int	fd1;
	int	fd2;

	if (ac != 5)
		return (0);
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd1 < 0)
		return (put_error("Error"), 0);
	pipex(fd1, fd2, av, env);
	return (0);
}
