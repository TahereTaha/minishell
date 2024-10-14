/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:56:38 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/14 08:37:50 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include "env.h"
//#include "core.h"
#include "prompt.h"

void	exec_prompt(void *env)
{
	printf("this is the prompt\n");
	printf("\tthe enviroment recived is %p\n", env);
	//run_command("", env);
	return ;
}
