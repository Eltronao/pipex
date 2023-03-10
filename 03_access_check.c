/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_access_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:26:03 by lagonzal          #+#    #+#             */
/*   Updated: 2023/02/07 12:26:03 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pathfinder(char ***aux_c, char **paths);

int	ft_check_access(t_cmnd_line **args)
{
	char	***aux_c;
	int		i;

	aux_c = args[0]->cmnds;
	i = -1;
	while (aux_c[++i])
	{
		if (ft_pathfinder(&aux_c[i], args[0]->path) == -1)
			return (-1);
	}
	return (0);
}

int	ft_pathfinder(char ***aux_c, char **paths)
{
	char	*full_path;
	int		err;
	int		j;

	err = -1;
	j = -1;
	while (paths[++j] && err != 0)
	{
		full_path = ft_strjoin(paths[j], aux_c[0][0]);
		err = access(full_path, F_OK);
		if (err == 0)
		{
			free(aux_c[0][0]);
			aux_c[0][0] = full_path;
		}
		else
			free(full_path);
	}
	if (err == -1)
		return (-1);
	else
		return (0);
}
