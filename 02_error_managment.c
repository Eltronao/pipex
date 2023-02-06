/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_error_managment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:57:22 by lagonzal          #+#    #+#             */
/*   Updated: 2023/02/06 21:03:46 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_triple_free(void ***ptr);
void	ft_double_free(void **ptr);
void	ft_close_fds(t_cmnd_line *args);

void    *ft_free_struct(t_cmnd_line *args, int e_type)
{
	while (e_type >= 0)
	{
		if (e_type == 0)
			ft_close_fds(args);
		else if (e_type == 1)
			ft_double_free((void **)args->path);
		else if (e_type == 2)
			ft_triple_free((void ***)args->cmnds);
		e_type -= 1;
	}
	return (free(args), NULL);
}

void	ft_close_fds(t_cmnd_line *args)
{
	close(args->fd_in);
	close(args->fd_out);
}

void	ft_double_free(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
        {
            free(ptr[i]);
            i++;
        }
    free(ptr);
}

void	ft_triple_free(void ***ptr)
{
    int     i;

    i = 0;
    while (ptr[i])
    {
        ft_double_free(ptr[i]);
        i++;
    }
    free(ptr);
}
