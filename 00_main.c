/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:47:13 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/24 13:21:14 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argv, char **argl, char **envp)
{
	t_cmnd_line	*args;
	int			fd[2];
	int			id;

	if (!envp)
		return (1);
	args = ft_arg_check(argv, argl, envp);
	if (!args)
		return (1);
	if (pipe(fd) == -1)
	{
		ft_free_struct(args, 4);
		return (-1);
	}
	id = fork();
	if (id == 0)
		child_process(fd, args, envp);
	else
	{
		waitpid(id, NULL, 0);
		parent_process(fd, args, envp);
		if (args)
			ft_free_struct(args, 8);
	}	
}
