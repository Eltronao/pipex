/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_print_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:03:32 by lagonzal          #+#    #+#             */
/*   Updated: 2023/03/15 18:03:32 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void print_args(char ***args)
{
	int	m;
	int	n;

	m = -1;
	while (args[++m])
	{
		printf("%d: ", m + 1);
		n = -1;
		while (args[m][++n])
			printf("%s ", args[m][n]);
		printf("\n");
	}
}