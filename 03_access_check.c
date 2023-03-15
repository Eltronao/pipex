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

char	*ft_pathfinder(char *aux_c, char **paths);

char	*ft_pathfinder(char *aux_c, char **paths)
{
	char	*full_path;
	int		err;
	int		j;

	err = -1;
	j = -1;
	while (paths[++j] && err != 0)
	{
		full_path = ft_strjoin(paths[j], aux_c);
		err = access(full_path, F_OK);
		if (err != 0)
			free(full_path);
	}
	if (err == -1)
		return (NULL);
	else
		return (full_path);
}

/*/	if (ft_check_access(&args) == -1)
	{
		return (ft_free_struct(args, 3));
	}
*/