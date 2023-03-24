/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:47:22 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/24 13:23:04 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_cmnd_line
{
	int		fd_in;
	int		fd_out;
	char	***cmnds;
	char	**path;
}	t_cmnd_line;

t_cmnd_line	*ft_arg_check(int argv, char **argl, char **envp);
void		*ft_free_struct(t_cmnd_line *cmnds, int e_type);
char		*ft_pathfinder(char *aux_c, char **paths);
void		child_process(int fd[2], t_cmnd_line *args, char **envp);
void		parent_process(int fd[2], t_cmnd_line *args, char **envp);

/*=================UTILS====================================*/

void		print_args(char ***args);
#endif