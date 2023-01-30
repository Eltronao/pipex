/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_arg_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:48:06 by lagonzal          #+#    #+#             */
/*   Updated: 2023/01/30 18:56:47 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



t_cmnd_line	*ft_open_fds(int argv, char **argl);
char	***ft_get_cmnds(int argv, char **argl);
char	**ft_get_path(char **envp);


t_comnd_line    *ft_arg_check(int argv, char **argl, char **envp)
{
	s_cmnd_line	*args;
	int			i;
	int			j;
	char		**path;

	if (argv != 5)
	{	
		ft_printf("Error in input quantity.\n Try: ./pipex <infile> <comand1> <comand2> <outfile>\n");
		return(NULL);
	}
	args = ft_open_fds(argv, argl);
	if (!args)
		return (NULL);
	path = ft_get_path(envp);
	if (!path)
		(free(args), NULL);
	args->cmnds = ft_get_cmnds(argv, argl);
	if (!(args->comnds))
		return (free(args), NULL);
	ft_check_access()
}

t_cmnd_line	*ft_open_fds(int argv, char **argl)
{
	t_cmnd_line	*args;

	args = malloc(sizeof(t_cmnd_line));
	args->fd_in = open(argl[0], O_RDONLY);
	if (args->fd_in < 0)
		return (free(args), NULL);
	args->fd_out = open(argl[argv - 1], O_WRONLY);
	if (args->fd_out < 0)
		return (free(args), NULL);
	return (args);
	
}

char	***ft_get_cmnds(int argv, char **argl)
{
	char	***cmnds;
	int		i;
	int		j;

	cmnds = malloc((argv - 2) * sizeof(char **));
	if (!cmnds)
		return (NULL);
	cmnds[argv - 3] = NULL;
	i = 0;
	j = 1;
	while (i < argv - 3)
	{
		cmnds[i] = ft_split(argl[j], ' ');
		if (!cmnds[i])
			return (ft_double_free(cmnds));
		i++;
		j++;
	}

}

char	**ft_get_path(char **envp)
{
	char	**path;
	char	*env_path;
	int		i;

	i = 0;
	env_path = (ft_strnchr(env[0], "PATH", 4));
	while(env_path == NULL)
		env_path = (ft_strnchr(env[++i], "PATH", 4));
	if (!(ft_strnchr(envp)))
		return (NULL);
	//printf("%s\n", envp[i]);
	path = ft_split(&env_path[5], ':');
	return (path);
}