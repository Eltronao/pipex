/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:47:22 by lagonzal          #+#    #+#             */
/*   Updated: 2023/02/06 20:46:43 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"



typedef struct s_cmnd_line{
    int		fd_in;
	int		fd_out;
	char	***cmnds;
	char	**path;
}	t_cmnd_line;

t_cmnd_line	*ft_arg_check(int argv, char **argl, char **envp);


void		*ft_free_struct(t_cmnd_line *cmnds, int e_type);

#endif