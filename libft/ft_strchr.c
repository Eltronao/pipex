/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:59:20 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/05 14:21:10 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	n;

	n = 0;
	while (s[n] != (char)c && s[n] != '\0')
		n++;
	if (s[n] == (char)c)
		return ((char *)&s[n]);
	else
		return (NULL);
}

/*int	main(void)
{
	const char	s[] = "teste";
	int	c = '.';
	printf("%s\n", s);
	printf("%s\n", ft_strchr(s, 't' + 256));
	return (0);	
}*/
