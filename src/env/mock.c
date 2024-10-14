/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:03:53 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/10 10:22:30 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//	function prototipes
#include "env.h"

void	*set_env(char **env)
{
	(void)env;
	printf("this is the mock of the set_env function\n");
	return ("");
}

void	free_env(void *env)
{
	(void)env;
	printf("this is the mock of the frre_env function\n");
}
