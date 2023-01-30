/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:47:22 by lagonzal          #+#    #+#             */
/*   Updated: 2023/01/30 17:33:35 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
//# include <libft/libft.h>


typedef struct s_cmnd_line{
    int		fd_in;
	int		fd_out;
	char	***cmnds;
	char	**path;
}	t_comnd_line;

#endif