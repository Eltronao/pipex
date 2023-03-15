/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:47:13 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/15 20:33:38 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argv, char **argl, char **envp)
{
	t_cmnd_line	*args;
	int			fd[2];
	int			id;

	args = ft_arg_check(argv, argl, envp);
	if (args)
		print_args(args->cmnds);
	if (pipe(fd) == -1)
	{
		ft_free_struct(args, 4);
		return (-1);
	}
	printf("A\n");
	id = fork();
	if (id == 0)
	{
	 	printf("B\n");
		child_process(fd, args, envp);
	}
	else
	{
		printf("C\n");
		waitpid(id, NULL, 0);
		printf("D\n");
		parent_process(fd, args, envp);
		if (args)
			ft_free_struct(args, 8);
	}	
}
