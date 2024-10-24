/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:21:53 by gasroman          #+#    #+#             */
/*   Updated: 2024/10/23 19:48:31 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "./builtins.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	if (av[1] && av[1][0] == '-' && av[1][1] == 'n')
	{
		i = 1;
		while (av[1][i] && av[1][i] == 'n')
			i++;
		if (av[1][i] == '\0')
			flag = 1;
	}
	if (!av[1])
		return (printf("\n"));
	j = 0 + flag;
	while (av[++j])
	{
		printf("%s", av[j]);
		if (av[j + 1])
			printf(" ");
	}
	if (flag == 0)
		printf("\n");
	return (0);
}
