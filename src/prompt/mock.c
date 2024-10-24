/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:56:38 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/18 08:38:44 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include "env.h"
#include "core.h"
#include "prompt.h"
#include "libft.h"

void	exec_prompt(void)
{
	int	error_value;
	printf("this is the prompt\n");
	error_value = run_command(ft_strdup("echo -n test"));
	if (error_value)
	{
		printf("========\nerror\n========\n");
		exit(42);
	}
	//run_command(ft_strdup("export a=b"));
	//run_command(ft_strdup("echo   $aash zsh nushell"));
	return ;
}
