/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_parent_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:53:11 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/15 19:53:11 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(int fd[2], t_cmnd_line *args, char **envp)
{
	char	*path;

	dup2(fd[0], 0);
	dup2(args->fd_out, 1);
	close(fd[1]);
	path = ft_pathfinder(args->cmnds[1][0], args->path);
	if (execve(path, args->cmnds[1], envp) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
