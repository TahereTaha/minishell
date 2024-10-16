/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:56:38 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/16 09:18:47 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include "env.h"
#include "core.h"
#include "prompt.h"
#include "libft.h"

void	exec_prompt(void)
{
	printf("this is the prompt\n");
	run_command(ft_strdup("echo -n test"));
	run_command(ft_strdup("export a=b"));
	run_command(ft_strdup("echo   $aash zsh nushell"));
	return ;
}
