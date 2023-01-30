/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:47:13 by lagonzal          #+#    #+#             */
/*   Updated: 2023/01/30 16:00:18 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argv, char **argl, char **envp)
{
	t_comnd_line	*arg;

	arg = ft_arg_check(argv, argl, envp);
}