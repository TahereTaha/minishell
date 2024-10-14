/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:56:38 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/14 11:23:25 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include "env.h"
#include "core.h"
#include "prompt.h"

void	exec_prompt(void)
{
	printf("this is the prompt\n");
	run_command("echo test");
	return ;
}
