/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_child_proccess.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:11:05 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/15 19:11:05 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_child_proccess.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:44:27 by lagonzal          #+#    #+#             */
/*   Updated: 2023/02/07 16:44:27 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int fd[2], t_cmnd_line *args, char **envp)
{
	char	*path;

	dup2(fd[1], 1);
	dup2(args->fd_in, 0);
	close(fd[0]);
	path = ft_pathfinder(args->cmnds[0][0], args->path);
	if (!path)
		exit(EXIT_FAILURE);
	if (execve(path, args->cmnds[0], envp) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
